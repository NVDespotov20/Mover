#include "main.h"
#include "objects.h"


int coords(int grid)
{
	return grid * 64;
}

int grid[10][16];

void grid_reset()
{
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			grid[i][j] = 0;
		} 
	}
}

void update()
{
	SDL_RenderPresent(renderer);					//Update the window
}

void loadTexture(string path, objRect t1)
{
	secSurface = loadSurface(path);
	SDL_Texture* t = NULL;
	t = SDL_CreateTextureFromSurface(renderer, secSurface);
	if (t == NULL)
	{
		cout << "Can't load image! Error: " << SDL_GetError() << endl;
	}
	else
	{
		SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
		SDL_RenderCopy(renderer, t, NULL, &t1.oRect);
	}
	SDL_FreeSurface(secSurface);
	SDL_DestroyTexture(t);
}