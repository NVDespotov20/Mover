#include "main.h"

void update()
{

	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = scrWidth;
	stretchRect.h = scrHeight;
	SDL_BlitScaled(secSurface, NULL, mSurface, &stretchRect);
	SDL_UpdateWindowSurface(mWindow);						//Update the window

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