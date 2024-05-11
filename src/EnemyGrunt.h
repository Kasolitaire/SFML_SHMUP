#pragma once
#include <unordered_map>
#include "Enemy.h"
class EnemyGrunt : public Enemy
{
public :
	EnemyGrunt(Player& player, Vector2f spawnPosition);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
private:
	std::unordered_map<std::string, Animation> m_animations;
	bool m_alive;
};

