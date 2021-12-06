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
		lvl1();
		render(direct);
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
				else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
				{
					player.move(e);
					render(direct);
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 16; j++)
						{
							cout << grid[i][j] << " ";
						}

						cout << endl;
					}
					cout << endl;
					cout << endl;
					cout << "stamina: " << stamina << endl;
					cout << endl;
				}
			}
			if (stamina <= 0)
			{
				loadTexture("images/levelsBg/deathScreenBg.png", background);
				SDL_Delay(1000);
				lvl1();
			}
			update();
		}
		return 0;
	}
}