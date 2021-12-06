#include "main.h"
#include "objects.h"

int xEmpty;
int yEmpty;
char direct = 'd';
int level;
int boxColor;
int playerX;
int playerY;

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

void objRect::move(SDL_Event e)		//This moves the player on the screen
{
	switch (e.key.keysym.sym)
	{
	case SDLK_w:;
		direct = 'w';
		playerX = player.oRect.x / 64;
		playerY = player.oRect.y / 64;
		if (player.oRect.y != coords(0) && grid[playerY - 1][playerX] == 0)
		{
			grid_fix_player(0);
			player.oRect.y -= coords(1);
			grid_fix_player(1);
			stamina -= 1;
		}
		else if (player.oRect.y != coords(0) && grid[playerY - 1][playerX] != 0)
		{
			boxColor = grid[playerY - 1][playerX];
			moves('w', playerY - 1, playerX);
		}

		break;

	case SDLK_s:;
		direct = 's';
		playerX = player.oRect.x / 64;
		playerY = player.oRect.y / 64;
		if (player.oRect.y != coords(9) && grid[playerY + 1][playerX] == 0)
		{
			grid_fix_player(0);
			player.oRect.y += coords(1);
			grid_fix_player(1);
			stamina -= 1;
		}
		else if (player.oRect.y != coords(9) && grid[playerY + 1][playerX] != 0)
		{
			boxColor = grid[playerY + 1][playerX];
			moves('s', playerY + 1, playerX);
		}

		break;

	case SDLK_a:
		direct = 'a';
		playerX = player.oRect.x / 64;
		playerY = player.oRect.y / 64;
		if (player.oRect.x != coords(0) && grid[playerY][playerX - 1] == 0)
		{
			grid_fix_player(0);
			player.oRect.x -= coords(1);
			grid_fix_player(1);
			stamina -= 1;
		}
		else if (player.oRect.x != coords(0) && grid[playerY][playerX - 1] != 0)
		{
			boxColor = grid[playerY][playerX - 1];
			moves('a', playerY, playerX - 1);
		}
		break;

	case SDLK_d:
		direct = 'd';
		playerX = player.oRect.x / 64;
		playerY = player.oRect.y / 64;
		if (player.oRect.x != coords(15) && grid[playerY][playerX + 1] == 0)
		{
			grid_fix_player(0);
			player.oRect.x += coords(1);
			grid_fix_player(1);
			stamina -= 1;
		}
		else if (player.oRect.x != coords(15) && grid[playerY][playerX + 1] != 0)
		{
			boxColor = grid[playerY][playerX + 1];
			moves('d', playerY, playerX + 1);
		}
		break;
	}
}


void moves(char direction, int y, int x)		//This moves the boxes
{
	if (grid[y][x] != 0 && grid[y][x] != 1 && grid[y][x] != 7)
	{
		switch (direction)
		{
		case 'w':

			if (player.oRect.y != coords(1))
			{
				fix(y, x, 'w');
				grid_fix_player(0);
				player.oRect.y -= coords(1);
				grid_fix_player(1);
				boxNum(boxColor, y - 1, x);
			}

			break;
		case 's':

			if (player.oRect.y != coords(8))
			{
				fix(y, x, 's');
				grid_fix_player(0);
				player.oRect.y += coords(1);
				grid_fix_player(1);
				boxNum(boxColor, y + 1, x);
			}

			break;
		case 'a':

			if (player.oRect.x != coords(1))
			{
				fix(y, x, 'a');
				grid_fix_player(0);
				player.oRect.x -= coords(1);
				grid_fix_player(1);
				boxNum(boxColor, y, x - 1);
			}

			break;
		case 'd':

			if (player.oRect.x != coords(14))
			{
				fix(y, x, 'd');
				grid_fix_player(0);
				player.oRect.x += coords(1);
				grid_fix_player(1);
				boxNum(boxColor, y, x + 1);
			}
			break;
		}
	}
}



void fix(int y, int x, char direction)
{
	switch (direction)
	{
	case 'w':

		grid[y - 1][x] = grid[y][x];
		grid[y][x] = 0;

		break;
	case 's':

		grid[y + 1][x] = grid[y][x];
		grid[y][x] = 0;


		break;
	case 'a':

		grid[y][x - 1] = grid[y][x];
		grid[y][x] = 0;


		break;
	case 'd':

		grid[y][x + 1] = grid[y][x];
		grid[y][x] = 0;


		break;
	}
}

void boxNum(int num, int y, int x)
{
	switch (num)
	{
	case 2:
		boxY.oRect.y = coords(y);
		boxY.oRect.x = coords(x);
		stamina -= 2;
		break;
	case 3:
		boxG.oRect.y = coords(y);
		boxG.oRect.x = coords(x);
		stamina -= 3;
		break;
	case 4:
		boxT.oRect.y = coords(y);
		boxT.oRect.x = coords(x);
		stamina -= 4;
		break;
	case 5:
		boxR.oRect.y = coords(y);
		boxR.oRect.x = coords(x);
		stamina -= 5;
		break;
	case 6:
		boxB.oRect.y = coords(y);
		boxB.oRect.x = coords(x);
		stamina -= 6;
		break;
	}
}

bool onSquare(int y, int x)
{
	bool yes = 0;
	switch (level)
	{
	case 1:

		if (y == 5 && x == 10)
		{
			yes = 1;
		}

		break;
	}
	return yes;
}

void grid_fix_player(int num)
{
	grid[player.oRect.y / 64][player.oRect.x / 64] = num;
}


bool lvl1()
{
	bool complete = 0;
	grid_reset();
	level = 1;			//This sets the level code


	player.oRect.x = coords(1); //This sets the player starting location on the grid and screen
	player.oRect.y = coords(5);
	grid[5][1] = 1;

	grid[5][5] = 2;				//All of the lines below set the starting location on the grid and screen for the boxes
	boxY.oRect.x = coords(5);
	boxY.oRect.y = coords(5);

	grid[5][6] = 3;
	boxG.oRect.x = coords(6);
	boxG.oRect.y = coords(5);

	grid[5][7] = 4;
	boxT.oRect.x = coords(7);
	boxT.oRect.y = coords(5);

	grid[5][8] = 5;
	boxR.oRect.x = coords(8);
	boxR.oRect.y = coords(5);

	grid[5][9] = 6;
	boxB.oRect.x = coords(9);
	boxB.oRect.y = coords(5);

	grid[5][10] = 13;			//This sets the starting location on the grid and screen for the square
	squareRB.oRect.x = coords(10);
	squareRB.oRect.y = coords(5);
	stamina = 50;			//This sets the level stamina
	if (onSquare(boxY.oRect.y, boxY.oRect.x))	//This checks if the level is completed or not
	{
		complete = 1;
	}
	return complete;
}
bool lvl2()
{
	level = 2;
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