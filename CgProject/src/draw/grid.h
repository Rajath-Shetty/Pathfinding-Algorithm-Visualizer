#ifndef _GRID_H_INCLUDED
#define _GRID_H_INCLUDED

#include "tile.h"
#include <vector>

class Grid {
public:
	int rows;
	int x;
	int y;
	int gridSize;
	std::vector<std::vector<Tile>> tiles;

	Grid(int arows, int ax,int ay, int agridSize);

	void initGrid();
};
void drawGrid(Grid* grid);
#endif
