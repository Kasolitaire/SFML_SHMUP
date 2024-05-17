#include "EnemyGrunt.h"

EnemyGrunt::EnemyGrunt(
	Player& player,
	Vector2f spawnPosition,
	const RenderWindow& renderWindowConstant) : Enemy(player, spawnPosition, renderWindowConstant)
{
	m_sprite.setPosition(spawnPosition);
	m_sprite.setScale(0.8, 0.8);
	
	m_animations.insert({"explosion", Animation(ASSETS_PATH + "explosion-spritesheet.png", 8, 0.1f)});
	m_animations.insert({ "grunt", Animation(ASSETS_PATH + "grunt_spritesheet.png", 3, 0.1f) });

	Vector2f frameSize = m_animations["grunt"].GetFrameSize();
	float reduceMultiplier = 0.5;
	m_hitbox.setSize(Vector2f(frameSize.x * reduceMultiplier, frameSize.y * reduceMultiplier));
	m_sprite.setOrigin(frameSize.x / 2, frameSize.y / 2);
	m_hitbox.setOrigin(frameSize.x / 2 * reduceMultiplier, frameSize.y / 2 * reduceMultiplier);

	m_hitbox.setPosition(m_sprite.getPosition());
	//ToggleHitBox(true);
}

void EnemyGrunt::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	UpdateTrackablePosition(GetHitboxPosition());
	m_sprite.move(-100 * deltaTime.asSeconds(), 0); 
	
	if (!m_dead && CheckForProjectileIntersection()) 
	{
		MarkAsDead();
		MarkAsUntrackable();
		m_sounds.at("explosion").play();
	}
	if (m_dead)
	{
		if (m_animations["explosion"].Update(deltaTime, m_sprite))
			
			MarkForDespawn();
		// should take damage or die here		!!!
	}
	else 
	{
		m_animations["grunt"].Update(deltaTime, m_sprite);
		if (m_player.GetHitboxPosition().intersects(m_hitbox.getGlobalBounds()))
			m_player.DecrementLives(totalTimeElapsed);
	}
	m_hitbox.setPosition(m_sprite.getPosition());
}
