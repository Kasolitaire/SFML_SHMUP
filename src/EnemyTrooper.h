#pragma once
#include "Enemy.h"
#include "DirectionalProjectile.h"
class EnemyTrooper : public Enemy
{
public :
	EnemyTrooper(Player& player, Vector2f spawnPosition, const RenderWindow& renderWindowConstant, const float speed, const float rotationSpeed);
	~EnemyTrooper();
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void draw(RenderTarget& target, RenderStates states) const override;
	void DespawnProjectiles();
	void MarkProjectilesForDespawn(const Time deltaTime, const Time totalTimeElapsed);
private :
	void Movement();
	std::unordered_map<std::string, Animation> m_animations;
	std::vector<DirectionalProjectile> m_directionalProjectiles;
	Time m_firedTimeStamp;
	float m_speed;
	float m_rotationSpeed;
};

