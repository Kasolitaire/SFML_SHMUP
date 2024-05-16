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
#include "Despawnable.h"
using namespace sf;

class World : public Despawnable
{
public:
	World(RenderWindow& renderWindow, EventManager& eventManager);
	void HandleInputs();
	void HandleEvents(const Event& event);
	void WorldRender();
	void WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed); // marking for despawn or dead or despawn should only happen here
	void PreDespawn(); // check if something is about to be despawned
	void Despawn();
private:
	RenderWindow* m_renderWindowPointer;
	Player m_player;
	
	// managers
	EventManager& m_eventManager;
	PickupManager m_pickUpManager;
	EnemyManager m_enemyManager;

	// parallax
	std::vector<Entity*> m_parallaxEntityVector;
	std::unordered_map<string, ParallaxEntity> m_parallaxEntityMap;

	Music m_music;
	Text m_score;
};

