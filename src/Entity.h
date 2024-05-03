#pragma once
#include <iostream>;
#include "debug.h";
#include "SFML/Graphics.hpp";
#include "AssetManager.h";
#include "Paths.h";
using namespace sf;
class Entity : public Drawable
{
public:
	Entity();
	virtual void draw(RenderTarget& target, RenderStates states) const;
	virtual void Update(const Time& deltaTime, const Time& totalTimeElapsed);
protected:
	Entity(const RenderWindow& renderWindowConstant);
	Sprite m_sprite;
	const RenderWindow* m_renderWindowConstant;
};

