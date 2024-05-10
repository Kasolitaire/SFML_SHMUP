#include "EnemyGrunt.h"

EnemyGrunt::EnemyGrunt(Player& player, Vector2f spawnPosition) : Enemy(player, spawnPosition)
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
}

void EnemyGrunt::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	m_sprite.move(-100 * deltaTime.asSeconds(), 0);

	if (CheckForProjectileIntersection())
	{
		m_alive = false;
		// should take damage or die here		
	}
	m_hitbox.setPosition(m_sprite.getPosition());
}
