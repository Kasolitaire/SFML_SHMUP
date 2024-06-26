#pragma once;
#include "debug.h";
#include "SFML\Graphics.hpp";
#include "iostream";
#include "string";
using namespace sf;

void consoleVector2f(const Vector2f vector);
void consoleVector2u(const Vector2u vector);
void consoleVector2i(const Vector2i vector);
void consoleBool(const bool result, std::string str);
void consoleFloat(const float number);