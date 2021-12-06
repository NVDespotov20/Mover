#include "main.h"
SDL_Window* mWindow = NULL;		//Main window
SDL_Surface* mSurface = NULL;	//The surface of the main window
SDL_Surface* secSurface = NULL;
SDL_Renderer* renderer = NULL;

objRect background(coords(0), coords(0), scrWidth, scrHeight);

objRect player(coords(7), coords(5), 64, 64);

objRect box(coords(5), coords(5), 64, 64);		//Those initialise the objects
objRect boxY(coords(5), coords(5), 64, 64);
objRect boxG(coords(6), coords(5), 64, 64);
objRect boxT(coords(7), coords(5), 64, 64);
objRect boxR(coords(8), coords(5), 64, 64);
objRect boxB(coords(9), coords(5), 64, 64);

objRect squareY(coords(10), coords(5), 64, 64);
objRect squareG(coords(10), coords(5), 64, 64);
objRect squareT(coords(10), coords(5), 64, 64);
objRect squareR(coords(10), coords(5), 64, 64);
objRect squareB(coords(10), coords(5), 64, 64);
objRect squareRB(coords(10), coords(5), 64, 64);

int stamina = 100;					//This initialises the stamina variable and object
objRect Stamina(16, 656, 992, 36);

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

	if (SDL_Init(SDL_INIT_VIDEO) < 0)	////Initialising the SDL library
	{
		cout << "Error init: " << SDL_GetError() << endl;	//If something goes wrong this will tell us what happened
		success = 0;
	}
	else
	{
		mWindow = SDL_CreateWindow("Mover", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			scrWidth, scrHeight, SDL_WINDOW_SHOWN);			//Initialising the main window
		if (mWindow == NULL)
		{
			cout << "Error window: " << SDL_GetError() << endl;
			success = 0;
		}
		else
		{
			renderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);	//Initialising the renderer
			if (renderer == NULL)
			{
				cout << "Error renderer! Error: " << SDL_GetError() << endl;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);	//Setting the default drawing color
				
				int imgFlags = IMG_INIT_PNG;	////Initialising the SDL_Image library
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
	loadTexture("images/bg.png", background);	//Loads the background

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)	//This checks every grid[][] coordinates and renders the coresponding tile
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
				loadTexture("images/boxes/boxY.png", boxY);
				break;
			case 3:
				loadTexture("images/boxes/boxG.png", boxG);
				break;
			case 4:
				loadTexture("images/boxes/boxT.png", boxT);
				break;
			case 5:
				loadTexture("images/boxes/boxR.png", boxR);
				break;
			case 6:
				loadTexture("images/boxes/boxB.png", boxB);
				break;
			case 7:
				loadTexture("images/boxes/box.png", box);
				break;
				/////////////////////////////////////////////
			case 8:
				loadTexture("images/squares/squareY.png", squareY);
				break;
			case 9:
				loadTexture("images/squares/squareG.png", squareG);
				break;
			case 10:
				loadTexture("images/squares/squareT.png", squareT);
				break;
			case 11:
				loadTexture("images/squares/squareR.png", squareR);
				break;
			case 12:
				loadTexture("images/squares/squareB.png", squareB);
				break;
			case 13:
				loadTexture("images/squares/squareRB.png", squareRB);
				break;
			}
		}
	}


	if (float(stamina * 2) / 100 == 1)			//This renders the difrent stamina states
	{
		loadTexture("images/stamina bar states/sbFull.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.95 && float(stamina) / 100 < 0.99)
	{
		loadTexture("images/stamina bar states/sb20.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.90 && float(stamina) / 100 <= 0.94)
	{
		loadTexture("images/stamina bar states/sb19.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.85 && float(stamina) / 100 <= 0.89)
	{
		loadTexture("images/stamina bar states/sb18.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.80 && float(stamina) / 100 <= 0.84)
	{
		loadTexture("images/stamina bar states/sb17.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.75 && float(stamina) / 100 <= 0.79)
	{
		loadTexture("images/stamina bar states/sb16.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.70 && float(stamina) / 100 <= 0.74)
	{
		loadTexture("images/stamina bar states/sb15.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.65 && float(stamina) / 100 <= 0.69)
	{
		loadTexture("images/stamina bar states/sb14.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.60 && float(stamina) / 100 <= 0.64)
	{
		loadTexture("images/stamina bar states/sb13.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.55 && float(stamina) / 100 <= 0.59)
	{
		loadTexture("images/stamina bar states/sb12.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.50 && float(stamina) / 100 <= 0.54)
	{
		loadTexture("images/stamina bar states/sb11.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.45 && float(stamina) / 100 <= 0.49)
	{
		loadTexture("images/stamina bar states/sb10.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.40 && float(stamina) / 100 <= 0.44)
	{
		loadTexture("images/stamina bar states/sb9.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.35 && float(stamina) / 100 <= 0.39)
	{
		loadTexture("images/stamina bar states/sb8.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.30 && float(stamina) / 100 <= 0.34)
	{
		loadTexture("images/stamina bar states/sb7.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.25 && float(stamina) / 100 <= 0.29)
	{
		loadTexture("images/stamina bar states/sb6.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.20 && float(stamina) / 100 <= 0.24)
	{
		loadTexture("images/stamina bar states/sb5.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.15 && float(stamina) / 100 <= 0.19)
	{
		loadTexture("images/stamina bar states/sb4.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.10 && float(stamina) / 100 <= 0.14)
	{
		loadTexture("images/stamina bar states/sb3.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.05 && float(stamina) / 100 <= 0.09)
	{
		loadTexture("images/stamina bar states/sb2.png", Stamina);
	}
	else if (float(stamina * 2) / 100 >= 0.01 && float(stamina) / 100 <= 0.04)
	{
		loadTexture("images/stamina bar states/sb1.png", Stamina);
	}


}