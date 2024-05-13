#pragma once
#include "HomingProjectile.h"
#include "Pickup.h"
#include "Animation.h"
class HomingPickup : Pickup, HomingProjectile
{
private:
	HomingPickup(
		const HitboxEntity& entity,
		const Vector2f spawnPosition,
		const float speed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
protected:
	Animation m_animation;
};

