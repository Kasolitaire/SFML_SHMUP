#pragma once
#include "Player.h"
#include "Despawnable.h"
class EventManager : public Despawnable
{
public:
	EventManager(Player& player);
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void SomeEvent();
private:
	Player& m_player;
};

