#pragma once
#include "Player.h"
class EventManager
{
public:
	EventManager(Player& player);
	void SomeEvent();
private:
	Player& m_player;
};

