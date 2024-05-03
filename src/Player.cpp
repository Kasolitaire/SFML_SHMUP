#include "Player.h"

Player::Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant) : HitboxEntity(renderWindowConstant), m_speed(5) // refactor !!!
{
	p = Projectile(Vector2f(200, 200), 500, renderWindowConstant);
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
	m_hitbox.setSize(Vector2f(28, 12));

	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "ship.png");
	m_sprite.setTexture(texture);
	m_sprite.setScale(0.9, 0.9);
	//m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_sprite.setPosition(spawnPosition);
	
}

void Player::HandleInputs(RenderWindow& renderWindowReference)
{	
	m_mousePosition = Vector2f(renderWindowReference.mapPixelToCoords(Mouse::getPosition(renderWindowReference)));
}

void Player::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	//Vector2 velocity(m_direction.x * m_speed * deltaTime.asSeconds(), m_direction.y * m_speed * deltaTime.asSeconds());
	//m_sprite.move(velocity);
	Vector2f viewSizeVec = m_renderWindowConstant->getView().getSize();
	Vector2f vec = VectorLerp(m_sprite.getPosition(), m_mousePosition, m_speed * deltaTime.asSeconds());
	if(!(vec.x >= viewSizeVec.x || vec.y >= viewSizeVec.y || vec.x <= 0|| vec.y <= 0))
		m_sprite.setPosition(vec);
	//consoleVector2f(m_sprite.getPosition());
	m_hitbox.setPosition(vec.x, vec.y+5);
	p.Update(deltaTime, totalTimeElapsed);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	target.draw(p);
	if(m_hitboxVisible) target.draw(m_hitbox);
}
