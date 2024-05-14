#include "PickupManager.h"

PickupManager::PickupManager(Player& player, const RenderWindow& renderWindowConstant, EventManager& eventManager) :
	m_player(player), m_renderWindowConstant(&renderWindowConstant), m_eventManager(eventManager)
{
}

void PickupManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	for (HomingPickup* pickup : m_homingPickups) 
	{
		pickup->Update(deltaTime, totalTimeElapsed);
		
		if (pickup->CheckForIntersection(m_player.GetHitboxPosition())) 
		{
			PickupCollisionEvent(pickup);
			pickup->MarkForDespawn();
		}
	}
}

void PickupManager::draw(RenderTarget& target, RenderStates states) const
{
	for (HomingPickup* pickup : m_homingPickups)
		pickup->draw(target, states);
}

void PickupManager::Despawn()
{
	std::erase_if(m_homingPickups, [](HomingPickup* pickup)
		{
			if (pickup->MarkedForDespawn())
			{
				delete pickup;
				return true;
			}
			return false;
		});
}

void PickupManager::CreatePickup(const PickupType type, const Vector2f spawnPosition) // should also get time stamp !!!
{
	switch (type)
	{
	case PickupType::BATTERY:
		m_homingPickups.push_back(new HomingPickup(m_player, spawnPosition, 200, 200, *m_renderWindowConstant, Time(), type));	
		break;
	}
}

void PickupManager::PickupCollisionEvent(Pickup* pickup)
{
	switch (pickup->GetPickupType())
	{
	case PickupType::BATTERY :
		//event manager logic
		m_eventManager.SomeEvent();
		break;
	}
}
