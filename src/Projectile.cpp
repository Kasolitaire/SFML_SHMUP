#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(Vector2f spawnPosition, float speed, const RenderWindow& renderWindowConstant) : HitboxEntity(renderWindowConstant), m_speed(speed)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "projectile_1.png");
	m_sprite.setTexture(texture);
	m_sprite.rotate(90);
	m_sprite.setScale(0.5, 0.5);
	m_sprite.setPosition(spawnPosition);
}

void Projectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	Vector2f velocity(deltaTime.asSeconds() * m_speed, 0);
	m_sprite.move(velocity);
}

void Projectile::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
}
