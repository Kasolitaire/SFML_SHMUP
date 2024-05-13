#include "Game.h"

Game::Game() : m_renderWindow(sf::VideoMode(576, 324), "SFML works!", sf::Style::Fullscreen), m_clock(), m_world(m_renderWindow)
{
	m_renderWindow.setSize(Vector2u(1920, 1080));
	View view = View(FloatRect(0, 0, 576, 324));
	m_renderWindow.setView(view);
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
		Update();
		// renders the game
		Render();
	}
}

void Game::Update()
{
	if (m_fullscreen)
		ToggleFullScreen();

	if (!m_paused) 
	{
		// real time inputs
		m_world.HandleInputs(); 
		// frame by frame logic
		m_world.WorldUpdate(m_deltaTime, m_totalTimeElapsed);
	}
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
			break;
		case Event::Closed :
			m_renderWindow.close();
		case Event::KeyPressed :
			if (m_event.key.code == sf::Keyboard::Escape)
				m_paused = !m_paused;
			if (m_event.key.code == sf::Keyboard::F11)
				m_fullscreen != m_fullscreen;
			break;
		}
		
		// handles all events relevant to gameplay
		if (!m_paused)m_world.HandleEvents(m_event);
	}
}

void Game::CalculateDeltaTime()
{
	m_deltaTime = m_clock.restart();
	m_totalTimeElapsed += m_deltaTime;
}

void Game::ToggleFullScreen()
{
	//m_renderWindow = RenderWindow(sf::VideoMode(576, 324), "SFML works!", sf::Style::Fullscreen)
}
