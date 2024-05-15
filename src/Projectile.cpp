#include "Projectile.h"
Projectile::Projectile(Vector2f spawnPosition, float speed, const RenderWindow& renderWindowConstant, Time timeStamp) : 
	HitboxEntity(renderWindowConstant),
	m_speed(speed),
	m_dead(false),
	m_despawn(false),
	m_timeStamp(timeStamp)
{
	// setting up projectile
	m_sprite.setPosition(spawnPosition);
}

void Projectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
}