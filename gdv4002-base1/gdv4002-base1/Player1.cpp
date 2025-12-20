#include "Player1.h"
#include <cmath>
#include "texture_loader.h"
#include <iostream>

Player1::Player1()
{
	m_position = Vector2(512, 512); //centre of the screen
	m_rotation = 0.0f;
	m_speed = 5.0f;

	m_textureID = fiLoadTexture("Assets/player.png", TextureProperties());
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

	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-32, -32);
	glTexCoord2f(1, 0); glVertex2f(32, -32);
	glTexCoord2f(1, 1); glVertex2f(32, 32);
	glTexCoord2f(0, 1); glVertex2f(-32, 32);
	glEnd();

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