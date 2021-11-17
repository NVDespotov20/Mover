#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int scrWidth = 1280;			//Constant screen sizes
const int scrHeight = 720;
extern SDL_Window* mWindow;		//Main window
extern SDL_Surface* mSurface;	//The surface of the main window
extern SDL_Surface* secSurface;		//A secondary surface


SDL_Surface* loadSurface(string path);

bool init();

bool loadMedia();

void close();