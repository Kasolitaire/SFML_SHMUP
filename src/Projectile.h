#pragma once
#include "HitboxEntity.h";
#include "Despawnable.h"
class Projectile : public HitboxEntity, public Despawnable
{
public:
	Projectile(const Vector2f spawnPosition, const float speed, const RenderWindow& renderWindowConstant, const Time timeStamp);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed);
protected:
	float m_speed;
	bool m_dead;
	bool m_despawn;
	Time m_timeStamp;
};