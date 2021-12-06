#pragma once
#include "main.h"

class objRect				//This is our object class containing the x and y possision and the width and height of the object
{
	int _x, _y, _w, _h;
public:
	SDL_Rect oRect;
	objRect(int x, int y, int w, int h);
	void move(SDL_Event e);
	
};

bool onSquare(int y, int x);	//checks if a box is on a square

void moves(char direction, int y, int x);	//moves boxes that came in contact with the player

void grid_fix_player(int num);	//Fixes the posision of the player in the grid array

void boxNum(int num, int y, int x);	//updates the object Rect x and y pos
extern int boxColor; //The color code of the box

void fix(int y, int x, char direction);	//Fixes the posision of boxes in the grid array




bool lvl1();		//fuctions that initialise the levels
bool lvl2();
bool lvl3();
bool lvl4();
bool lvl5();
bool lvl6();
bool lvl7();
bool lvl8();
bool lvl9();
bool lvl10();