#pragma once
#include "HitboxEntity.h"
#include "Player.h"
class Enemy : public HitboxEntity
{
public:
	Enemy(Player& player, Vector2f spawnPosition);
	~Enemy();
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	bool MarkedForDespawn();
protected:
	bool CheckForProjectileIntersection();
	Player& m_player;
	std::vector<Projectile> m_projectiles;
	bool m_alive;
private: 
};

