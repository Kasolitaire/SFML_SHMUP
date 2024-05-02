#pragma once
#include "Entity.h"
class HitboxEntity : public Entity
{
public:
	virtual void ToggleHitBox(bool visible);
	virtual bool CheckForIntersection(FloatRect transfrom);
protected:
	bool m_hitboxVisible;
	RectangleShape m_hitbox;
};

