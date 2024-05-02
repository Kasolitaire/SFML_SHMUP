#include "HitboxEntity.h"

void HitboxEntity::ToggleHitBox(bool visible)
{
	m_hitboxVisible = visible;
}

bool HitboxEntity::CheckForIntersection(FloatRect transfrom)
{
	return m_hitbox.getGlobalBounds().intersects(transfrom);
}
