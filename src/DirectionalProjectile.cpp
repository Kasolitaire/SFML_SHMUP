#include "DirectionalProjectile.h"
DirectionalProjectile::DirectionalProjectile(
	const Vector2f spawnPosition,
	float speed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp,
	const float rotation) : Projectile(spawnPosition, speed, renderWindowConstant, timeStamp), m_rotation(rotation)
{
	
}

void DirectionalProjectile::MarkForDespawn()
{
	// whatever addition logic we want 
	Projectile::MarkedForDespawn();
}

void DirectionalProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	float y = -sinf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
	float x = cosf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
	m_sprite.move(x, y);
}
