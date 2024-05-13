#include "Enemy.h"

Enemy::Enemy(Player& player, Vector2f spawnPosition, const RenderWindow& renderWindowConstant) :
	HitboxEntity(renderWindowConstant),
	m_player(player), 
	m_despawn(false)
{
}

Enemy::~Enemy()
{
	std::cout << "enemy destroyed" << endl;
}

void Enemy::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
}

void Enemy::SineMovement(const Time& deltaTime, const Time& totalTimeElapsed,const float frequency, const float amplitude, float const speed)
{
	Vector2f enemyPosition = m_sprite.getPosition();
	float sin = sinf(enemyPosition.x * (std::numbers::pi / 180) * frequency) * amplitude;
	m_sprite.setPosition(enemyPosition.x, enemyPosition.y + sin);
	m_sprite.move(-(speed * deltaTime.asSeconds()), 0);
}

bool Enemy::MarkedForDespawn() const
{
	return m_despawn;
}

void Enemy::MarkForDespawn()
{
	m_despawn = true;
}

bool Enemy::CheckForProjectileIntersection()
{
	bool intersected = false;
	std::vector<Projectile*> projectiles = m_player.GetProjectiles();
	for (Projectile* projectile : projectiles) 
	{
		if (projectile->CheckForIntersection(m_hitbox.getGlobalBounds())) 
		{
			intersected = true;
			projectile->MarkForDespawn();
		}
	} 
	return intersected;
}
