#pragma once
#include "Enemy.h"
#include "DirectionalProjectile.h"
class EnemyTrooper : public Enemy
{
public :
	EnemyTrooper(Player& player, Vector2f spawnPosition);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void draw(RenderTarget& target, RenderStates states) const override;
private :
	std::vector<DirectionalProjectile> m_directionalProjectiles;
	Time m_firedTimeStamp;
};

