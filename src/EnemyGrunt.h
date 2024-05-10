#pragma once
#include "Enemy.h"
class EnemyGrunt : public Enemy
{
public :
	EnemyGrunt(Player& player, Vector2f spawnPosition);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
};

