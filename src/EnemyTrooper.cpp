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
	
	float angle = atan2(hitboxCenter.y - m_sprite.getPosition().y, hitboxCenter.x - m_sprite.getPosition().x) * 180 / 3.141;
	m_sprite.setRotation(angle);
	m_hitbox.setRotation(angle);
}
