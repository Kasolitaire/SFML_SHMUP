#pragma once
#include "Projectile.h"
class DirectionalProjectile : public Projectile
{
public:
	DirectionalProjectile(
		const Vector2f spawnPosition, 
		float speed,
		const RenderWindow& renderWindowConstant,
		const Time timeStamp,
		const float rotation);
	void MarkForDespawn() override;
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
private:
	const float m_rotation;
};

