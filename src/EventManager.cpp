#include "EventManager.h"

EventManager::EventManager(Player& player) : m_player(player)
{
}

void EventManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
}

void EventManager::SomeEvent()
{
	std::cout << "event triggered" << std::endl;
}
