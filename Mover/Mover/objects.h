#pragma once
#include "main.h"

class objRect 
{
	int _x, _y, _w, _h;
public:
	SDL_Rect oRect;
	objRect(int x, int y, int w, int h);
	void move(SDL_Event e);
	
};

class level
{
	int lv[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // the level that is going to load
	int _x, _y, _w, _h;
	objRect pos;
public:
	void lvl();
};