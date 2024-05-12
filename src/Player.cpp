#include "Player.h"

Player::Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant) :
	HitboxEntity(renderWindowConstant),
	m_speed(5),
	m_fire(false)
{
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
	m_hitbox.setSize(Vector2f(28, 12));
	m_sprite.setScale(0.8, 0.8);
	m_sprite.setPosition(spawnPosition);
	
	m_animations.push_back(Animation(ASSETS_PATH + "spacecraft_sheet.png", 4, 0.1f));
}

void Player::HandleInputs()
{	
	m_mousePosition = Vector2f(m_renderWindowConstant->mapPixelToCoords(Mouse::getPosition(*m_renderWindowConstant)));
	if (Mouse::isButtonPressed(Mouse::Left) && m_fire == false) m_fire = true;
	else m_fire = false;
}

void Player::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	if (totalTimeElapsed.asSeconds() - m_firedTimeStamp.asSeconds() >= 0.2 && m_fire) 
	{
		m_horizontalProjectiles.push_back(
			new HorizontalProjectile(
				Vector2f(m_sprite.getPosition()),
				500, *m_renderWindowConstant,
				totalTimeElapsed, Direction::RIGHT));
		m_firedTimeStamp = totalTimeElapsed;
	}
	
	//
	Vector2f viewSize = m_renderWindowConstant->getView().getSize();
	Vector2f lerp = vectorLerp(m_sprite.getPosition(), m_mousePosition, m_speed * deltaTime.asSeconds());
	m_sprite.setPosition(std::clamp(lerp.x, 0.0f, viewSize.x), std::clamp(lerp.y, 0.0f, viewSize.y));
	m_hitbox.setPosition(m_sprite.getPosition());

	// update projectiles
	for (auto& projectile : m_horizontalProjectiles) projectile->Update(deltaTime, totalTimeElapsed);

	//update animations
	for (auto& animation : m_animations) animation.Update(deltaTime, m_sprite); // this doesn't make any sense this would just play all the animations !!!
}

void Player::HandleEvents(const Event& event)
{
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	if(m_hitboxVisible) target.draw(m_hitbox);
	
	for (HorizontalProjectile* projectile : m_horizontalProjectiles) projectile->draw(target, states);
}

void Player::DespawnProjectiles()
{
	
	std::erase_if(m_horizontalProjectiles, [](HorizontalProjectile* x) 
		{
			x->MarkedForDespawn();
			if (x->MarkedForDespawn())
			{
				delete x;
				return true;
			}
			return false;
		});
}

std::vector<Projectile*> Player::GetProjectiles()
{
	vector<Projectile*> projectiles;
	for (Projectile* projectile : m_horizontalProjectiles)
		projectiles.push_back(projectile);

	return projectiles;
}

void Player::SpawnProjectile()
{
	// move spawn logic here !!!
}
