#pragma once
#include "Projectile.h"
class HorizontalProjectile : public Projectile
{
public:
	HorizontalProjectile( Vector2f spawnPosition,  float speed, const RenderWindow& renderWindowConstant,  Time timeStamp);
	 void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
private:
};

