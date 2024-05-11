#include "HitboxEntity.h"

HitboxEntity::HitboxEntity()
{
}

void HitboxEntity::ToggleHitBox(bool visible)
{
	// configure visible hitbox
	m_hitboxVisible = visible;
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
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
