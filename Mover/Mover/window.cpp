#include "main.h"
#include "objects.h"

SDL_Texture* t = NULL;
void update()
{
	SDL_RenderPresent(renderer);					//Update the window

}

bool loadBackground()
{
	bool success = 1;
	secSurface = loadSurface("images/bg.png");
	t = SDL_CreateTextureFromSurface(renderer, secSurface);
	objRect t1(0, 0, scrWidth, scrHeight);
	SDL_Rect *bRect = &t1.oRect;
	if (t == NULL)
	{
		cout << "Can't load image! Error: " << SDL_GetError() << endl;
		success = 0;
	}
	else
	{
		SDL_RenderCopy(renderer, t, NULL, &t1.oRect);
	}
	return success;
}