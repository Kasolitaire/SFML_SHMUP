#include "Game.h"

Game::Game() : m_renderWindow(VideoMode(576, 324), "SFML works!"), m_clock(), m_world(new World(m_renderWindow)), m_pauseMenu(m_renderWindow)
{
	m_renderWindow.setSize(Vector2u(1152, 648));
	View view = View(FloatRect(0, 0, 576, 324));
	m_renderWindow.setView(view);
	m_renderWindow.setMouseCursorVisible(false); 
	/*View view = m_renderWindow.getView();
	view.zoom(0);*/
	/*m_renderWindow.setView(view);*/
	// starts the game
	Run();
}

Game::~Game()
{
	delete m_world;
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

		if (m_world->MarkedForDespawn()) // really don't like this
			ReloadWorld();
	}
}

void Game::Update()
{
	if (!m_paused) 
	{
		// real time inputs
		m_world->HandleInputs(); 
		// frame by frame logic
		m_world->WorldUpdate(m_deltaTime, m_totalTimeElapsed);
	}
}

void Game::Render()
{
	// clear view
	m_renderWindow.clear();
	// all necessary draw calls
	m_world->WorldRender();
	//m_pauseMenu.draw(m_renderWindow, RenderStates());
	// display all changes
	m_renderWindow.display();
}

void Game::PollEvents()
{
	while (m_renderWindow.pollEvent(m_event)) 
	{
		switch (m_event.type)
		{
		case Event::Closed :
			m_renderWindow.close();
		case Event::KeyPressed :
			switch (m_event.key.code)
			{
			case sf::Keyboard::Escape:
				m_paused = !m_paused;
				break;
			case sf::Keyboard::F11:
				m_fullscreen = !m_fullscreen;
				ToggleFullScreen();
				break;
			default:
				break;
			}
		}
		
		// handles all events relevant to gameplay
		if (!m_paused)m_world->HandleEvents(m_event);
	}
}

void Game::CalculateDeltaTime()
{
	m_deltaTime = m_clock.restart();
	m_totalTimeElapsed += m_deltaTime;
}

void Game::ToggleFullScreen()
{
	if (m_fullscreen) 
	{
		m_renderWindow.create(VideoMode(576, 324), "SFML works!", Style::Fullscreen);
		View view = View(FloatRect(0, 0, 576, 324));
		m_renderWindow.setView(view);
		m_renderWindow.setSize(Vector2u(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	}
	else 
	{
		m_renderWindow.create(VideoMode(576, 324), "SFML works!");
		View view = View(FloatRect(0, 0, 576, 324));
		m_renderWindow.setView(view);
		m_renderWindow.setSize(Vector2u(1152, 648));
	}
	//m_renderWindow.setMouseCursorVisible(false);
}

void Game::ReloadWorld()
{
	if (m_world->MarkedForDespawn())
	{
		delete m_world;
		m_world = new World(m_renderWindow);
	}
}
