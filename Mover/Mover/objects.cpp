#include "main.h"
#include "objects.h"
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
				if (player.oRect.y != coords(0) && box.oRect.y != coords(0))
				{
					loadTexture("images/bg.png", background);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
					player.oRect.y -= coords(1);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					if (player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
					{
						box.oRect.y -= coords(1);
						occupied[box.oRect.y / 64][box.oRect.x / 64] = 2;

					}
				}
				else if (player.oRect.y != coords(0) && box.oRect.y == coords(0))
				{
					if (player.oRect.y != box.oRect.y && player.oRect.x != box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
						player.oRect.y -= coords(1);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					}
				}
				loadTexture("images/choveche/chovecheW.png", player);
				break;

			case SDLK_s:
				if (player.oRect.y != coords(9) && box.oRect.y != coords(9))
				{
					loadTexture("images/bg.png", background);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
					player.oRect.y += coords(1);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					if (player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						box.oRect.y += coords(1);
						occupied[box.oRect.y / 64][box.oRect.x / 64] = 2;

					}
				}
				else if (player.oRect.y != coords(9) && box.oRect.x != coords(9))
				{
					if (player.oRect.y != box.oRect.y && player.oRect.x != box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
						player.oRect.y += coords(1);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					}
				}
				loadTexture("images/choveche/chovecheS.png", player);
				break;

			case SDLK_a:
				if (player.oRect.x != coords(0) && box.oRect.x != coords(0))
				{
					loadTexture("images/bg.png", background);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
					player.oRect.x -= coords(1);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					if (player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						box.oRect.x -= coords(1);
						occupied[box.oRect.y / 64][box.oRect.x / 64] = 2;

					}
				}
				else if (player.oRect.y != coords(0) && box.oRect.y != coords(0))
				{
					if (player.oRect.y != box.oRect.y && player.oRect.x != box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
						player.oRect.x -= coords(1);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					}
				}
				loadTexture("images/choveche/chovecheA.png", player);
				break;

			case SDLK_d:
				if (player.oRect.x != coords(15) && box.oRect.x != coords(15))
				{
					loadTexture("images/bg.png", background);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
					player.oRect.x += coords(1);
					occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					if (player.oRect.y == box.oRect.y && player.oRect.x == box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						box.oRect.x += coords(1);
						occupied[box.oRect.y / 64][box.oRect.x / 64] = 2;

					}
				}
				else if (player.oRect.y != coords(15) && box.oRect.y != coords(15))
				{
					if (player.oRect.y != box.oRect.y && player.oRect.x != box.oRect.x)
					{
						loadTexture("images/bg.png", background);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 0;
						player.oRect.x += coords(1);
						occupied[player.oRect.y / 64][player.oRect.x / 64] = 1;
					}
				}
				loadTexture("images/choveche/chovecheD.png", player);
				break;
			default:
				break;
			}
}

//bool check_empty(int x, int y, char direction)


bool lvl1()
{
	player.oRect.x = coords(1);
	player.oRect.y = coords(5);
	loadTexture("images/choveche/chovecheW.png", player);
	occupied[5][1] = 1;
	loadTexture("images/boxes/boxY.png", box);
	occupied[5][5] = 2; 
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