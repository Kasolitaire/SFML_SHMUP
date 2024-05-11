#pragma once
#include "SFML/Graphics.hpp"
#include <string>;
#include "AssetManager.h"
using namespace sf;

class Animation
{
public:
	Animation();
	Animation(std::string filename, const unsigned int sectionCount, const float m_frameDuration);
	bool Update(const Time deltaTime, Sprite& sprite);

private:
	unsigned int m_sectionCount;
	unsigned int m_currentSection;

	float m_frameDuration;
	Time m_totalTimeElapsed;
	IntRect m_intRect;
	Texture m_texture;
};

