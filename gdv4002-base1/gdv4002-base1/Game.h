#pragma once
#include "Player1.h"

class Game
{
       public:
		Game();
		void Update(float dt);
		void Render();

	   private:
		   Player1 m_player;
};
