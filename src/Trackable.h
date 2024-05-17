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
protected:
	void MarkAsUntrackable();
	void UpdateTrackablePosition(FloatRect position);
	FloatRect m_trackablePosition;
	bool m_tracked;
	bool m_trackable;
private:
};