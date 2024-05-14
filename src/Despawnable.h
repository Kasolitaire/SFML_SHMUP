#pragma once
class Despawnable
{
public:
	bool MarkedForDespawn() const;
protected:
	void MarkForDespawn();
	bool m_despawn = false;
};

