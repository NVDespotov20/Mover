#pragma once
#include "main.h"

extern int xEmpty;
extern int yEmpty;


class objRect 
{
	int _x, _y, _w, _h;
public:
	SDL_Rect oRect;
	objRect(int x, int y, int w, int h);
	void move(SDL_Event e);
	
};


bool check_empty(int x, int y, char direction);
void moveObj(int xCur,int yCur, int xDest, int yDest);
void moves(char direction);
void grid_fix_box(int num);
void grid_fix_player(int num);

bool lvl1();
bool lvl2();
bool lvl3();
bool lvl4();
bool lvl5();
bool lvl6();
bool lvl7();
bool lvl8();
bool lvl9();
bool lvl10();