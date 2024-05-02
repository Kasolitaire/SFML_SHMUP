#include "math.h"
// const lerp = (x, y, a) => ;
float lerp(const float x1, const float x2, const float a)
{
	return x1 * (1 - a) + x2 * a;
}

Vector2f VectorLerp(const Vector2f vector1, const Vector2f vector2, const float a)
{
	Vector2f lerpedVector;
	lerpedVector.x = lerp(vector1.x, vector2.x, a);
	lerpedVector.y = lerp(vector1.y, vector2.y, a);
	return lerpedVector;
}