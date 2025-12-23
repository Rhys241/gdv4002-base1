#include "Game.h"
#include "Vector2.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Player1.h"


Game::Game()
{
	std::vector<Asteroid> asteroids; //asteroid spawn

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

std::vector<Asteroid> asteroids;