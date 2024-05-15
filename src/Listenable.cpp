
#include "Listenable.h"

void Listenable::SetVolume(const unsigned int volume)
{
    for (auto& sound: m_sounds) {
        sound.second.setVolume(volume);
    }
}

void Listenable::PauseSounds()
{
    for (auto& sound : m_sounds) {
        sound.second.pause();
    }
}

void Listenable::UnpauseSounds()
{
    for (auto& sound : m_sounds) {
        sound.second.play();
    }
}
