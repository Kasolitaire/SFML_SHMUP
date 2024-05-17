#pragma once 
#include "HomingProjectile.h"
#include "Trackable.h"

class HomingMissile : public HomingProjectile, public Despawnable
{
public:
	HomingMissile(
		const HitboxEntity& entity,
		const Vector2f spawnPosition,
		const float speed, const float rotationSpeed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp);
	bool TrackingStatus() const;
	void PreDespawn();
	void SetTrackable(Trackable* trackable);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
private:
	void TrackingMovement(const Time deltaTime, const Time totalTimeElapsed);
	void NonTrackingMovement(const Time deltaTime, const Time totalTimeElapsed);
	Trackable* m_trackable;
	bool m_tracking = false;

};

