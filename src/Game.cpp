#include "Game.h"

Game::Game() : m_renderWindow(sf::VideoMode(320, 240), "SFML works!"), m_world(m_renderWindow), m_clock()
{
	Run();
}

void Game::Run()
{
	while (m_renderWindow.isOpen()) 
	{
		CalculateDeltaTime();
		PollEvents();
		Update();
		Render();
	}
}

void Game::Update()
{
	// handles input states
	m_world.HandleInputs(); 
	m_world.WorldUpdate(m_deltaTime, m_totalTimeElapsed);
}

void Game::Render()
{
	// clear view
	m_renderWindow.clear();
	// all necessary draw calls
	m_world.WorldRender();
	// display all changes
	m_renderWindow.display();
}

void Game::PollEvents()
{
	while (m_renderWindow.pollEvent(m_event)) 
	{
		// handles all events relevant to gameplay
		m_world.HandleEvents(m_event); 
		//gui.HandleEventthe g
	}
}

void Game::CalculateDeltaTime()
{
	m_deltaTime = m_clock.restart();
	m_totalTimeElapsed += m_deltaTime;
}
