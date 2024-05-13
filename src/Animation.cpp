#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(std::string filename, const unsigned int sectionCount, const float m_frameDuration) :
	m_sectionCount(sectionCount),
	m_frameDuration(m_frameDuration),
	m_currentSection(0),
	m_totalTimeElapsed(Time()),
	m_texture(AssetManager::GetTexture(filename))
{
	Vector2u textureSize = m_texture.getSize();
	m_intRect.width = textureSize.x / m_sectionCount;
	m_intRect.height = textureSize.y;
}

bool Animation::Update(const Time deltaTime, Sprite& sprite)
{
	bool completed = false;
	
	if (m_currentSection == 0)
		sprite.setTexture(m_texture);
	
	m_totalTimeElapsed += deltaTime;
	if (m_totalTimeElapsed.asSeconds() >= m_frameDuration) 
	{
		m_totalTimeElapsed -= seconds(m_frameDuration);
		m_currentSection++;
		if (m_currentSection == m_sectionCount) 
		{
			m_currentSection = 0;
			completed = true;
		}
		m_intRect.left = m_currentSection * m_intRect.width;
	}
	sprite.setTextureRect(m_intRect);
	return completed;
}

Vector2f Animation::GetFrameSize() const
{
	return Vector2f(m_intRect.width, m_intRect.height);
}
