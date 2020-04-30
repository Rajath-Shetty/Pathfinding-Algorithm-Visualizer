#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED
#include "draw/grid.h"
#include "Button and Mouse/Gui.h"

constexpr auto rows = 20;

typedef struct {
    int mapEditState;   // s=-1,e=0,w=1,c=2;
    int showGui;        //1=enable gui 0= disable gui
} GameState;

extern int sx;
extern int sy;

extern int ex;
extern int ey;

//extern const int rows;
extern int windowW;
extern int windowH;

extern GameState gameState;
extern Grid* g;
extern Gui* gui;
extern Tile* previousStartingPoint;
extern Tile* previousEndingPoint;
extern Button* prevClicked;
void intiGameManager();
#endif