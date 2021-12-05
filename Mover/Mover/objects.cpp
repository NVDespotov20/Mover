#include "main.h"
#include "objects.h"

int xEmpty;
int yEmpty;
char direct = 'd';
int boxColor;

objRect::objRect(int x, int y, int w, int h)
{
	_x = x;
	_y = y;
	_w = w;
	_h = h;
	oRect.x = _x;
	oRect.y = _y;
	oRect.w = _w;
	oRect.h = _h;
}

void objRect::move(SDL_Event e)
{	
	switch (e.key.keysym.sym)
	{
	case SDLK_w:
		direct = 'w';
		if (player.oRect.y != coords(0))
		{
			//moveObj(player.oRect.x, player.oRect.y, xEmpty, yEmpty);
			grid_fix_player(0);
			boxColor = grid_check(grid[box.oRect.y / 64][box.oRect.x / 64]);
			player.oRect.y -= coords(1);
			grid_fix_player(1);
			moves('w');
		}

		break;

	case SDLK_s:
		direct = 's';
		if (player.oRect.y != coords(9))
		{
			//moveObj(player.oRect.x, player.oRect.y, xEmpty, yEmpty);
			grid_fix_player(0);
			boxColor = grid_check(grid[box.oRect.y / 64][box.oRect.x / 64]);
			player.oRect.y += coords(1);
			grid_fix_player(1);
			moves('s');
		}
		break;

	case SDLK_a:
		direct = 'a';
		if (player.oRect.x != coords(0))
		{
			//moveObj(player.oRect.x, player.oRect.y, xEmpty, yEmpty);
			grid_fix_player(0);
			boxColor = grid_check(grid[box.oRect.y / 64][box.oRect.x / 64]);
			player.oRect.x -= coords(1);
			grid_fix_player(1);
			moves('a');
		}
		break;

	case SDLK_d:
		direct = 'd';
		if (player.oRect.x != coords(15))
		{
			//moveObj(player.oRect.x, player.oRect.y, xEmpty, yEmpty);
			grid_fix_player(0);
			boxColor = grid_check(grid[box.oRect.y / 64][box.oRect.x / 64]);
			player.oRect.x += coords(1);
			grid_fix_player(1);
			moves('d');
		}
		break;
	}
}

void moves(char direction)
{
	switch(direction)
	{
	case 'w':
		if (box.oRect.y != coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			
			grid_fix_box(0);
			box.oRect.y -= coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		else if(box.oRect.y == coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.y += coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		break;
	case 's':
		if (box.oRect.y != coords(9) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			grid_fix_box(0);
			box.oRect.y += coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		else if (box.oRect.y == coords(9) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.y -= coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		break;
	case 'a':
		if (box.oRect.x != coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			grid_fix_box(0);
			box.oRect.x -= coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		else if (box.oRect.x == coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.x += coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		break;
	case 'd':
		if (box.oRect.x != coords(15) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			grid_fix_box(0);
			box.oRect.x += coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		else if (box.oRect.x == coords(15) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.x -= coords(1);
			grid_fix_box(boxColor);
			grid_fix_player(1);
		}
		break;
	}
}

bool onSquare(objRect Box, objRect Square)
{
	bool yes = 0;
	if (Box.oRect.y == Square.oRect.y && Box.oRect.x == Square.oRect.x)
	{
		yes = 1;
	}
	return yes;
}

void grid_fix_box(int num)
{
	grid[box.oRect.y / 64][box.oRect.x / 64] = num;
}
void grid_fix_player(int num)
{
	grid[player.oRect.y / 64][player.oRect.x / 64] = num;
}

int grid_check(int check)
{
	int value = 0;
	switch (check)
	{
	case 0:
		value = 0;
		break;
	case 1:
		value = 1;
		break;
	case 2:
		value = 2;
		break;
	case 3:
		value = 3;
		break;
	case 4:
		value = 4;
		break;
	case 5:
		value = 5;
		break;
	case 6:
		value = 6;
		break;
	case 7:
		value = 7;
		break;
	case 8:
		value = 8;
		break;
	case 9:
		value = 9;
		break;
	case 10:
		value = 10;
		break;
	case 11:
		value = 11;
		break;
	case 12:
		value = 12;
		break;
	case 13:
		value = 13;
		break;
	}
	return value;
}

bool lvl1()
{
	bool complete = 0;
	player.oRect.x = coords(1);
	player.oRect.y = coords(5);

	grid[5][1] = 1;

	grid[5][5] = 5;
	grid[5][10] = 3;

	stamina = 50;
	return complete;
}
bool lvl2()
{
	bool complete = 0;
	return complete;
}
bool lvl3()
{
	bool complete = 0;
	return complete;
}
bool lvl4()
{
	bool complete = 0;
	return complete;
}
bool lvl5()
{
	bool complete = 0;
	return complete;
}
bool lvl6()
{
	bool complete = 0;
	return complete;
}
bool lvl7()
{
	bool complete = 0;
	return complete;
}
bool lvl8()
{
	bool complete = 0;
	return complete;
}
bool lvl9()
{
	bool complete = 0;
	return complete;
}
bool lvl10()
{
	bool complete = 0;
	return complete;
}