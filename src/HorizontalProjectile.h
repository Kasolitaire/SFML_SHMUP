#pragma once
#include "Projectile.h"
enum Direction
{
	RIGHT = 1,
	LEFT = -1
};
class HorizontalProjectile : public Projectile
{
public:
	HorizontalProjectile(
		const Vector2f spawnPosition,
		float speed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp,
		Direction direction);
	 void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	 void SetColor(const Color color);
private:
	Direction m_direction;
};

