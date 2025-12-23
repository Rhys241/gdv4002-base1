#pragma once
#include "Player1.h"
#include <vector>
#include "Bullet.h"
#include "Asteroid.h"

class Game
{
       public:
		Game();
		void Update(float dt);
		void Render();
		std::vector<Asteroid> asteroids;

	   public:
		   Player1 m_player;
		   std::vector<Bullet> bullets;

		  
};
