#include "Pickup.h"

Pickup::Pickup(const PickupType type) : m_pickupType(type)
{
}

PickupType Pickup::GetPickupType()
{
	return m_pickupType;
}
