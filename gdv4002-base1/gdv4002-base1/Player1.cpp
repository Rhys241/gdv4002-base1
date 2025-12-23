#include "Player1.h"
#include <cmath>
#include "texture_loader.h"
#include <iostream>
#include <fstream>
#include <vector>

Player1::Player1()
{
	m_position = Vector2(0, 0); //centre of the screen
	m_rotation = 0.0f;
	m_speed = 0.1f;

	m_textureID = 0;
	std::cout << "Texture ID = " << m_textureID << "\n";
}

void Player1::Load()
{
	std::cout << "Load() was called\n";

	m_textureID = fiLoadTexture("player1.png", TextureProperties());
	std::cout << "Texture ID = " << m_textureID << "\n";
}

void Player1::Rotate(float amount)
{
	m_rotation += amount;
}

void Player1::Update(float dt)
{
	//movement
}

void Player1::Render()
{

	glPushMatrix();

	glTranslatef(m_position.x, m_position.y, 0.0f);
	glRotatef(m_rotation, 0.0f, 0.0f, 1.0f);

	glDisable(GL_TEXTURE_2D);

	glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.8f, 1.0f);

	glVertex2f(0.0f, 0.2f);

	glVertex2f(-0.15f, -0.15f);

	glVertex2f(0.15f, -0.15f);

	glEnd();

	glEnable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Player1::Thrust()
{
	float radians = m_rotation * 3.14159f / 180.0f;

	float dx = cos(radians);
	float dy = sin(radians);

	m_position.x += dx * m_speed;
	m_position.y += dy * m_speed;
}