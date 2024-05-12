#include "HorizontalProjectile.h"

HorizontalProjectile::HorizontalProjectile(
	const Vector2f spawnPosition,
	float speed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp,
	Direction direction)
	: 
	Projectile(spawnPosition, speed, renderWindowConstant, timeStamp), m_direction(direction)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "projectile_1.png");
	m_sprite.setTexture(texture);
	m_sprite.setScale(0.5, 0.5);
	FloatRect floatRect = m_sprite.getGlobalBounds();
	m_hitbox.setSize(Vector2f(floatRect.width, floatRect.height));
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
}

void HorizontalProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	if (totalTimeElapsed.asSeconds() - m_timeStamp.asSeconds() >= 5)
		MarkForDespawn();
	Vector2f velocity(deltaTime.asSeconds() * m_speed * m_direction, 0);
	m_sprite.move(velocity);
	m_hitbox.setPosition(m_sprite.getPosition());
}

void HorizontalProjectile::SetColor(const Color color)
{
	m_sprite.setColor(color);
}
