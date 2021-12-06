#include "main.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO))	//Initialising SDL
	{
		cout << "ERROR: " << SDL_GetError() << endl;
	}
	else
	{
		init();	//Initialising everything that has to be initialised
		lvl1();	//Loads the first level
		render(direct);	//Renders the frame
		bool quit = 0;							//quit check
		SDL_Event e;							//Event variable
		direct = 'd';
		while (!quit)
		{
			
			while (SDL_PollEvent(&e) != 0)		//Checking that the event queue isn't empty
			{

				if (e.type == SDL_QUIT)         //If the current event is the X button
				{
					quit = 1;					//End the while loop and close SDL
				}
				else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)	//If the current event is a key press that happened only once
				{
					player.move(e);
					render(direct);
				}
			}
			if (stamina <= 0)	//Checks if the stamina is below zero
			{
				loadTexture("images/levelsBg/deathScreenBg.png", background);
				SDL_Delay(1000);
				lvl1();			//Restarts level 1
			}
			update();	//Updates the frame
		}
		return 0;
	}
}