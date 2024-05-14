#pragma once
#include "HitboxEntity.h"
#include "EventManager.h"
enum PickupType {BATTERY};
class Pickup 
{
public:
	Pickup(const PickupType type);
	PickupType GetPickupType();
protected:
	PickupType m_pickupType;
};

