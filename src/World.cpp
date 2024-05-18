#include "World.h"

World::World(RenderWindow& renderWindow, EventManager& eventManager) :
	m_renderWindowPointer(&renderWindow), 
	m_eventManager(eventManager),
	m_player(Vector2f(100, 100), *m_renderWindowPointer, eventManager),
	m_pickUpManager(m_player, renderWindow, eventManager), //pickup manager requires event manager
	m_enemyManager(m_player, renderWindow, m_pickUpManager) // enemy manager requires pickup manager
{
	View view = m_renderWindowPointer->getView();
	m_parallaxEntityMap["1"] = ParallaxEntity("1.png", view, 5, true);
	m_parallaxEntityMap["2"] = ParallaxEntity("2.png", view, 50, true);
	m_parallaxEntityMap["4"] = ParallaxEntity("4.png", view, 75, true);
	

	m_parallaxEntityVector.push_back(&m_parallaxEntityMap["1"]);
	m_parallaxEntityVector.push_back(&m_parallaxEntityMap["2"]);
	m_parallaxEntityVector.push_back(&m_parallaxEntityMap["4"]);

	m_music.openFromFile(ASSETS_PATH + "Shovel Knight OST - Strike the Earth! Plains of Passage.mp3");
	m_music.play();
	m_music.setVolume(10);

	m_score.setFont(AssetManager::GetFont(ASSETS_PATH + "Vermin Vibes 1989.ttf"));
	m_score.setString("score: 0");
	m_score.setScale(0.5, 0.5);
	m_score.setPosition(Vector2f(30, 10));
	m_score.setOutlineThickness(1);
	m_score.setOutlineColor(Color::Black);
	m_score.setLetterSpacing(5);
}
void World::HandleInputs()
{
	m_player.HandleInputs();
}

void World::HandleEvents(const Event& event)
{
	//switch (event.key.code) // test code !!!
	//{
	//case Keyboard::Num1:
	//	m_player.ToggleHitBox(true);
	//	break;
	//case Keyboard::Num2:
	//	m_player.ToggleHitBox(false);
	//	//MarkForDespawn();
	//	break;
	//}

	m_player.HandleEvents(event);

	m_score.setString("SCORE: " + std::to_string(m_eventManager.GetScore()));
}

void World::WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed)
{
	// update player
	m_player.Update(deltaTime, totalTimeElapsed);
	// update enemies
	m_enemyManager.Update(deltaTime, totalTimeElapsed);
	//update pickups
	m_pickUpManager.Update(deltaTime, totalTimeElapsed);

	m_eventManager.Update(deltaTime, totalTimeElapsed);
	// update parallax background
	for (auto& entity : m_parallaxEntityVector) entity->Update(deltaTime, totalTimeElapsed);
	// must always be the last function executedp

	Despawn();
}

void World::WorldRender() // still don't know what states are for !!!
{
	for (auto& drawable : m_parallaxEntityVector) drawable->draw(*m_renderWindowPointer, RenderStates());
	
	// draw ene
	// mies and their projectiles
	m_enemyManager.draw(*m_renderWindowPointer, RenderStates());
	
	// draw pickups
	m_pickUpManager.draw(*m_renderWindowPointer, RenderStates());

	// draw player
	m_player.draw(*m_renderWindowPointer, RenderStates());

	m_renderWindowPointer->draw(m_score);
}

void World::Despawn()
{
	PreDespawn();
	m_player.DespawnProjectiles(); 
	m_enemyManager.Despawn();
	m_pickUpManager.Despawn();
	if (m_eventManager.MarkedForDespawn())
		MarkForDespawn();
}

void World::PreDespawn()
{
	m_player.PreDespawn();
}
