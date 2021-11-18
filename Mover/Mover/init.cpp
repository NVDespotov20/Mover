#include "main.h"
SDL_Window* mWindow = NULL;		//Main window
SDL_Surface* mSurface = NULL;	//The surface of the main window
SDL_Surface* secSurface = NULL;
SDL_Renderer* mRenderer = NULL;

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
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer == NULL)
			{
				cout << "Error renderer! Error: " << SDL_GetError() << endl;
			}
			else
			{
				SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
				
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
	SDL_FreeSurface(secSurface); //clear that surface for next use
	secSurface = NULL;
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);

	SDL_Quit();
}