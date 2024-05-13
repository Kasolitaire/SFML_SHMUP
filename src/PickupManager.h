#pragma once
#pragma once
#include <queue>
#include <vector>
#include "Player.h"
#include "HomingPickup.h"
class PickupManager : public Drawable
{
public:
	PickupManager(Player& player, const RenderWindow& renderWindowConstant);
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;
	void Despawn();
private:
	RenderWindow m_renderWindowConstant;
	HomingPickup test;
};

