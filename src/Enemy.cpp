#include "Enemy.h"

Enemy::Enemy(Player& player, Vector2f spawnPosition) : m_player(player), m_alive(true)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "enemy_2_1.png");
	m_sprite.setTexture(texture);
	m_sprite.setPosition(spawnPosition);
	m_sprite.setScale(0.5, 0.5);
	m_hitbox.setSize(Vector2f(texture.getSize().x, texture.getSize().y));
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
	m_hitbox.setPosition(m_sprite.getPosition());
	ToggleHitBox(true);
	
}

Enemy::~Enemy()
{
	std::cout << "enemy destroyed" << endl;
}

void Enemy::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	// movement
	SineMovement(deltaTime, totalTimeElapsed, 0.05, 1, 100);
	
	if (CheckForProjectileIntersection()) 
	{
		m_alive = false;
		// should take damage or die here		
	}
}

void Enemy::SineMovement(const Time& deltaTime, const Time& totalTimeElapsed,const float frequency, const float amplitude, float const speed)
{
	Vector2f enemyPosition = m_sprite.getPosition();
	float sin = sinf(enemyPosition.x * (std::numbers::pi / 180) * frequency) * amplitude;
	m_sprite.setPosition(enemyPosition.x, enemyPosition.y + sin);
	m_sprite.move(-(speed * deltaTime.asSeconds()), 0);
}

bool Enemy::MarkedForDespawn()
{
	return !m_alive;
}

bool Enemy::CheckForProjectileIntersection()
{
	bool intersected = false;
	auto& projectiles = m_player.GetProjectiles();
	for (auto& projectile : projectiles) 
	{
		if (projectile.CheckForIntersection(m_hitbox.getGlobalBounds())) 
		{
			intersected = true;
			projectile.MarkForDespawn();
		}
	} 
	return intersected;
}
