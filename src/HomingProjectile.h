#pragma once
#include "Projectile.h"
class HomingProjectile : public Projectile
{
public:
	HomingProjectile(const HitboxEntity& entity, const Vector2f spawnPosition, const float speed, const RenderWindow& renderWindowConstant, const Time timeStamp);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
protected:
	const HitboxEntity& m_entity;
};