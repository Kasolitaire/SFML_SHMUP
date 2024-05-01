#pragma once
#include "SFML/Graphics.hpp"
#include "Paths.h"
#include "AssetManager.h"
#include "Entity.h"
#include "Math.h"

using namespace sf;
class Player : public Entity
{
public:
	Player(const Vector2f& spawnPosition);
	void HandleInputs(RenderWindow& renderWindowReference);
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void draw(RenderTarget& target, RenderStates states) const override;
private:
	float m_speed;
	Vector2f m_direction;
	Vector2f m_mousePosition;
};

