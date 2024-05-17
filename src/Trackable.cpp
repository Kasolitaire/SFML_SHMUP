#include "Trackable.h"

Trackable::Trackable() : m_trackable(true), m_tracked(false)
{
}

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

bool Trackable::MarkedAsTracked()
{
    return m_tracked;
}

void Trackable::MarkAsUntrackable()
{
    m_trackable = false;
}

void Trackable::UpdateTrackablePosition(FloatRect position)
{
    m_trackablePosition = position;
}
