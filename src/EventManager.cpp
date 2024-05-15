#include "EventManager.h"

void EventManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	if (MarkedForDespawn()) 
	{
		m_despawn = false;
		m_playerDead = false;
	}
	if (m_playerDead) 
		MarkForDespawn();
}

void EventManager::SomeEvent()
{
	std::cout << "event triggered" << std::endl;
}

bool EventManager::GetPausedStatus()
{
	return m_paused;
}

void EventManager::SetPausedStatus(const bool status)
{
	m_paused = status;
}

void EventManager::MarkPlayerAsDead()
{
	m_playerDead = true;
}
