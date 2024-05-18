#include "Player.h"

Player::Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant, EventManager& eventManager) :
	m_eventManager(eventManager),
	HitboxEntity(renderWindowConstant),
	Trackable(m_hitbox),
	m_fire(false),
	m_grace(false),
	m_speed(5),
	m_lives(3),
	m_gracePeriod(seconds(2))
{
	// setting up the player (hardcoded values subject to change)
	m_sprite.setScale(0.8, 0.8);
	m_sprite.setPosition(spawnPosition);
	
	m_animations.insert({"idle", Animation(ASSETS_PATH + "spacecraft_sheet.png", 4, 0.1f)});
	Vector2f frameSize = m_animations["idle"].GetFrameSize();
	float reduce = 0.5;
	m_hitbox.setSize(Vector2f(frameSize.x * reduce, frameSize.y*reduce));
	m_sprite.setOrigin(frameSize.x / 2, frameSize.y / 2);
	m_hitbox.setOrigin(frameSize.x / 2 * reduce, frameSize.y / 2 * reduce);

	m_sounds.insert({ "fire", Sound(AssetManager::GetSoundBuffer(ASSETS_PATH + "laser_gun.wav")) });
	m_sounds.insert({ "damaged", Sound(AssetManager::GetSoundBuffer(ASSETS_PATH + "damaged.wav")) });
	m_sounds["damaged"].setVolume(20);
	m_sounds["fire"].setVolume(20);
}

Player::~Player()
{
	for (HorizontalProjectile* projectile : m_horizontalProjectiles)
		delete projectile;
}

void Player::HandleInputs()
{	
	m_mousePosition = Vector2f(m_renderWindowConstant->mapPixelToCoords(Mouse::getPosition(*m_renderWindowConstant)));
	if (Mouse::isButtonPressed(Mouse::Left) && m_fire == false) m_fire = true;
	else m_fire = false;
}

void Player::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	// player movement
	Vector2f viewSize = m_renderWindowConstant->getView().getSize();
	Vector2f lerp = vectorLerp(m_sprite.getPosition(), m_mousePosition, m_speed * deltaTime.asSeconds());
	m_sprite.setPosition(std::clamp(lerp.x, 0.0f, viewSize.x), std::clamp(lerp.y, 0.0f, viewSize.y));
	m_hitbox.setPosition(m_sprite.getPosition());

	SpawnProjectile(totalTimeElapsed);

	// update projectiles
	for (auto& projectile : m_horizontalProjectiles) 
		projectile->Update(deltaTime, totalTimeElapsed);
	for (auto& projectile : m_homingMissiles)
		projectile->Update(deltaTime, totalTimeElapsed);

	//update animations
	m_animations["idle"].Update(deltaTime, m_sprite);

	// expires grace after alloted period
	RemoveGrace(totalTimeElapsed);

	if (m_grace) 
	{
		m_sprite.setColor(Color(0, 0 ,0 ,100));
	}
	else 
	{
		m_sprite.setColor(Color(255, 255, 255, 255));
	}

	if (m_lives == 0) 
		m_eventManager.MarkPlayerAsDead();
}

void Player::PreDespawn()
{
	for (HomingMissile* homingMissile : m_homingMissiles) 
	{
		homingMissile->PreDespawn();
	}
}

void Player::HandleEvents(const Event& event)
{
	if (m_eventManager.GetPausedStatus()) 
	{
		PauseSounds();
	}
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	if(m_hitboxVisible) target.draw(m_hitbox);
	
	for (HorizontalProjectile* projectile : m_horizontalProjectiles) projectile->draw(target, states);
	for (HomingMissile* projectile : m_homingMissiles) projectile->draw(target, states);


}

void Player::DespawnProjectiles()
{
	
	std::erase_if(m_horizontalProjectiles, [](HorizontalProjectile* projectile) 
		{
			projectile->MarkedForDespawn();
			if (projectile->MarkedForDespawn())
			{
				delete projectile;
				return true;
			}
			return false;
		});
	std::erase_if(m_homingMissiles, [](HomingMissile* missile)
		{
			missile->MarkedForDespawn();
			if (missile->MarkedForDespawn())
			{
				delete missile;
				return true;
			}
			return false;
		});
}

bool Player::UnderGrace() const
{
	return m_grace;
}

float Player::GetLives() const
{
	return m_lives;
}

std::vector<HomingMissile*> Player::GetNonTrackingHomingMissiles()
{
	std::vector<HomingMissile*> nonTrackingHomingMissiles;
	for (HomingMissile* homingMissile : m_homingMissiles) 
	{
		if(!homingMissile->TrackingStatus())
			nonTrackingHomingMissiles.push_back(homingMissile);
	}
	return nonTrackingHomingMissiles;
}

void Player::DecrementLives(const Time totalTimeElapsed)
{
	if (m_lives == 0)
	{
		return;
	}
	else if (totalTimeElapsed - m_damagedTimeStamp >= m_gracePeriod)
	{
		m_lives--;
		m_damagedTimeStamp = totalTimeElapsed;
		m_grace = true;
		m_sounds["damaged"].play();
	}
}

std::vector<Projectile*> Player::GetProjectiles()
{
	vector<Projectile*> projectiles;
	for (Projectile* projectile : m_horizontalProjectiles)
		projectiles.push_back(projectile);

	return projectiles;
}

void Player::RemoveGrace(const Time totalTimeElapsed)
{
	if (totalTimeElapsed - m_damagedTimeStamp >= m_gracePeriod)
		m_grace = false;
}

void Player::SpawnProjectile(const Time totalTimeElapsed)
{
	if (totalTimeElapsed.asSeconds() - m_firedTimeStamp.asSeconds() >= 0.2f && m_fire)
	{
		m_homingMissiles.push_back(new HomingMissile(*this, m_sprite.getPosition(), 200, 200, *m_renderWindowConstant, totalTimeElapsed));
	}
	if (totalTimeElapsed.asSeconds() - m_firedTimeStamp.asSeconds() >= 0.2 && m_fire)
	{
		m_sounds.at("fire").play();
		m_horizontalProjectiles.push_back(
			new HorizontalProjectile(
				Vector2f(m_sprite.getPosition()),
				500, *m_renderWindowConstant,
				totalTimeElapsed, Direction::RIGHT));
		m_firedTimeStamp = totalTimeElapsed;
	}
}
