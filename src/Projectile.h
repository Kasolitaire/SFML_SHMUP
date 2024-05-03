#pragma once
#include "HitboxEntity.h";
class Projectile : public HitboxEntity
{
public:
	Projectile();
	Projectile(Vector2f spawnPosition, float speed, const RenderWindow& renderWindowConstant);
	void Update(const Time& deltaTime, const Time& totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;
protected:
	float m_speed;
private:
	
};

