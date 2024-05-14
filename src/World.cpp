#include "World.h"

World::World(RenderWindow& renderWindow) : 
	m_renderWindowPointer(&renderWindow), 
	m_player(Vector2f(100, 100), *m_renderWindowPointer),
	m_eventManager(m_player),
	m_pickUpManager(m_player, renderWindow, m_eventManager), //pickup manager requires event manager
	m_enemyManager(m_player, renderWindow, m_pickUpManager) // enemy manager requires pickup manager
{
	View view = m_renderWindowPointer->getView();
	m_parallaxEntityMap["1"] = ParallaxEntity("1.png", view, 5, true);
	m_parallaxEntityMap["2"] = ParallaxEntity("2.png", view, 50, true);
	m_parallaxEntityMap["4"] = ParallaxEntity("4.png", view, 75, true);
	

	m_parallaxEntityVector.push_back(&m_parallaxEntityMap["1"]);
	m_parallaxEntityVector.push_back(&m_parallaxEntityMap["2"]);
	m_parallaxEntityVector.push_back(&m_parallaxEntityMap["4"]);
}
void World::HandleInputs()
{
	m_player.HandleInputs();
}

void World::HandleEvents(const Event& event)
{
	switch (event.key.code) // test code !!!
	{
	case Keyboard::Num1:
		m_player.ToggleHitBox(true);
		break;
	case Keyboard::Num2:
		m_player.ToggleHitBox(false);
		break;
	}

	m_player.HandleEvents(event);
}

void World::WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed)
{
	// update player
	m_player.Update(deltaTime, totalTimeElapsed);
	
	// update enemies
	m_enemyManager.Update(deltaTime, totalTimeElapsed);

	//update pickups
	m_pickUpManager.Update(deltaTime, totalTimeElapsed);

	// update parallax background
	for (auto& entity : m_parallaxEntityVector) entity->Update(deltaTime, totalTimeElapsed);

	// must always be the last function executed
	Despawn();
}

void World::WorldRender() // still don't know what states are for !!!
{
	for (auto& drawable : m_parallaxEntityVector) drawable->draw(*m_renderWindowPointer, RenderStates());
	
	// draw enemies and their projectiles
	m_enemyManager.draw(*m_renderWindowPointer, RenderStates());
	
	// draw pickups
	m_pickUpManager.draw(*m_renderWindowPointer, RenderStates());

	// draw player
	m_player.draw(*m_renderWindowPointer, RenderStates());
}

void World::Despawn()
{
	m_player.DespawnProjectiles(); 
	m_enemyManager.Despawn();
}
