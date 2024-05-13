#pragma once
#include <queue>
#include <vector>
#include "Squadron.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyGrunt.h"
#include "EnemyTrooper.h"
class EnemyManager : public Drawable // I intend for this class to have a bunch of information about the states of other objects 
{
public:
	EnemyManager(Player& player, const RenderWindow& renderWindowConstant);
	~EnemyManager();
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;
	void SpawnSquadron(Squadron squadron);
	void Despawn();
	
private:
	void DespawnEnemies();
	void DespawnEnemyProjectiles();
	const RenderWindow& m_renderWindowConstant;
	std::queue<Squadron> m_squadrons;
	std::vector<Enemy*> m_enemies;
	Time m_timer;
	Player& m_player;
};