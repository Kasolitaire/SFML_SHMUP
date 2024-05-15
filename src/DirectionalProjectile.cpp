#include "DirectionalProjectile.h"
DirectionalProjectile::DirectionalProjectile(
	const Vector2f spawnPosition,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp,
	const float speed,
const float rotation) : Projectile(spawnPosition, speed, renderWindowConstant, timeStamp),
m_rotation(rotation)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "projectile_2.png");
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_sprite.setRotation(rotation - 180);
	m_hitbox.setRotation(rotation);
	ToggleHitBox(false);
	m_hitbox.setSize(Vector2f(5, 5));
	m_animations.insert({ "explosion", Animation(ASSETS_PATH + "explosion-spritesheet.png", 8, 0.1f) });
}

void DirectionalProjectile::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	if (m_dead) 
	{
		m_sprite.setScale(0.5, 0.5);
		m_sprite.move(-100 * deltaTime.asSeconds(), 0);
		if (m_animations["explosion"].Update(deltaTime, m_sprite))
		{
			consoleBool(true, "anim");
			MarkForDespawn();
		}

			
	}
	else 
	{
		float y = cosf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
		float x = -sinf(degreesToRadians(m_rotation)) * deltaTime.asSeconds() * m_speed;
		m_sprite.move(x, y);
		m_hitbox.setPosition(m_sprite.getPosition());
	}
}

void DirectionalProjectile::MarkAsDead()
{
	m_dead = true;
}
