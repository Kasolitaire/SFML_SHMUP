#include "Trackable.h"

Trackable::Trackable(RectangleShape& hitbox) : m_untrackable(false), m_tracked(false), m_collided(false), m_trackableHitbox(hitbox)
{
}

FloatRect Trackable::GetTrackablePosition() const
{
    return m_trackableHitbox.getGlobalBounds();
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
    return m_untrackable;
}

bool Trackable::MarkedAsTracked()
{
    return m_tracked;
}

void Trackable::MarkAsCollided()
{
    m_collided = true;
}

bool Trackable::MarkedAsCollided()
{
    return m_collided;
}

void Trackable::MarkAsUntrackable()
{
    m_untrackable = true;
}

void Trackable::SetTrackableHitbox(RectangleShape& hitbox)
{
    m_trackableHitbox = hitbox;
}

