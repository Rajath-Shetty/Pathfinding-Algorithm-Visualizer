#ifndef _GUI_H_INCLUDED
#define _GUI_H_INCLUDED

#include "Button.h"
#include <vector>


class Gui {
public:
	int x;
	int y;
	int winW;
	int winH;
	std::vector<Button> btns;

	Gui(int ax, int ay, int awinW,int awinH);

	void initGui();
};
void drawGui(Gui* gui);

void setStartingPoint();

void setEndingPoint();

void setNonTraversalPath();

void clearMode();
void backtrackingAlgoCallback();
//void dummyCallback();
void clearGrid();
void clearResult();
void aStar();
void aStarDiagonals();
int** createGridMatrix(int height, int width);
#endif
