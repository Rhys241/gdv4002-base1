#include "Asteroid.h"
#include <GLFW/glfw3.h>
#include <cmath>


void Asteroid::Update(float dt)
{
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

	if (position.x > 1.0f) position.x = -1.0f;
	if (position.x < -1.0f) position.x = 1.0f;
	if (position.y > 1.0f) position.y = -1.0f;
	if (position.y < -1.0f) position.y = 1.0f;
}

void Asteroid::Render()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, 0.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);

	for (int i = 0; i < 12; i++)
	{
		float angle = i * (3.14159f * 2 / 12);
		glVertex2f(cos(angle) * 0.05f, sin(angle) * 0.05f);
	}
	glEnd();
	glPopMatrix();

}