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
				if (player.oRect.y != coords(0))
				{
					loadTexture("images/bg.png", background);
					//occupied[player.oRect.x / 64][player.oRect.y / 64] = false;
					player.oRect.y -= coords(1);
					//occupied[player.oRect.x / 64][player.oRect.y / 64] = true;
				}
				loadTexture("images/choveche/chovecheW.png", player);
				break;

			case SDLK_s:
				if (player.oRect.y != coords(9))
				{
					loadTexture("images/bg.png", background);
					player.oRect.y += coords(1);
				}
				loadTexture("images/choveche/chovecheS.png", player);
				break;

			case SDLK_a:
				if (player.oRect.x != coords(0))
				{
					loadTexture("images/bg.png", background);
					player.oRect.x -= coords(1);
				}
				loadTexture("images/choveche/chovecheA.png", player);
				break;

			case SDLK_d:
				if (player.oRect.x != coords(15))
				{
					loadTexture("images/bg.png", background);
					player.oRect.x += coords(1);
				}
				loadTexture("images/choveche/chovecheD.png", player);
				break;
			default:
				break;
			}
}

void check_empty(int x, int y)
{

}


bool lvl1()
{
	player.oRect.x = coords(1);
	player.oRect.y = coords(5);
	loadTexture("images/choveche/chovecheW.png", player);
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