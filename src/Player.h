#pragma once
#include "Paths.h"
#include "AssetManager.h"
#include "HitboxEntity.h"
#include "Math.h"
#include "Projectile.h"
#include <vector>

using namespace sf;
class Player : public HitboxEntity
{
public:
	Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant);
	void HandleInputs();
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void HandleEvents(const Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
private:
	void SpawnProjectile();
	float m_speed;
	Vector2f m_direction;
	Vector2f m_mousePosition;

	// more variety !!!
	std::vector<Projectile> m_projectiles;
};

