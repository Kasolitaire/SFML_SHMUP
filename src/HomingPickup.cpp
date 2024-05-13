#include "HomingPickup.h"

HomingPickup::HomingPickup(
	const HitboxEntity& entity,
	const Vector2f spawnPosition,
	const float speed,
	const float rotationSpeed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp) : HomingProjectile(entity, spawnPosition, speed, rotationSpeed , renderWindowConstant, timeStamp),
	m_animation(ASSETS_PATH + "battery_sheet.png", 15, 0.1f)
{
	Vector2f frameSize = m_animation.GetFrameSize();
	m_sprite.setOrigin(frameSize.x / 2, frameSize.y / 2);
	m_hitbox.setSize(frameSize);
	m_hitbox.setOrigin(frameSize.x / 2, frameSize.y / 2);
}

void HomingPickup::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	HomingProjectile::Update(deltaTime, totalTimeElapsed);
	m_animation.Update(deltaTime, m_sprite);
}
