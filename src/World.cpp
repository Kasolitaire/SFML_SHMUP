#include "World.h"

void World::HandleInputs()
{
	m_player.HandleInputs();
}

void World::HandleEvents(const Event& event)
{
}

World::World(RenderWindow& renderWindow) : m_renderWindowReference(renderWindow), m_player(Vector2f(100, 100))
{
	
}

void World::WorldUpdate(const Time& deltaTime, const Time& totalTimeElapsed)
{
	m_player.PlayerUpdate(deltaTime, totalTimeElapsed);
}

void World::WorldRender()
{
	for (auto& drawable : m_firstLayerDrawables) drawable->draw(m_renderWindowReference, RenderStates());
	//m_player.draw(m_renderWindowReference, RenderStates()); // I have no idea where a render state come from or how to use it !!!
}
