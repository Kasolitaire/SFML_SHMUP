#pragma once
#include "SFML/Graphics.hpp";
#include "World.h";
using namespace sf;

class Game
{
public:
	Game();
private:
	void Run();
	void Update();
	void Render();
	void PollEvents();
	void CalculateDeltaTime();
	World m_world;
	RenderWindow m_renderWindow;
	Event m_event;
	Clock m_clock;
	Time m_totalTimeElapsed;
	Time m_deltaTime;
};

