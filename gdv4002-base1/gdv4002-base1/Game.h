#pragma once
#include "Player1.h"

class Game
{
       public:
		Game();
		void Update(float dt);
		void Render();

	   public:
		   Player1 m_player;
};
