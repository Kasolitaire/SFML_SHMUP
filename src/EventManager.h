#pragma once
#include "Player.h"
#include "Despawnable.h"
class EventManager : public Despawnable
{
public:
	EventManager(Player& player);
	void SomeEvent();
private:
	Player& m_player;
};

