#pragma once
#include "HitboxEntity.h";
class Projectile : public HitboxEntity
{
public:
	Projectile(Vector2f spawnPosition, float speed, const RenderWindow& renderWindowConstant, Time timeStamp);
	void Update(const Time& deltaTime, const Time& totalTimeElapsed);
	void MarkForDespawn();
	bool MarkedForDespawn();
protected:
	float m_speed;
	bool m_alive;
	Time m_timeStamp;
private:
	
};