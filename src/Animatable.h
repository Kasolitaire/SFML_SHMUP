#pragma once
#include "Animation.h"
#include <unordered_map>
class Animatable
{
public:
protected:
	std::unordered_map<string, Animation> m_animations;
};

