#include "World.h"

World::World(RenderWindow& renderWindow) : m_renderWindowReference(renderWindow), m_player(Vector2f(100, 100), m_renderWindowReference)
{
	//test
	r.setFillColor(Color::White);
	r.setSize(Vector2f(50, 50));
	r.setPosition(50, 50);
	
	View view = m_renderWindowReference.getView();
	m_parallaxEntityMap["1"] = ParallaxEntity("1.png", view, 5, true);
	m_parallaxEntityMap["2"] = ParallaxEntity("2.png", view, 50, true);
	m_parallaxEntityMap["4"] = ParallaxEntity("4.png", view, 75, true);
	
	
	m_firstLayerDrawables.push_back(&m_player);
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
	m_player.Update(deltaTime, totalTimeElapsed);
	if (m_player.CheckForIntersection(r.getGlobalBounds())) std::cout << "collision" << endl;
	for (auto& entity : m_parallaxEntityVector) entity->Update(deltaTime, totalTimeElapsed);

	// must always be the last function executed
	Despawn();
}

void World::WorldRender()
{
	for (auto& drawable : m_parallaxEntityVector) drawable->draw(m_renderWindowReference, RenderStates());
	for (auto& drawable : m_firstLayerDrawables) drawable->draw(m_renderWindowReference, RenderStates());
	m_renderWindowReference.draw(r);
	//m_player.draw(m_renderWindowReference, RenderStates()); // I have no idea where a render state come from or how to use it !!!
}

void World::Despawn()
{
}
