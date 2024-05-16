#pragma once
#include "HitboxEntity.h"
#include "Player.h"
#include <numbers>
class Enemy : public HitboxEntity, public Audible, public Trackable
{
public:
	Enemy(Player& player, Vector2f spawnPosition, const RenderWindow& renderWindowConstant);
	~Enemy();
	void SineMovement(const Time& deltaTime, const Time& totalTimeElapsed, const float frequency, const float amplitude, float const speed); // the speed on the x axis changes how fast we go through the sine wave
	virtual bool MarkedForDespawn() const;
	virtual bool MarkedAsDead();
	virtual bool MarkedAsIgnore();
	virtual void MarkAsIgnore();
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
protected:
	virtual void MarkAsDead();
	virtual void MarkForDespawn();
	bool CheckForProjectileIntersection();
	Player& m_player;
	bool m_despawn;
	bool m_dead;
	bool m_ignore;
};

