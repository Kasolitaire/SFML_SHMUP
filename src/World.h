#pragma once
#include <vector>;
#include "SFML/Graphics.hpp";
#include "Player.h";
#include "Entity.h";
using namespace sf;

class World
{
public:
	void HandleInputs();
	void HandleEvents(const Event& event);
	World(RenderWindow& renderWindow);
	void WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed);
	void WorldRender();
		
private:
	RenderWindow& m_renderWindowReference;
	Player m_player;
	std::vector<Entity*> m_firstLayerDrawables;
};

