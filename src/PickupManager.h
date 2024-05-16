#pragma once
#pragma once
#include <queue>
#include <vector>
#include "Player.h"
#include "HomingPickup.h"
#include "EventManager.h"
#include "vector";
class PickupManager : public Drawable, public Audible // will be made non listenable in the future !!!
{
public:
	PickupManager(Player& player, const RenderWindow& renderWindowConstant, EventManager& eventManager);
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;
	void Despawn();
	void CreatePickup(const PickupType type, const Vector2f spawnPosition);
private:
	void PickupCollisionEvent(Pickup* pickup);
	const RenderWindow* m_renderWindowConstant;
	std::vector<HomingPickup*> m_homingPickups;
	Player& m_player;
	EventManager& m_eventManager;
};