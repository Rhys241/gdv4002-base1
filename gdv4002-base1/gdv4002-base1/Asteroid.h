#pragma once
#include "Vector2.h"

class Asteroid
{
public:
	Asteroid(Vector2 pos, Vector2 vel);

	void Update(float dt);
	void Render();

	Vector2 position;
	Vector2 velocity;
};
