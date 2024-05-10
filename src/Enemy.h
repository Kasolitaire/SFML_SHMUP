#pragma once
#include "HitboxEntity.h"
#include "Player.h"
#include <numbers>
class Enemy : public HitboxEntity
{
public:
	Enemy(Player& player, Vector2f spawnPosition);
	~Enemy();
	void SineMovement(const Time& deltaTime, const Time& totalTimeElapsed, const float frequency, const float amplitude, float const speed); // the speed on the x axis changes how fast we go through the sine wave
	bool MarkedForDespawn();
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
protected:
	bool CheckForProjectileIntersection();
	Player& m_player;
	std::vector<Projectile> m_projectiles;
	bool m_alive;
private: 
};

