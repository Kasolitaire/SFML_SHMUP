#include "DirectionalProjectile.h"
DirectionalProjectile::DirectionalProjectile(
	const Vector2f spawnPosition,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp,
	const float speed,
	const float rotation) : Projectile(spawnPosition, speed, renderWindowConstant, timeStamp), m_rotation(rotation)
{
	m_hitbox.setSize(Vector2f(10, 10));
	consoleVector2f(m_hitbox.getPosition());
	ToggleHitBox(true);
	
}

void DirectionalProjectile::MarkForDespawn()
{
	// whatever addition logic we want 
	Projectile::MarkedForDespawn();
}

void DirectionalProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	float y = cosf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
	float x = -sinf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
	m_sprite.move(x, y);
	m_hitbox.setPosition(m_sprite.getPosition());
}
