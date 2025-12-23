#include "Game.h"
#include "Vector2.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Player1.h"
#include <cmath>

Game::Game()
{

	for (int i = 0; i < 5; i++)
	{
		float x = (rand() % 200 - 100) / 100.0f;
		float y = (rand() % 200 - 100) / 100.0f;

		float vx = (rand() % 100 - 50) / 500.0f;
		float vy = (rand() % 100 - 50) / 500.0f;

		asteroids.emplace_back(Vector2(x, y), Vector2(vx, vy));
	}
}


void Game::Update(float dt)
{
	m_player.Update(dt);

	for (auto& b : bullets)
	{
		b.Update(dt);
	}

	for (auto& a : asteroids)
	{
		a.Update(dt);
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < asteroids.size(); j++)
		{
			float dx = bullets[i].position.x - asteroids[j].position.x;
			float dy = bullets[i].position.y - asteroids[j].position.y;
			float dist = sqrt(dx * dx + dy * dy);

			if (dist < 0.05f)
			{
				asteroids.erase(asteroids.begin() + j);
				bullets.erase(bullets.begin() + i);
				i--;
				break;
			}
		}
	}

	for (auto& a : asteroids)
	{
		float dx = a.position.x - m_player.m_position.x;
		float dy = a.position.y - m_player.m_position.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 0.07f)
		{
			printf("Player hit\n");
		}
	}


}

void Game::Render()
{
	m_player.Render();

	for (auto& b : bullets)
	{
		b.Render();
	}

	for (auto& a : asteroids)
	{
		a.Render();
	}
}

