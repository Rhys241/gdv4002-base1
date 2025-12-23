#pragma once

class Vector2
{
public:
		float x;
		float y;

		Vector2() : x(0) {}
		Vector2(float x, float y) : x(x), y(y) {}

		Vector2 operator*(float scalar) const
		{
			return Vector2(x * scalar, y * scalar);
		}
};
