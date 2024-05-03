#pragma once
#include <vector>;
#include <unordered_map>;
#include <string>;
#include "SFML/Graphics.hpp";
#include "Player.h";
#include "Entity.h";
#include "ParallaxEntity.h";
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
	std::vector<Entity*> m_firstLayerDrawables;
	std::vector<Entity*> m_parallaxEntityVector;
	std::unordered_map<string, ParallaxEntity> m_parallaxEntityMap;

	RectangleShape r; //test
};

