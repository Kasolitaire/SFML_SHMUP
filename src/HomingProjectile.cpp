#include "HomingProjectile.h"

HomingProjectile::HomingProjectile(
	const HitboxEntity& entity,
	const Vector2f spawnPosition,
	const float speed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp) : Projectile(spawnPosition, speed, renderWindowConstant, timeStamp), m_entity(entity)
{
	m_hitbox.setPosition(m_sprite.getPosition());
	m_hitbox.setSize(Vector2f(10, 10));
	m_hitbox.setOrigin(m_hitbox.getSize().x / 2, m_hitbox.getSize().y / 2);
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "darkgrey_02.png");
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void HomingProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	Movement(deltaTime, totalTimeElapsed);
	m_hitbox.setPosition(m_sprite.getPosition());
}

void HomingProjectile::Movement(const Time deltaTime, const Time totalTimeElapsed)
{
	float rotation = getAngleToTarget(m_entity.GetHitboxPosition().getPosition(), m_sprite.getPosition());
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
		float increment = (m_sprite.getRotation() - 100 * deltaTime.asSeconds());
		m_sprite.setRotation(increment);

		y = cosf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
		x = -sinf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
	}
	else
	{
		float decrement = m_sprite.getRotation() + 100 * deltaTime.asSeconds();
		m_sprite.setRotation(decrement);

		y = cosf(degreesToRadians(decrement - 90)) * deltaTime.asSeconds() * m_speed;
		x = -sinf(degreesToRadians(decrement - 90)) * deltaTime.asSeconds() * m_speed;
	}
	m_sprite.move(x, y);
}
