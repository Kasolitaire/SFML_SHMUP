#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Player
{
public:
	Player(const Vector2f& spawnPosition);
private:
	Sprite m_playerSprite;
};

