#pragma once
#include <unordered_map>
#include "Enemy.h"
#include "Trackable.h"
class EnemyGrunt : public Enemy
{
public :
	EnemyGrunt(Player& player, Vector2f spawnPosition, const RenderWindow& renderWindowConstant);
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	std::unordered_map<std::string, Animation> m_animations;
	std::vector<HorizontalProjectile*> m_horizontalProjectiles;
	Time m_firedTimeStamp;
	void SpawnProjectile(const Time deltaTime, const Time totalTimeElapsed);
};

