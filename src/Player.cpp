#include "Player.h"
#include "Math.h"


Player::Player(const Vector2f& spawnPosition) : m_speed(5)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "ship.png");
	m_sprite.setTexture(texture);
	m_sprite.setScale(0.9, 0.9);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_sprite.setPosition(spawnPosition);
	//m_sprite.setRotation(90);
	
}

void Player::HandleInputs(RenderWindow& renderWindowReference)
{	
	m_mousePosition = Vector2f(renderWindowReference.mapPixelToCoords(Mouse::getPosition(renderWindowReference)));
	
	/*if (Keyboard::isKeyPressed(Keyboard::S))
		m_direction.y = 1;
	else if (Keyboard::isKeyPressed(Keyboard::W))
		m_direction.y = -1;
	else if (Keyboard::isKeyPressed(Keyboard::D))
		m_direction.x = 1;
	else if (Keyboard::isKeyPressed(Keyboard::A))
		m_direction.x = -1;
	else 
	{
		m_direction = Vector2f();
	}*/
}

void Player::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	//Vector2 velocity(m_direction.x * m_speed * deltaTime.asSeconds(), m_direction.y * m_speed * deltaTime.asSeconds());
	//m_sprite.move(velocity);
	
	//m_sprite.setPosition(m_mousePosition);
	Vector2f vec = VectorLerp(m_sprite.getPosition(), m_mousePosition, m_speed * deltaTime.asSeconds());
	m_sprite.setPosition(vec);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
}
