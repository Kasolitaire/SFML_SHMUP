#include "PickupManager.h"

PickupManager::PickupManager(Player& player, const RenderWindow& renderWindowConstant, EventManager& eventManager) :
	m_player(player), m_renderWindowConstant(&renderWindowConstant), m_eventManager(eventManager)
{
	m_sounds.insert({"collect", Sound(AssetManager::GetSoundBuffer(ASSETS_PATH + "collect.wav")) });
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
			
	int size = m_homingPickups.size();
	std::erase_if(m_homingPickups, [](HomingPickup* pickup)
		{
			if (pickup->MarkedForDespawn())
			{
				delete pickup;
				return true;
			}
			return false;
		});
	
	if(size > m_homingPickups.size())
		m_sounds.at("collect").play(); // this is horrible change asap!!!
}

void PickupManager::CreatePickup(const PickupType type, const Vector2f spawnPosition)
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
		m_eventManager.IncreaseScore();
		break;
	}
}
