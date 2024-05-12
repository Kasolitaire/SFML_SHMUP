#include "HitboxEntity.h"

HitboxEntity::HitboxEntity()
{
}

void HitboxEntity::ToggleHitBox(bool visible)
{
	// configure visible hitbox
	m_hitboxVisible = visible;
}

bool HitboxEntity::CheckForIntersection(FloatRect transfrom)
{
	return m_hitbox.getGlobalBounds().intersects(transfrom);
}

void HitboxEntity::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	if (m_hitboxVisible) 
		target.draw(m_hitbox);
}

FloatRect HitboxEntity::GetHitboxPosition() const
{
	return m_hitbox.getGlobalBounds();
}

HitboxEntity::HitboxEntity(const RenderWindow& renderWindowConstant) : Entity(renderWindowConstant)
{
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
}
