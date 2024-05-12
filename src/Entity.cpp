#include "Entity.h"
#include "Animation.h"

Entity::Entity()
{
}

FloatRect Entity::GetSpritePosition() const
{
	return m_sprite.getGlobalBounds();
}

void Entity::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
}

void Entity::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
}

Entity::Entity(const RenderWindow& renderWindowConstant) : m_renderWindowConstant(&renderWindowConstant)
{
}
