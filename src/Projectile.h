#pragma once
#include "HitboxEntity.h";
class Projectile : public HitboxEntity
{
public:
	Projectile(const Vector2f spawnPosition, const float speed, const RenderWindow& renderWindowConstant, const Time timeStamp);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed);
	virtual void MarkForDespawn();
	virtual bool MarkedForDespawn();
protected:
	float m_speed;
	bool m_alive;
	bool m_despawn;
	Time m_timeStamp;
};