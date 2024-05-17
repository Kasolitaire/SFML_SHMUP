#include "CustomMath.h"
// const lerp = (x, y, a) => ;
float lerp(const float x1, const float x2, const float a)
{
	return x1 * (1 - a) + x2 * a;
}

Vector2f vectorLerp(const Vector2f vector1, const Vector2f vector2, const float a)
{
	Vector2f lerpedVector;
	lerpedVector.x = lerp(vector1.x, vector2.x, a);
	lerpedVector.y = lerp(vector1.y, vector2.y, a);
	return lerpedVector;
}

float degreesToRadians(const float degrees)
{
	return degrees * (atan(1) * 4 / 180);
}

float getAngleToTarget(const Vector2f target, const Vector2f local)
{
	float angleInRadians = atan2(target.y - local.y, target.x - local.x) * 180 / 3.141;
	return angleInRadians;
}

Vector2f getCenterOfFloatRect(const FloatRect floatRect)
{
	return Vector2f(floatRect.width / 2, floatRect.height / 2);
}

float getDistanceBetweenVectors(const Vector2f first, const Vector2f second)
{
	float d = first.x;
	float distance = std::sqrt(std::pow((first.x - second.x), 2) + std::pow(first.y - second.y, 2));
	return distance;
}



