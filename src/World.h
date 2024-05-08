#pragma once
#include <vector>;
#include <unordered_map>;
#include <string>;
#include "SFML/Graphics.hpp";
#include "Player.h";
#include "Entity.h";
#include "ParallaxEntity.h";
#include "debug.h"
#include "EnemyManager.h"
using namespace sf;

class World
{
public:
	World(RenderWindow& renderWindow);
	void HandleInputs();
	void HandleEvents(const Event& event);
	void WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed);
	void WorldRender();
	void Despawn();
private:
	RenderWindow& m_renderWindowReference;
	Player m_player;
	EnemyManager m_enemyManager;
	std::vector<Entity*> m_LayerZeroDrawables;
	std::vector<Entity*> m_parallaxEntityVector;
	std::unordered_map<string, ParallaxEntity> m_parallaxEntityMap;
};

