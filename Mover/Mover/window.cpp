#include "main.h"
#include "objects.h"


int coords(int grid)
{
	return grid * 64;
}

int grid[10][16];

void grid_reset()	//Resets the grid
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
	SDL_RenderPresent(renderer);					//Update the frame
}

void loadTexture(string path, objRect t1)		
{
	secSurface = loadSurface(path);	//loads a picture
	SDL_Texture* t = NULL;
	t = SDL_CreateTextureFromSurface(renderer, secSurface);	//Changes the loaded surface to a GPU accelerated texture
	if (t == NULL)
	{
		cout << "Can't load image! Error: " << SDL_GetError() << endl;
	}
	else
	{
		SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);	//Sets the blend mode
		SDL_RenderCopy(renderer, t, NULL, &t1.oRect);	//loads the texture with the renderer to be shown in the next frame
	}
	SDL_FreeSurface(secSurface);	//Frees the surface for future uses
	SDL_DestroyTexture(t);			//Frees the Texture for future uses
}