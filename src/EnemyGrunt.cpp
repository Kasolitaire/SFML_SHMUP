#include "EnemyGrunt.h"

EnemyGrunt::EnemyGrunt(
	Player& player,
	Vector2f spawnPosition,
	const RenderWindow& renderWindowConstant) : Enemy(player, spawnPosition, renderWindowConstant)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "enemy_2_1.png");
	m_sprite.setTexture(texture);
	m_sprite.setPosition(spawnPosition);
	m_sprite.setScale(0.8, 0.8);
	m_hitbox.setSize(Vector2f(texture.getSize().x, texture.getSize().y));
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
	m_hitbox.setPosition(m_sprite.getPosition());
	ToggleHitBox(true);
	m_animations.insert({"explosion", Animation(ASSETS_PATH + "explosion-spritesheet.png", 8, 0.1f)});
	m_animations.insert({ "grunt", Animation(ASSETS_PATH + "grunt_spritesheet.png", 3, 0.1f) });
}

void EnemyGrunt::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	m_sprite.move(-100 * deltaTime.asSeconds(), 0);
	
	if (!m_dead && CheckForProjectileIntersection())
		MarkAsDead();
	if (m_dead)
	{
		if (m_animations["explosion"].Update(deltaTime, m_sprite))
			MarkForDespawn();
		// should take damage or die here		
	}
	else 
	{
		m_animations["grunt"].Update(deltaTime, m_sprite);
	}
	m_hitbox.setPosition(m_sprite.getPosition());
}
