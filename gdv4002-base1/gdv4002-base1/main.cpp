#include "Engine.h"
#include "Game.h"

Game game;

void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_LEFT)
		{
			game.m_player.Rotate(-5.0f);
		}
	}
	else if (key == GLFW_KEY_RIGHT)
	{
		game.m_player.Rotate(5.0f);
	}
	else if (key == GLFW_KEY_UP)
	{
		game.m_player.Thrust();
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

// Function prototypes

int main(void) 
{
	setKeyboardHandler(keyboardHandler);
	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	if (initResult != 0)
	{
		printf("cannot setup game window\n");
	}

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//callback engine
	
	//
	// Setup game scene objects here
	//
	
	setUpdateFunction(gameUpdateCallback);
	setRenderFunction(gameRenderCallback);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


