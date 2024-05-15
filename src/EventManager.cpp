#include "EventManager.h"

EventManager::EventManager(Player& player) : m_player(player)
{
}

void EventManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	float lives = m_player.GetLives();
	if (lives == 0) 
	{
		MarkForDespawn();
	}
}

void EventManager::SomeEvent()
{
	std::cout << "event triggered" << std::endl;
}
