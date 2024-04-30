#pragma once
#include "SFML/Graphics.hpp"
#include "Paths.h"
#include "AssetManager.h";
#include "Entity.h"

using namespace sf;
class Player : public Entity
{
public:
	Player(const Vector2f& spawnPosition);
	void HandleInputs();
	void PlayerUpdate(const Time& deltaTime, const Time& totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;
private:
	Vector2f m_speed;
};

