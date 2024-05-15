#pragma once
#include "SFML/Audio/Sound.hpp"
#include <unordered_map>
#include <string>
using namespace sf;
class Listenable
{
public:
	void SetVolume(const unsigned int volume);
protected:
	std::unordered_map<std::string, Sound> m_sounds;
};



