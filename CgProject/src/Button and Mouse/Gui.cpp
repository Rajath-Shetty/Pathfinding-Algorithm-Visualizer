#include "Gui.h"
#include <vector>
#include <iostream>
#include "../GameManager.h"
#include "../algo/backtracking.h"
#include "../algo/aStar.h"
//#include "../algo/aStar.h"

Gui::Gui(int ax, int ay, int awinW, int awinH) {
	x = ax;
	y = ay;
	winW = awinW;
	winH = awinH;
	initGui();
}

void Gui::initGui() {
	int size = winH / 9;
	btns.push_back(Button((char*)"Starting point", x, y + size * 0, 200, size, 0, setStartingPoint));
	btns.push_back(Button((char*)"Ending Point", x, y + size * 1, 200, size, 0, setEndingPoint));
	btns.push_back(Button((char*)"Non-Traversable Path", x, y + size * 2, 200, size, 0, setNonTraversalPath));
	btns.push_back(Button((char*)"Clear Mode", x, y + size * 3, 200, size, 0, clearMode));
	btns.push_back(Button((char*)"Depth First search", x, y + size * 4, 200, size, 0, backtrackingAlgoCallback));
	btns.push_back(Button((char*)"A*", x, y + size * 5, 200, size, 0, aStar));
	btns.push_back(Button((char*)"A*with diagonals", x, y + size * 6, 200, size, 0, aStarDiagonals));
	btns.push_back(Button((char*)"Clear Grid Result", x, y + size * 7, 200, size, 0, clearResult));
	btns.push_back(Button((char*)"Reset Grid*", x, y + size * 8, 200, size, 0, clearGrid));
}

int** createGridMatrix(int height, int width)
{
	int** array2D = 0;
	array2D = new int* [height];

	for (int h = 0; h < height; h++)
	{
		array2D[h] = new int[width];

		for (int w = 0; w < width; w++)
		{
			if (g->tiles[w][h].state == -1 || g->tiles[w][h].state == 0 || g->tiles[w][h].state == 2) {
				array2D[h][w] = 1;

			}
			if (g->tiles[w][h].state == 1) {
				array2D[h][w] = 0;
			}
		}
	}
	return array2D;
}

void drawGui(Gui* gui) {
		for (Button t : gui->btns) {
			drawButton(&t);
		}
}

void setStartingPoint() {
	gameState.mapEditState = -1;
	std::cout << "The Map State Changed to :( " << gameState.mapEditState << " )Starting point"<< std::endl;
}

void setEndingPoint() {
	gameState.mapEditState = 0;
	std::cout << "The Map State Changed to :( " << gameState.mapEditState << " )Ending Point" << std::endl;
}

void setNonTraversalPath() {
	gameState.mapEditState = 1;
	std::cout << "The Map State Changed to :( " << gameState.mapEditState << " )NonTraversal" << std::endl;
}

void clearMode() {
	gameState.mapEditState = 2;
	std::cout << "The Map State Changed to :( " << gameState.mapEditState << " )clearGrid" << std::endl;
}

void clearResult() {
	for (std::vector<Tile>& v : g->tiles) {
		for (Tile& t : v) {
			t.highlighted = 5;
		}
	}
}

void backtrackingAlgoCallback(){

	int** matA=createGridMatrix(rows, rows);
	
	int visited[rows][rows];

	// initially all cells are unvisited
	memset(visited, 0, sizeof visited);

	int min_dist = INT_MAX;
	g->tiles[sx][sy].state = -1;
	g->tiles[ex][ey].state = 0;
	glutPostRedisplay();
	findShortestPath(matA, visited, sy, sx, ey,ex, min_dist, 0);


	if (min_dist != INT_MAX)
		std::cout << "The shortest path from source to destination "
		"has length " << min_dist;
	else
		std::cout << "Destination can't be reached from given source";
}

void aStar(){
	int** grid = createGridMatrix(rows, rows);
	Pair src = make_pair(sy, sx);
	Pair dest = make_pair(ey, ex);
	std::cout << sy << " " << sx;
	aStarSearch(grid, src, dest);
}



void aStarDiagonals() {
	int** grid = createGridMatrix(rows, rows);
	Pair src = make_pair(sy, sx);
	Pair dest = make_pair(ey, ex);
	std::cout << sy << " " << sx;
	aStarSearchD(grid, src, dest);
}

void clearGrid() {
	intiGameManager();
}