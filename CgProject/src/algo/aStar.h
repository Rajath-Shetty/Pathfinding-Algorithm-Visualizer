#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED
#include "stdc++.h"
#include "../GameManager.h"
#include "GL/glut.h"


// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int> > pPair;

// A structure to hold the neccesary parameters
struct cell
{
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

// A Utility Function to check whether given cell (row, col)
// is a valid cell or not.
bool isValid(int row, int col);

// A Utility Function to check whether the given cell is
// blocked or not
bool isUnBlocked(int** grid, int row, int col);

// A Utility Function to check whether destination cell has
// been reached or not
bool isDestination(int row, int col, Pair dest);

// A Utility Function to calculate the 'h' heuristics.
double calculateHValue(int row, int col, Pair dest);

// A Utility Function to trace the path from the source
// to destination
void tracePath(cell cellDetails[][rows], Pair dest);

// A Function to find the shortest path between
// a given source cell to a destination cell according
// to A* Search Algorithm
void aStarSearch(int** grid, Pair src, Pair dest);

void aStarSearchD(int** grid, Pair src, Pair dest);

#endif
