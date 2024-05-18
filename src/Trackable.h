#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Trackable
{
public:
	Trackable(RectangleShape& trackableHitbox);
	FloatRect GetTrackablePosition() const;
	void MarkAsUntracked();
	void MarkAsTracked();
	bool MarkedAsUntrackable();
	bool MarkedAsTracked();
	void MarkAsCollided();
	bool MarkedAsCollided();
protected:
	void MarkAsUntrackable();
	void SetTrackableHitbox(RectangleShape& hitbox);
private:
	FloatRect m_trackablePosition;
	bool m_tracked;
	bool m_untrackable;
	bool m_collided;
	RectangleShape& m_trackableHitbox;
};