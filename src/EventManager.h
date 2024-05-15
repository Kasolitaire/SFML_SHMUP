#pragma once
#include "Despawnable.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
class EventManager : public Despawnable
{
public:
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void SomeEvent();
	bool GetPausedStatus();
	void SetPausedStatus(const bool status);
	void MarkPlayerAsDead();
private:
	bool m_paused = false;
	bool m_playerDead = false;
};

