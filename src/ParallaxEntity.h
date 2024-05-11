#pragma once
#include "SFML/Graphics.hpp";
#include "Entity.h"
#include <string>;
#include "AssetManager.h";
#include "Paths.h";
#include <iostream>;

using namespace sf;

class ParallaxEntity : public Entity
{
public: 
	ParallaxEntity();
	ParallaxEntity(const std::string& filename, const View& view, const float& speed, const bool repeat);
	void Update(const Time& deltaTime, const Time& totalTimeElapsed) override;
	void SetSpeed(const float& speed);
	void draw(RenderTarget& target, RenderStates states) const override;

private:
	Vector2u m_textureSize;
	float m_speed;
	bool m_repeat;
};