#include "main.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		cout << "ERROR: " << SDL_GetError() << endl;
	}
	else
	{
		init();
		loadTexture("images/bg.png", background);
		lvl1();
		bool quit = 0;							//quit check
		SDL_Event e;							//Event variable
		while (!quit)
		{
			
			while (SDL_PollEvent(&e) != 0)		//Checking that the event queue isn't empty
			{

				if (e.type == SDL_QUIT)         //If the current event is the X button
				{
					quit = 1;					//End the while loop and close SDL
				}
				else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
				{
					player.move(e);
				}
			}
			update();
		}
		return 0;
	}
}