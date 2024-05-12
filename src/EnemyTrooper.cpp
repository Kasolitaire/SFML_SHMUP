#include "EnemyTrooper.h"

EnemyTrooper::EnemyTrooper(Player& player, Vector2f spawnPosition) : Enemy(player, spawnPosition)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "darkgrey_02.png");
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_hitbox.setSize(Vector2f(texture.getSize().x, texture.getSize().y));
	m_sprite.setPosition(spawnPosition);
	ToggleHitBox(true);
	m_hitbox.setPosition(m_sprite.getPosition());
	m_hitbox.setOrigin(m_hitbox.getSize().x / 2, m_hitbox.getSize().y / 2);
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineThickness(0.5f);
	m_hitbox.setOutlineColor(Color::Green);
}

void EnemyTrooper::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	FloatRect hitboxRect = m_player.GetHitboxPosition();
	Vector2f hitboxCenter(hitboxRect.left + hitboxRect.width / 2, hitboxRect.top + hitboxRect.height / 2);
	
	float angle = getAngleToTarget(hitboxCenter, m_sprite.getPosition());
	m_sprite.setRotation(angle);
	m_hitbox.setRotation(angle);

	//fire logic

	if (totalTimeElapsed - m_firedTimeStamp >= seconds(1.5))
	{
		m_firedTimeStamp = totalTimeElapsed;
		m_directionalProjectiles.push_back(
			DirectionalProjectile(
				m_sprite.getPosition(),
				*m_renderWindowConstant,
				totalTimeElapsed,
				150,
				angle - 90
			));

	}

	for (DirectionalProjectile& projectile : m_directionalProjectiles) 
	{
		projectile.Update(deltaTime, totalTimeElapsed);
		if (projectile.CheckForIntersection(m_player.GetHitboxPosition())) std::cout << "player hit" << std::endl;
	}
}

void EnemyTrooper::draw(RenderTarget& target, RenderStates states) const
{
	for (const DirectionalProjectile& projectile : m_directionalProjectiles) projectile.draw(target, states);
	Enemy::draw(target, states);
}
