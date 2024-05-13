#include "DirectionalProjectile.h"
DirectionalProjectile::DirectionalProjectile(
	const Vector2f spawnPosition,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp,
	const float speed,
	const float rotation) : Projectile(spawnPosition, speed, renderWindowConstant, timeStamp), m_rotation(rotation)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "projectile_2.png");
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_sprite.setRotation(rotation - 180);
	ToggleHitBox(true);
	m_hitbox.setSize(Vector2f(5, 5));
	
}

void DirectionalProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	float y = cosf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
	float x = -sinf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
	m_sprite.move(x, y);
	m_hitbox.setPosition(m_sprite.getPosition());
}
