#include "GameManager.h"

GameState gameState;
Grid* g;
Gui* gui;

int sx;
int sy;
int ex;
int ey;

//const int rows = 10;
int windowW = 1100;
int windowH = 900;

Tile* previousStartingPoint;
Tile* previousEndingPoint;
Button* prevClicked;


void intiGameManager() {
	gameState = GameState{ 2, 0 };
	g = new Grid(rows, 0, 0, windowH);
	gui = new Gui(900, 0, 200, 900);
	previousStartingPoint = &g->tiles[((rows - 1) / 2) - 2][(rows-1)/2];
	previousEndingPoint = &g->tiles[((rows-1)/2)+3][(rows-1)/2];
	sx = ((rows - 1) / 2) - 2;
	sy = (rows - 1) / 2;
	ex = ((rows - 1) / 2) + 3;
	ey = (rows - 1) / 2;
	previousStartingPoint->state = -1;
	previousEndingPoint->state = 0;
	prevClicked = &gui->btns[3];
	prevClicked->state = 1;
}