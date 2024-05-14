#pragma once
#include "SFML/Graphics.hpp"
#include "World.h"
#include <iostream>
#include "PauseMenu.h"
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
	void ToggleFullScreen();
	World m_world;
	RenderWindow m_renderWindow;
	Event m_event;
	Clock m_clock;
	Time m_totalTimeElapsed;
	Time m_deltaTime;

	// temp pause
	// pause menu
	PauseMenu m_pauseMenu;
	bool m_paused = false;
	bool m_fullscreen = false;
};

