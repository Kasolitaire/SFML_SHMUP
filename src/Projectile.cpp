#include "Projectile.h"
Projectile::Projectile(Vector2f spawnPosition, float speed, const RenderWindow& renderWindowConstant, Time timeStamp) : 
	HitboxEntity(renderWindowConstant),
	m_speed(speed),
	m_alive(true),
	m_timeStamp(timeStamp)
{
	// setting up projectile
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "projectile_1.png");
	m_sprite.setTexture(texture);
	m_sprite.rotate(90);
	m_sprite.setScale(0.5, 0.5);
	m_sprite.setPosition(spawnPosition);
	m_hitbox.setSize(Vector2f(texture.getSize().x, texture.getSize().y));
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
	ToggleHitBox(true);
	
}

void Projectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	if (totalTimeElapsed.asSeconds() - m_timeStamp.asSeconds() >= 5)
		MarkForDespawn();
	Vector2f velocity(deltaTime.asSeconds() * m_speed, 0);
	m_sprite.move(velocity);
	m_hitbox.setPosition(m_sprite.getPosition());
}

void Projectile::MarkForDespawn()
{
	m_alive = false;
}

bool Projectile::MarkedForDespawn()
{
	return !m_alive;
}
