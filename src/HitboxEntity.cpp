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

void HitboxEntity::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	if (m_hitboxVisible) target.draw(m_hitbox);
}

HitboxEntity::HitboxEntity(const RenderWindow& renderWindowConstant) : Entity(renderWindowConstant)
{
}
