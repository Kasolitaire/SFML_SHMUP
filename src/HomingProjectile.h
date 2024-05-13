#pragma once
#include "Projectile.h"
class HomingProjectile : public Projectile
{
public:
	HomingProjectile(
		const HitboxEntity& entity,
		const Vector2f spawnPosition,
		const float speed, const float rotationSpeed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
protected:
	void Movement(const Time deltaTime, const Time totalTimeElapsed);
	const HitboxEntity& m_entity;
	float m_rotationSpeed;
};