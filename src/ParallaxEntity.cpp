#include "ParallaxEntity.h"

ParallaxEntity::ParallaxEntity() : m_speed(0.f)
{
}

ParallaxEntity::ParallaxEntity(const std::string& filename, const View& view, const float& speed, const bool repeat) : m_speed(speed), m_repeat(repeat)
{
	
	// semantics refactor !!!
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + filename);
	m_sprite.setTexture(texture);
	/*int viewWidth = view.getViewport().getSize().y;*/
	m_textureSize = texture.getSize();
		
	m_sprite.setTextureRect(IntRect(0, 0, 1152, m_textureSize.y));
	texture.setRepeated(repeat);
}

void ParallaxEntity::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	// semantics refactor !!!
	float velocity = (m_speed * deltaTime.asSeconds());
	m_sprite.move(-velocity, 0);
	if (m_sprite.getGlobalBounds().left <= -static_cast<int>(m_textureSize.x))
		m_sprite.setPosition(0, 0);
}

void ParallaxEntity::SetSpeed(const float& speed)
{
	m_speed = speed;
}

void ParallaxEntity::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
}
