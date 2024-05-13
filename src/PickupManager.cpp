#include "PickupManager.h"

PickupManager::PickupManager(Player& player, const RenderWindow& renderWindowConstant) : test(player, Vector2f(), 150, 200,renderWindowConstant, Time())
{

}

void PickupManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	test.Update(deltaTime, totalTimeElapsed);
}

void PickupManager::draw(RenderTarget& target, RenderStates states) const
{
	test.draw(target, states);
}

void PickupManager::Despawn()
{
}
