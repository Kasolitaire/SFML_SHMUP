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
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void MarkAsDead();
private:
	float m_rotation;
	std::unordered_map<std::string, Animation> m_animations;
};

