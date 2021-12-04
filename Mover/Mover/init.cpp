#include "main.h"
SDL_Window* mWindow = NULL;		//Main window
SDL_Surface* mSurface = NULL;	//The surface of the main window
SDL_Surface* secSurface = NULL;
SDL_Renderer* renderer = NULL;

objRect background(coords(0), coords(0), scrWidth, scrHeight);

objRect player(coords(7), coords(5), 64, 64);

objRect box(coords(5), coords(5), 64, 64);
objRect square(coords(10), coords(6), 64, 64);

int stamina = 100;

SDL_Surface* loadSurface(string path)
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Unable to load image! Error: " << IMG_GetError() << endl;
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, mSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			cout << "Unable to optimise img! Error: " << SDL_GetError() << endl;
		}

		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

bool init()
{
	bool success = 1;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Error init: " << SDL_GetError() << endl;
		success = 0;
	}
	else
	{
		mWindow = SDL_CreateWindow("Mover", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			scrWidth, scrHeight, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			cout << "Error window: " << SDL_GetError() << endl;
			success = 0;
		}
		else
		{
			renderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				cout << "Error renderer! Error: " << SDL_GetError() << endl;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout << "Error SDL_image: " << IMG_GetError() << endl;
					success = 0;
				}
				else
				{
					mSurface = SDL_GetWindowSurface(mWindow);
				}
			}
		}
	}
	return success;
}

void close()
{
	SDL_FreeSurface(secSurface); 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mWindow);

	SDL_Quit();
}

void render(char direction)
{
	loadTexture("images/bg.png", background);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			switch (grid[i][j])
			{
			case 1:
				switch (direction)
				{
				case 'w':
					loadTexture("images/choveche/chovecheW.png", player);
					break;
				case 's':
					loadTexture("images/choveche/chovecheS.png", player);
					break;
				case 'a':
					loadTexture("images/choveche/chovecheA.png", player);
					break;
				case 'd':
					loadTexture("images/choveche/chovecheD.png", player);
					break;
				}
				break;
			case 2:
				loadTexture("images/boxes/boxY.png", box);
				break;
			case 3:
				loadTexture("images/boxes/boxG.png", box);
				break;
			case 4:
				loadTexture("images/boxes/boxT.png", box);
				break;
			case 5:
				loadTexture("images/boxes/boxR.png", box);
				break;
			case 6:
				loadTexture("images/boxes/boxB.png", box);
				break;
			case 7:
				loadTexture("images/boxes/box.png", box);
				break;
				/////////////////////////////////////////////
			case 8:
				loadTexture("images/boxes/squareY.png", square);
				break;
			case 9:
				loadTexture("images/boxes/squareG.png", square);
				break;
			case 10:
				loadTexture("images/boxes/squareT.png", square);
				break;
			case 11:
				loadTexture("images/boxes/squareR.png", square);
				break;
			case 12:
				loadTexture("images/boxes/squareB.png", square);
				break;
			case 13:
				loadTexture("images/boxes/squareRB.png", square);
				break;
			}
		}
	}
}