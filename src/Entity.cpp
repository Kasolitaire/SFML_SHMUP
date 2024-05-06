#include "Entity.h"

Entity::Entity()
{
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
