#include "Player.h"

Player::Player(const Vector2f& spawnPosition)
{
	m_sprite.setTexture(AssetManager::GetTexture(ASSETS_PATH + "player_1.png"));
	m_sprite.setScale(0.3, 0.3);
	m_sprite.setPosition(spawnPosition);
	m_sprite.setRotation(90);

}

void Player::HandleInputs()
{
	if (Keyboard::isKeyPressed(Keyboard::S))
		m_speed.y = 100;
	else m_speed.y = 0;
}

void Player::PlayerUpdate(const Time& deltaTime, const Time& totalTimeElapsed)
{
	Vector2 velocity(m_speed.x * deltaTime.asSeconds(), m_speed.y * deltaTime.asSeconds());
	m_sprite.move(velocity);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
}
