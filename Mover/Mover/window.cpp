#include "main.h"

void update()
{
	SDL_Rect mRect;
	mRect.x = 0;
	mRect.y = 0;
	mRect.w = scrWidth;
	mRect.h = scrHeight;
	SDL_BlitScaled(secSurface, NULL, mSurface, &mRect);
	SDL_UpdateWindowSurface(mWindow);						//Update the window

}

bool loadMedia()
{
	bool success = 1;
	secSurface = loadSurface("images/bg.png");
	if (secSurface == NULL)
	{
		cout << "Can't load image! Error: " << SDL_GetError() << endl;
		success = 0;
	}
	return success;
}