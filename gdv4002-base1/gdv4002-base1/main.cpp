#include "Engine.h"
#include "Game.h"
#include <cmath>

Game game;

void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("KEY:	%d ACTION:	%d\n", key, action);

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_LEFT)
		{
			game.m_player.Rotate(-5.0f);
		}
	    
		if (key == GLFW_KEY_RIGHT)
		{
			game.m_player.Rotate(5.0f);
		}
	    
		if (key == GLFW_KEY_UP)
		{
			game.m_player.Thrust();
		}
	    
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			float radians = game.m_player.GetRotation() * 3.14159f / 180.0f;

			Vector2 dir(cos(radians), sin(radians));

			Vector2 bulletPos = game.m_player.m_position;
			Vector2 bulletVel = dir * 1.5f; // speed

			game.bullets.emplace_back(bulletPos, bulletVel);

			printf("bullet fired! count = %zu/n", game.bullets.size());


		}
	
	}

}

void gameUpdateCallback(GLFWwindow* window, double dt)
{
	game.Update((float)dt);
}

void gameRenderCallback(GLFWwindow* window)
{
	game.Render();
}

int main(void)
{

	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	if (initResult != 0)
	{
		printf("cannot stetup game window!\n");
		return initResult;
	}

	setKeyboardHandler(keyboardHandler);

	game.m_player.Load();

	setUpdateFunction(gameUpdateCallback);
	setRenderFunction(gameRenderCallback);

	engineMainLoop();

	engineShutdown();

	return 0;


}