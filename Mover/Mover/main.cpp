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
		loadMedia();

		bool quit = 0;							//quit check
		SDL_Event e;							//Event variable
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)		//Checking that the event queue isn't empty
			{
				if (e.type == SDL_QUIT)         //If the current event is the X button
				{
					quit = 1;					//End the while loop and close SDL
					close();
				}
			}
			update();
		}
		return 0;
	}
}