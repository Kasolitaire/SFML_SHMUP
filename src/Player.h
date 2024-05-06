#pragma once
#include "Paths.h"
#include "AssetManager.h"
#include "HitboxEntity.h"
#include "Math.h"
#include "Projectile.h"
#include <vector>
#include "Animation.h"

using namespace sf;
class Player : public HitboxEntity
{
public:
	Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant);
	void HandleInputs();
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void HandleEvents(const Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
	void DespawnProjectiles();
	std::vector<Projectile>& GetProjectiles(); // potentially worth making certain fucntions const within projectiles !!!
	FloatRect GetHitboxPosition();
private:
	void SpawnProjectile();
	float m_speed;
	Vector2f m_mousePosition;
	
	// for fire logic
	Time m_firedTimeStamp;
	bool m_fire;

	// animations
	std::vector<Animation> m_animations;

	// more variety !!!
	std::vector<Projectile> m_projectiles;
};

