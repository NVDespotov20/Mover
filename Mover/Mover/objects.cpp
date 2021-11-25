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
				if (player.oRect.y != 0)
				{
					loadTexture("images/bg.png", background);
					player.oRect.y -= 64;
				}
				loadTexture("images/choveche/chovecheW.png", player);
				break;

			case SDLK_s:
				if (player.oRect.y != 576)
				{
					loadTexture("images/bg.png", background);
					player.oRect.y += 64;
				}
				loadTexture("images/choveche/chovecheS.png", player);
				break;

			case SDLK_a:
				if (player.oRect.x != 0)
				{
					loadTexture("images/bg.png", background);
					player.oRect.x -= 64;
				}
				loadTexture("images/choveche/chovecheA.png", player);
				break;

			case SDLK_d:
				if (player.oRect.x != 960)
				{
					loadTexture("images/bg.png", background);
					player.oRect.x += 64;
				}
				loadTexture("images/choveche/chovecheD.png", player);
				break;
			default:
				break;
			}
}

void level::lvl()
{
	objRect pos(0, 0, 64, 64);
	switch (lv[level_num])
	{
	case 1:
	{	
		objRect pos1(64, 64, 64, 64);
		loadTexture("images/boxes/boxR.png", pos1);

		objRect pos2(448, 320, 64, 64);
		loadTexture("images/squares/squareR.png", pos2);
	break;
	}
	default:
		objRect pos0(0, 0, 64, 64);
		break;
	}
}