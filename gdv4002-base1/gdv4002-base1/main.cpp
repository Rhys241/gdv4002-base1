#include "Engine.h"
#include "Game.h"

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