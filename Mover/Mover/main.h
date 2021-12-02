#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "objects.h"

using namespace std;

//int occupied[16][10];

const int scrWidth = 1024;			//Constant screen sizes
const int scrHeight = 704;
extern SDL_Window* mWindow;		//Main window
extern SDL_Surface* mSurface;	//The surface of the main window
extern SDL_Surface* secSurface;		//A secondary surface
extern SDL_Renderer* renderer;
extern SDL_Texture* t;


SDL_Surface* loadSurface(string path);


bool init();

void loadTexture(string path, objRect t1);

void update();

void close();

void grid_reset();

int coords(int grid);

extern objRect background;
extern objRect player;
