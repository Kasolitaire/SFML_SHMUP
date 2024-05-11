#pragma once
#include "Projectile.h"
class DirectionalProjectile : public Projectile
{
public:
	DirectionalProjectile(
		 Vector2f spawnPosition, 
		const RenderWindow& renderWindowConstant,
		const Time timeStamp,
		 float speed,
		 float rotation);
	void MarkForDespawn() override;
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
private:
	const float m_rotation;
};

