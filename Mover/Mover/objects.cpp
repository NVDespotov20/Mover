#include "main.h"
#include "objects.h"

int xEmpty;
int yEmpty;
char direct = 'd';
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

void objRect::move(SDL_Event e)
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
		}
		else if(player.oRect.y != coords(1) && grid[playerY - 1][playerX] != 0)
		{
			moves('w');
		}

		break;

	case SDLK_s:
		direct = 's';
		playerX = player.oRect.x / 64;
		playerY = player.oRect.y / 64;
		if (player.oRect.y != coords(9) && grid[playerY + 1][playerX] == 0)
		{
			grid_fix_player(0);
			player.oRect.y += coords(1);
			grid_fix_player(1);
		}
		else if (player.oRect.y != coords(8) && grid[playerY + 1][playerX] != 0)
		{
			moves('s');
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
		}
		else if (player.oRect.y != coords(1) && grid[playerY][playerX - 1] != 0)
		{
			moves('a');
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
		}
		else if (player.oRect.y != coords(14) && grid[playerY][playerX + 1] != 0)
		{
			moves('d');
		}
		break;
	}
}


void moves(char direction)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (grid[i][j] != 0 && grid[i][j] != 1 && grid[i][j] != 7)
			{
				switch (direction)
				{
				case 'w':

					if (player.oRect.y != coords(1))
					{
						fix(i, j, 'w');
						grid_fix_player(0);
						player.oRect.y -= coords(1);
						grid_fix_player(1);
						boxNum(2, i - 1, j);
					}

					break;
				case 's':

					if (player.oRect.y != coords(8))
					{
						fix(i, j, 's');
						grid_fix_player(0);
						player.oRect.y += coords(1);
						grid_fix_player(1);
						boxNum(2, i + 1, j);
					}

					break;
				case 'a':

					if (player.oRect.x != coords(1))
					{
						fix(i, j, 'a');
						grid_fix_player(0);
						player.oRect.x -= coords(1);
						grid_fix_player(1);
						boxNum(2, i, j - 1);
					}

					break;
				case 'd':

					if (player.oRect.x != coords(14))
					{
						fix(i, j, 'd');
						grid_fix_player(0);
						player.oRect.x += coords(1);
						grid_fix_player(1);
						boxNum(2, i, j + 1);
					}

					break;
				}
			}
		}
	}
}

void fix(int y, int x, char direction)
{
	switch (direction)
	{
	case 'w':

		grid[y - 1][x] = grid[y][x];

		break;
	case 's':

		grid[y + 1][x] = grid[y][x];

		break;
	case 'a':

		grid[y][x - 1] = grid[y][x];

		break;
	case 'd':

		grid[y][x + 1] = grid[y][x];

		break;
	}
}

void boxNum(int num, int y, int x)
{
	switch (num)
	{
	case 2:
		box.oRect.y = coords(y);
		box.oRect.x = coords(x);
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
	grid[5][5] = 2;

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