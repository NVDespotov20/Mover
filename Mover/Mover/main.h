#pragma once					//This is our main header file containing most of our #include-s, variables, and functions 
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "objects.h"

using namespace std;

extern int grid[10][16];		//This is our grid array responsible for holding the coordinates of our objects

const int scrWidth = 1024;			//Constant screen sizes
const int scrHeight = 704;
extern SDL_Window* mWindow;		//The main window
extern SDL_Surface* mSurface;	//The surface of the main window
extern SDL_Surface* secSurface;		//A secondary surface used to load Textures
extern SDL_Renderer* renderer;		//Renderer responsible for rendering everything in the game
extern SDL_Texture* t;				//A texture


SDL_Surface* loadSurface(string path);	//A function that loads a surface from a picture


bool init();		//Used to check if the initialisation of SDL is successful

void loadTexture(string path, objRect t1);	//Changes the surface loaded by loadSurface() to a gpu accelerated texture for faster render

void update();	//Updates the current frame

void close();	//closes SDL and frees alocated memory

void grid_reset();	//Sets the grid array to zero

void render(char direction);	//Renders to the screen based on the info in the grid array

int coords(int grid);		//Multiplies the grid literal by 64 pixels

extern objRect background;	//Objects for the difrent objects
extern objRect player;
extern objRect box;
extern objRect boxY;
extern objRect boxG;
extern objRect boxT;
extern objRect boxR;
extern objRect boxB;
extern objRect squareY;
extern objRect squareG;
extern objRect squareT;
extern objRect squareR;
extern objRect squareB;
extern objRect squareRB;

extern int stamina;			//The stamina variable and object
extern objRect Stamina;

extern char direct;			// That variable is used by render() to determine which way the player is facing