#pragma once
#include "Vector2.h"

class Asteroid
{
public:
	Vector2 position;
	Vector2 velocity;

	Asteroid(Vector2 pos, Vector2 vel)
		: position(pos), velocity(vel)
	{}
	
	void Update(float dt);
	void Render();

	
};
