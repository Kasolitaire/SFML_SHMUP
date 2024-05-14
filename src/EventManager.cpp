#include "EventManager.h"

EventManager::EventManager(Player& player) : m_player(player)
{
}

void EventManager::SomeEvent()
{
	std::cout << "event triggered" << std::endl;
}
