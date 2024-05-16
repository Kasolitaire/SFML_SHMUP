#pragma once
#include "Paths.h"
#include "AssetManager.h"
#include "HitboxEntity.h"
#include "CustomMath.h"
#include "Projectile.h"
#include <vector>
#include <unordered_map>
#include "HorizontalProjectile.h"
#include "Audible.h"
#include "EventManager.h"
#include "HomingMissile.h"

using namespace sf;
class Player : public HitboxEntity, public Audible, public Trackable
{
public:
	Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant, EventManager& eventManager);
	~Player();
	void HandleInputs();
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void PreDespawn();
	void HandleEvents(const Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
	void DespawnProjectiles();
	bool UnderGrace() const;
	float GetLives() const;
	std::vector<HomingMissile*> GetNonTrackingHomingMissiles();

	void DecrementLives(const Time totalTimeElapsed);
	std::vector<Projectile*> GetProjectiles(); // potentially worth making certain fucntions const within projectiles !!!
private:
	void RemoveGrace(const Time totalTimeElapsed);
	void SpawnProjectile( const Time totalTimeElapsed);
	float m_speed;
	Vector2f m_mousePosition;
	EventManager& m_eventManager;
	Time m_firedTimeStamp;
	Time m_damagedTimeStamp;
	Time m_gracePeriod;
	bool m_grace;
	bool m_fire;
	unsigned int m_lives;
	std::unordered_map<string, Animation> m_animations;
	std::vector<HorizontalProjectile*> m_horizontalProjectiles;
	std::vector<HomingMissile*> m_homingMissiles;
};

