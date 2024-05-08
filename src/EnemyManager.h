#pragma once
#include <queue>
#include "Squadron.h"
#include "Enemy.h";
#include <vector>
#include "Player.h"
class EnemyManager : public Drawable // I intend for this class to have a bunch of information about the states of other objects 
{
public:
	EnemyManager(Player& player);
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;
	void SpawnSquadron(Squadron squadron);
	
private:
	std::queue<Squadron> m_squadrons;
	std::vector<Enemy> m_enemies;
	Time m_timer;
	Player& m_player;
};