#include "Game.h"

Game::Game() : m_renderWindow(sf::VideoMode(576, 324), "SFML works!"), m_clock(), m_world(m_renderWindow)
{
	//m_view.move(200, 200);
	//m_view.setViewport(FloatRect(0.25, 0, 1.f, 1.f));
	m_renderWindow.setMouseCursorVisible(false); 
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
		switch (m_event.type)
		{
		case Event::Resized:
			ViewResizedEvent();
			break;
		case Event::Closed :
			m_renderWindow.close();
		}
		
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

void Game::ViewResizedEvent()
{
	/*View view;
	view.zoom
	view.setSize(float(m_event.size.width), float(m_event.size.height));*/

	/*sf::FloatRect visibleArea(0.f, 0.f, m_event.size.width, m_event.size.height);
	m_renderWindow.setView(sf::View(visibleArea));*/
	/*float aspectRatio = float(m_event.size.width) / float(m_event.size.height);
	m_view.setSize(aspectRatio * 240, 240);
	m_renderWindow.setView(m_view);*/
	
}
