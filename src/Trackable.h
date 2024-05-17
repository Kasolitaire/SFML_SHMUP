#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Trackable
{
public:
	Trackable();
	FloatRect GetTrackablePosition() const;
	void MarkAsUntracked();
	void MarkAsTracked();
	bool MarkedAsUntrackable();
	bool MarkedAsTracked();
	void MarkAsCollided();
protected:
	bool MarkedAsCollided();
	void MarkAsUntrackable();
	void UpdateTrackablePosition(FloatRect position);
private:
	FloatRect m_trackablePosition;
	bool m_tracked;
	bool m_trackable;
	bool m_collided;
};