
#include "Audible.h"

void Audible::SetVolume(const unsigned int volume)
{
    for (auto& sound: m_sounds) {
        sound.second.setVolume(volume);
    }
}

void Audible::PauseSounds()
{
    for (auto& sound : m_sounds) {
        sound.second.pause();
    }
}

void Audible::UnpauseSounds()
{
    for (auto& sound : m_sounds) {
        sound.second.play();
    }
}
