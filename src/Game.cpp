#include "Game.h"

Game::Game() : m_renderWindow(sf::VideoMode(576, 324), "SFML works!"), m_clock(), m_world(m_renderWindow)
{
	m_renderWindow.setSize(Vector2u(1152, 648));
	m_renderWindow.setMouseCursorVisible(false); 
	/*View view = m_renderWindow.getView();
	view.zoom(0);*/
	/*m_renderWindow.setView(view);*/
	// starts the game
	Run();
}

void Game::Run()
{
	while (m_renderWindow.isOpen()) 
	{
		// calculates delta time & total time elapsed
		CalculateDeltaTime();
		// polls all events
		PollEvents();
		// updates all logic
		if (!m_pause) Update();
		// renders the game
		Render();
	}
}

void Game::Update()
{
	// real time inputs
	m_world.HandleInputs(); 
	// frame by frame logic
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
		case Event::Resized :
			ViewResizedEvent();
			break;
		case Event::Closed :
			m_renderWindow.close();
		case Event::KeyPressed :
			if (m_event.key.code == sf::Keyboard::Escape)
			m_pause = !m_pause;
			break;
		}
		
		// handles all events relevant to gameplay
		if (!m_pause)m_world.HandleEvents(m_event); 
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
