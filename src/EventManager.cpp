#include "EventManager.h"

void EventManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	if (MarkedForDespawn()) 
	{
		m_despawn = false;
		m_playerDead = false;
	}
	if (m_playerDead) 
	{
		MarkForDespawn();
		m_score = 0;
	}
}

void EventManager::IncreaseScore()
{
	m_score += 50;
}

int EventManager::GetScore()
{
	return m_score;
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
