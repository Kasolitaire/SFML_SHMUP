#pragma once 
#include "HomingProjectile.h"
class HomingMissile : public HomingProjectile, public Despawnable
{
public:
	HomingMissile(
		const HitboxEntity& entity,
		const Vector2f spawnPosition,
		const float speed, const float rotationSpeed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp);

private:
};

