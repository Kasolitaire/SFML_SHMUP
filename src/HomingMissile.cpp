#include "HomingMissile.h"

HomingMissile::HomingMissile(
	const HitboxEntity& entity,
	const Vector2f spawnPosition,
	const float speed,
	const float rotationSpeed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp) : 
	HomingProjectile(entity, spawnPosition, speed, rotationSpeed, renderWindowConstant, timeStamp), m_trackable(nullptr)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "Arrow.png");
	m_sprite.setTexture(texture);
	m_hitbox.setSize(Vector2f(texture.getSize()));
	ToggleHitBox(true);
}

bool HomingMissile::TrackingStatus() const
{
	return m_tracking;
}

void HomingMissile::PreDespawn()
{
	if (m_trackable != nullptr && m_trackable->MarkedAsUntrackable())
	{
		m_trackable = nullptr;
		m_tracking = false;
	}
}

void HomingMissile::SetTrackable(Trackable* trackable)
{
	m_trackable = trackable;
	m_tracking = true;
}

void HomingMissile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	if (m_tracking) 
	{
		if (CheckForIntersection(m_trackable->GetTrackablePosition()))
			m_trackable->MarkAsCollided();
		TrackingMovement(deltaTime, totalTimeElapsed);

	}
	else
		NonTrackingMovement(deltaTime, totalTimeElapsed);
	m_hitbox.setPosition(m_sprite.getPosition());
}

void HomingMissile::TrackingMovement(const Time deltaTime, const Time totalTimeElapsed)
{
	std::cout << "dd";
	float rotation = getAngleToTarget(
		m_trackable->GetTrackablePosition().getMiddlePosition(), m_sprite.getGlobalBounds().getMiddlePosition());
	
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
	m_hitbox.setPosition(m_sprite.getPosition());
}

void HomingMissile::NonTrackingMovement(const Time deltaTime, const Time totalTimeElapsed)
{
	//std::cout << "sfs";
}
