#pragma once
#include "SFML/Graphics.hpp";
#include "math.h";
using namespace sf;
float lerp(const float x, const float y, const float a);
Vector2f vectorLerp(const Vector2f vector1, const Vector2f vector2, const float a);
float degreesToRadians(const float degrees);