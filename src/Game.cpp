#include "Game.h"

Game::Game() : m_renderWindow(VideoMode(640, 480), "Input", sf::Style::Close), m_world(m_renderWindow), m_clock()
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
	m_world.WorldUpdate(m_deltaTime, m_totalTimeElapsed);
}

void Game::Render()
{
	m_renderWindow.clear();
	// all necessary draw calls
	m_renderWindow.display();
}

void Game::PollEvents()
{
	while (m_renderWindow.pollEvent(m_event)) 
	{
		m_world.HandleEvent(m_event); // handles all events related to actual gameplay
		//gui.HandleEventthe g
	}
}

void Game::CalculateDeltaTime()
{
	m_deltaTime = m_clock.restart();
	m_totalTimeElapsed += m_deltaTime;
}
