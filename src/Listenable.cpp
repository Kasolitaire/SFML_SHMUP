
#include "Listenable.h"

void Listenable::SetVolume(const unsigned int volume)
{
    for (auto& sound: m_sounds) {
        sound.second.setVolume(volume);
    }
}
