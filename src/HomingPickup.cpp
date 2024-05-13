#include "HomingPickup.h"

HomingPickup::HomingPickup(
	const HitboxEntity& entity,
	const Vector2f spawnPosition,
	const float speed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp) : HomingProjectile(entity, spawnPosition, speed, renderWindowConstant, timeStamp),
	m_animation(ASSETS_PATH + "battery_sheet.png", 15, 0.1f)
{
	
}

void HomingPickup::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	HomingProjectile::Update(deltaTime, totalTimeElapsed);
	m_animation.Update(deltaTime, m_sprite);
}
