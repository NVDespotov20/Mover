#include "main.h"
#include "objects.h"

int xEmpty;
int yEmpty;
char direct = 'd';
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
			grid_fix_box(2);
			grid_fix_player(1);
		}
		else if(box.oRect.y == coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.y += coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		break;
	case 's':
		if (box.oRect.y != coords(9) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			grid_fix_box(0);
			box.oRect.y += coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		else if (box.oRect.y == coords(9) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.y -= coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		break;
	case 'a':
		if (box.oRect.x != coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			grid_fix_box(0);
			box.oRect.x -= coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		else if (box.oRect.x == coords(0) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.x += coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		break;
	case 'd':
		if (box.oRect.x != coords(15) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			grid_fix_box(0);
			box.oRect.x += coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		else if (box.oRect.x == coords(15) && player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
		{
			player.oRect.x -= coords(1);
			grid_fix_box(2);
			grid_fix_player(1);
		}
		break;
	}
}

void grid_fix_box(int num)
{
	grid[box.oRect.y / 64][box.oRect.x / 64] = num;
}
void grid_fix_player(int num)
{
	grid[player.oRect.y / 64][player.oRect.x / 64] = num;
}

/*bool check_empty(int x, int y, char direction)
{
	bool empty = 1;
	if (grid[y][x] != 0 && coords(y) != coords(0) && coords(x) != coords(0) && coords(y) != coords(9) && coords(x) != coords(15))
	{
		switch (grid[y][x])
		{
		case 2:
			switch (direction)
			{
			case 'w':
				check_empty(x, y - coords(1), direction);
				break;
			case 's':
				check_empty(x, y + coords(1), direction);
				break;
			case 'a':
				check_empty(x - coords(1), y, direction);
				break;
			case 'd':
				check_empty(x + coords(1), y, direction);
				break;
			}
			break;
		case 3:
			switch (direction)
			{
			case 'w':
				check_empty(x, y - coords(1), direction);
				break;
			case 's':
				check_empty(x, y + coords(1), direction);
				break;
			case 'a':
				check_empty(x - coords(1), y, direction);
				break;
			case 'd':
				check_empty(x + coords(1), y, direction);
				break;
			}
			break;
		case 4:
			switch (direction)
			{
			case 'w':
				check_empty(x, y - coords(1), direction);
				break;
			case 's':
				check_empty(x, y + coords(1), direction);
				break;
			case 'a':
				check_empty(x - coords(1), y, direction);
				break;
			case 'd':
				check_empty(x + coords(1), y, direction);
				break;
			}
			break;
		case 5:
			switch (direction)
			{
			case 'w':
				check_empty(x, y - coords(1), direction);
				break;
			case 's':
				check_empty(x, y + coords(1), direction);
				break;
			case 'a':
				check_empty(x - coords(1), y, direction);
				break;
			case 'd':
				check_empty(x + coords(1), y, direction);
				break;
			}
			break;
		case 6:
			switch (direction)
			{
			case 'w':
				check_empty(x, y - coords(1), direction);
				break;
			case 's':
				check_empty(x, y + coords(1), direction);
				break;
			case 'a':
				check_empty(x - coords(1), y, direction);
				break;
			case 'd':
				check_empty(x + coords(1), y, direction);
				break;
			}
			break;
		}
		switch (direction)
		{
		case 'w':
			check_empty(x, y-coords(1), direction);
			break;
		case 's':
			check_empty(x, y + coords(1), direction);
			break;
		case 'a':
			check_empty(x - coords(1), y, direction);
			break;
		case 'd':
			check_empty(x + coords(1), y, direction);
			break;
		}
	}
	else if(grid[y][x] == 0 && coords(y) != coords(0) && coords(x) != coords(0) && coords(y) != coords(9) && coords(x) != coords(15))
	{
		empty = 1;
	}
	else
	{
	empty = 0;
 }

	if (empty == 1)
	{
		xEmpty = x;
		yEmpty = y;
	}
	
	return empty;
}


void moveObj(int xCur, int yCur, int xDest, int yDest)
{
	if (xCur >= 0 && xCur <= 15 && yCur >= 0 && yCur <= 9 && xDest >= 0 && xDest <= 15 && yDest >= 0 && yDest <= 9)
	{
		//if (xCur == xDest)
		//{
			if (yCur > yDest)
			{
				for (int i = yDest; i < yCur; i++)
				{
					grid[i][xCur] = grid[i + 1][xCur];
				}
			}
			else
			{
				for (int i = yDest; i > yCur; i--)
				{
					grid[i][xCur] = grid[i - 1][xCur];
				}
			}
		//}
		//else if (yCur == yDest)
		//{
			if (xCur > xDest)
			{
				for (int i = xDest; i < yCur; i++)
				{
					grid[yCur][i] = grid[yCur][i + 1];
				}
			}
			else
			{
				for (int i = xDest; i > yCur; i--)
				{
					grid[yCur][i] = grid[yCur][i - 1];
				}
			}
		//}
		grid[yCur][xCur] = 0;
	}
}*/


bool lvl1()
{
	player.oRect.x = coords(1);
	player.oRect.y = coords(5);

	grid[5][1] = 1;

	grid[5][5] = 2; 

	stamina = 50;
	return 1;
}
bool lvl2()
{
	return 1;
}
bool lvl3()
{
	return 1;
}
bool lvl4()
{
	return 1;
}
bool lvl5()
{
	return 1;
}
bool lvl6()
{
	return 1;
}
bool lvl7()
{
	return 1;
}
bool lvl8()
{
	return 1;
}
bool lvl9()
{
	return 1;
}
bool lvl10()
{
	return 1;
}