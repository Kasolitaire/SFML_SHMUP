#pragma once
#include "SFML/Graphics.hpp";
using namespace sf;

class World
{
public:
	void HandleEvent(const Event& event);
	World(RenderWindow& renderWindow);
	void WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed);
private:
	RenderWindow& m_renderWindowReference;
	
};

