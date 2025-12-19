#include "Game.h"

Game::Game()
{
	//asteroid spawn
}

void Game::Update(float dt)
{
	m_player.Update(dt);
}

void Game::Render()
{
	m_player.Render();
}