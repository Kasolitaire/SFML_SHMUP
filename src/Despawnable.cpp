#include "Despawnable.h"

bool Despawnable::MarkedForDespawn() const
{
	return m_despawn;
}

void Despawnable::MarkForDespawn()
{
	m_despawn = true;
}
