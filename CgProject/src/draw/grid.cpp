#include "grid.h"
#include <vector>
#include <iostream>
 	
Grid::Grid(int arows, int ax, int ay, int agridSize) {
		rows = arows;
		x = ax;
		gridSize = agridSize;
		initGrid();
}
void Grid::initGrid() {
	int size = gridSize / rows;
	for (int i = 0; i < rows; i++) {
		std::vector<Tile> temp;
		for (int j = 0; j < rows; j++) {
			temp.push_back(Tile(x+size*i, y+size*j, size,  2, 0));
		}
		tiles.push_back(temp);
	}
}

void drawGrid(Grid* grid) {
	for (std::vector<Tile> &v : grid->tiles) {
		for (Tile t : v) {
			drawTile(&t);
		}
	 }
}

