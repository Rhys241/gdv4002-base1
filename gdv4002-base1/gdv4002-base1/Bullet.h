#pragma once
#include "Vector2.h"
#include <Windows.h>
#include <GL/glu.h>

class Bullet
{
public:
	Vector2 position;
	Vector2 velocity;
	float lifetime;

	Bullet(Vector2 pos, Vector2 vel)
	 	: position(pos), velocity(vel), lifetime(2.0f) { }

	void Update(float dt)
	{
		position.x += velocity.x * dt;
		position.y += velocity.y * dt;

		lifetime -= dt;
	}

	void Render()
	{
		glPushMatrix();
		glTranslatef(position.x, position.y, 0.0f);

		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(-0.01f, -0.01f);
		glVertex2f( 0.01f, -0.01f);
		glVertex2f(0.01f, 0.01f);
		glVertex2f(-0.01f, 0.01f);
		glEnd();

		glPopMatrix();
	}

	bool IsDead() const { return lifetime <= 0.0f; }
};   
 
