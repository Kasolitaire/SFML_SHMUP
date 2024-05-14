#include "HomingProjectile.h"

HomingProjectile::HomingProjectile(
	const HitboxEntity& hitboxEntity,
	const Vector2f spawnPosition,
	const float speed, const float rotationSpeed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp) : Projectile(spawnPosition, speed, renderWindowConstant, timeStamp), m_entity(hitboxEntity), m_rotationSpeed(rotationSpeed)
{
	m_sprite.setRotation(getAngleToTarget(m_entity.GetHitboxPosition().getMiddlePosition(), m_sprite.getPosition()));
}

void HomingProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	Movement(deltaTime, totalTimeElapsed);
	m_hitbox.setPosition(m_sprite.getPosition());
}

void HomingProjectile::Movement(const Time deltaTime, const Time totalTimeElapsed)
{
	float rotation = getAngleToTarget(m_entity.GetHitboxPosition().getMiddlePosition(), m_sprite.getPosition());
	float target = rotation < 0 ? 360 + rotation : rotation;

	float cw_distance;
	float ccw_distance;
	float x = 0;
	float y = 0;
	float current = m_sprite.getRotation();
	if (current - target > 0)
	{
		cw_distance = abs(current - target);
		ccw_distance = 360 - cw_distance;
	}
	else
	{
		ccw_distance = abs(current - target);
		cw_distance = 360 - ccw_distance;
	}

	if (cw_distance < ccw_distance) //move clockwise
	{
		float increment = (m_sprite.getRotation() - m_rotationSpeed * deltaTime.asSeconds());
		m_sprite.setRotation(increment);

		y = cosf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
		x = -sinf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
	}
	else
	{
		float decrement = m_sprite.getRotation() + m_rotationSpeed * deltaTime.asSeconds();
		m_sprite.setRotation(decrement);

		y = cosf(degreesToRadians(decrement - 90)) * deltaTime.asSeconds() * m_speed;
		x = -sinf(degreesToRadians(decrement - 90)) * deltaTime.asSeconds() * m_speed;
	}
	m_sprite.move(x, y);
}
