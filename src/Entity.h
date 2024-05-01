#pragma once
#include "SFML/Graphics.hpp";
using namespace sf;
class Entity : public Drawable
{
public:
	virtual void draw(RenderTarget& target, RenderStates states) const;
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed);
protected:
	Sprite m_sprite;
};

