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
		m_projectiles.push_back(Projectile(Vector2f(m_sprite.getPosition()), 500, *m_renderWindowConstant, totalTimeElapsed));
		m_firedTimeStamp = totalTimeElapsed;
	}
	
	Vector2f viewSizeVec = m_renderWindowConstant->getView().getSize();
	Vector2f vec = VectorLerp(m_sprite.getPosition(), m_mousePosition, m_speed * deltaTime.asSeconds());
	if(!(vec.x >= viewSizeVec.x || vec.y >= viewSizeVec.y || vec.x <= 0|| vec.y <= 0)) // doesnt work very well !!!
		m_sprite.setPosition(vec);
	
	//consoleVector2f(m_sprite.getPosition());
	m_hitbox.setPosition(vec.x, vec.y);

	// update projectiles
	for (auto& projectile : m_projectiles) projectile.Update(deltaTime, totalTimeElapsed);

	//update animations
	for (auto& animation : m_animations) animation.Update(deltaTime, m_sprite);

	
}

void Player::HandleEvents(const Event& event)
{
	//if (event.key.code == Keyboard::Space && event.KeyReleased == Event::KeyReleased)
		
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	if(m_hitboxVisible) target.draw(m_hitbox);
	for (auto& projectile : m_projectiles) projectile.draw(target, states);
}

void Player::DespawnProjectiles()
{
	//m_projectiles.erase(std::remove_if(m_projectiles.begin(),
	//	m_projectiles.end(),
	//	[](auto& projectile) {
	//	projectile.MarkedForDespawn(); // put your condition here
	//	}),
	//	m_projectiles.end());
	std::erase_if(m_projectiles, [](Projectile& x) {return x.MarkedForDespawn();});
}

std::vector<Projectile>& Player::GetProjectiles()
{
	return m_projectiles;
}

FloatRect Player::GetHitboxPosition()
{
	return m_hitbox.getGlobalBounds();
}

void Player::SpawnProjectile()
{
}
