#include "HitboxEntity.h"

HitboxEntity::HitboxEntity()
{
}

void HitboxEntity::ToggleHitBox(bool visible)
{
	m_hitboxVisible = visible;
}

bool HitboxEntity::CheckForIntersection(FloatRect transfrom)
{
	return m_hitbox.getGlobalBounds().intersects(transfrom);
}

HitboxEntity::HitboxEntity(const RenderWindow& renderWindowConstant) : Entity(renderWindowConstant)
{
}
