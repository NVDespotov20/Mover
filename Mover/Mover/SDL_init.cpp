#include "main.h"
SDL_Window* mWindow = NULL;		//Main window
SDL_Surface* mSurface = NULL;	//The surface of the main window
SDL_Surface* secSurface = NULL;

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
	return success;
}

bool loadMedia()
{
	bool success = 1;
	secSurface = loadSurface("images/test.png");
	if (secSurface == NULL)
	{
		cout << "Can't load image! Error: " << SDL_GetError() << endl;
		success = 0;
	}
	return success;
}


void close()
{
	SDL_FreeSurface(secSurface); //clear that surface for next use
	secSurface = NULL;

	SDL_DestroyWindow(mWindow);

	SDL_Quit();
}