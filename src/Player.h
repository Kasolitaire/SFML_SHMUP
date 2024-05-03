#pragma once
#include "Paths.h"
#include "AssetManager.h"
#include "HitboxEntity.h"
#include "Math.h"
#include "Projectile.h";

using namespace sf;
class Player : public HitboxEntity
{
public:
	Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant);
	void HandleInputs(RenderWindow& renderWindowReference);
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void draw(RenderTarget& target, RenderStates states) const override;
private:
	float m_speed;
	Vector2f m_direction;
	Vector2f m_mousePosition;

	Projectile p;
};

