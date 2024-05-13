#pragma once
#include "HomingProjectile.h"
#include "Pickup.h"
#include "Animation.h"
class HomingPickup : public Pickup, public HomingProjectile
{
public:
	HomingPickup(
		const HitboxEntity& entity,
		const Vector2f spawnPosition,
		const float speed,
		const float rotationSpeed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
protected:
	Animation m_animation;
};

