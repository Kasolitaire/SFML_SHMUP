#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "ParallaxEntity.h"
#include "debug.h"
#include "EnemyManager.h"
#include "EnemyTrooper.h"
#include"PickupManager.h"
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
	RenderWindow* m_renderWindowPointer;
	Player m_player;
	
	// managers
	EnemyManager m_enemyManager;
	PickupManager m_pickUpManager;
	EventManager m_eventManager;

	// parallax
	std::vector<Entity*> m_parallaxEntityVector;
	std::unordered_map<string, ParallaxEntity> m_parallaxEntityMap;
};

