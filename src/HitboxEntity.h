#pragma once
#include "Entity.h"
class HitboxEntity : public Entity
{
public:
	HitboxEntity();
	virtual void ToggleHitBox(bool visible);
	virtual bool CheckForIntersection(FloatRect transfrom);
protected:
	HitboxEntity(const RenderWindow& renderWindowConstant);
	bool m_hitboxVisible;
	RectangleShape m_hitbox;
};

