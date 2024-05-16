#include "HomingMissile.h"

HomingMissile::HomingMissile(
	const HitboxEntity& entity,
	const Vector2f spawnPosition,
	const float speed,
	const float rotationSpeed,
	const RenderWindow& renderWindowConstant,
	const Time timeStamp): HomingProjectile(entity, spawnPosition, speed, rotationSpeed, renderWindowConstant, timeStamp)
{
}
