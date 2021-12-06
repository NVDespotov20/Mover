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

bool onSquare(objRect Box, objRect Square);
void moves(char direction);
void grid_fix_box(int num);
void grid_fix_player(int num);
void boxNum(int num, int y, int x);
void fix(int y, int x, char direction);

int grid_check(int check);
extern int boxColor;
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