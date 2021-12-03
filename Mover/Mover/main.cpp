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
					loadTexture("images/boxes/boxY.png", box);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 16; j++)
						{
							cout << occupied[i][j] << " ";
						}

						cout << endl;
					}
					cout << endl;
					cout << endl;
					cout << endl;
				}
			}
			update();
		}
		return 0;
	}
}