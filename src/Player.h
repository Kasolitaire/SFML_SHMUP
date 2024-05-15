#pragma once
#include "Paths.h"
#include "AssetManager.h"
#include "HitboxEntity.h"
#include "CustomMath.h"
#include "Projectile.h"
#include <vector>
#include <unordered_map>
#include "HorizontalProjectile.h"

using namespace sf;
class Player : public HitboxEntity
{
public:
	Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant);
	~Player();
	void HandleInputs();
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void HandleEvents(const Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
	void DespawnProjectiles();
	bool UnderGrace() const;
	float GetLives() const;
	void DecrementLives(const Time totalTimeElapsed);
	std::vector<Projectile*> GetProjectiles(); // potentially worth making certain fucntions const within projectiles !!!
private:
	void SpawnProjectile();
	float m_speed;
	Vector2f m_mousePosition;
	
	Time m_firedTimeStamp;
	Time m_damagedTimeStamp;
	Time m_gracePeriod;
	bool m_graceActive;
	bool m_fire;
	unsigned int m_lives;
	std::unordered_map<string, Animation> m_animations;
	std::vector<HorizontalProjectile*> m_horizontalProjectiles;
};

