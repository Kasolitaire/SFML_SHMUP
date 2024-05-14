#pragma once
#include "HomingProjectile.h"
#include "Pickup.h"
#include "Animation.h"
#include "Player.h"
class HomingPickup : public Pickup, public HomingProjectile
{
public:
	HomingPickup(
		const HitboxEntity& hitboxEntity,
		const Vector2f spawnPosition,
		const float speed,
		const float rotationSpeed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp,
		const PickupType type);

	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;

protected:
	Animation m_animation;
};

