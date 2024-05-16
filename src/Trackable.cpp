#include "Trackable.h"

FloatRect Trackable::GetTrackablePosition() const
{
    return m_trackablePosition;
}

void Trackable::MarkAsUntracked()
{
    m_tracked = false;
}

void Trackable::MarkAsTracked()
{
    m_tracked = true;
}

bool Trackable::MarkedAsUntrackable()
{
    return m_trackable;
}

void Trackable::MarkAsUntrackable()
{
    m_trackable = false;
}

void Trackable::UpdateTrackablePosition(FloatRect position)
{
    m_trackablePosition = position;
}
