#pragma once
class Despawnable
{
public:
	bool MarkedForDespawn() const;
	void MarkForDespawn();
protected:
	bool m_despawn = false;
};

