#pragma once
#include "Enemy.h"
class EnemyTrooper : public Enemy
{
public :
	EnemyTrooper(Player& player, Vector2f spawnPosition);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
private :
};

