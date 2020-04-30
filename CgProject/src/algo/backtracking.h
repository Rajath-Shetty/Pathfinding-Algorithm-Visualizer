#ifndef _BFS_H_INCLUDED
#define _BFS_H_INCLUDED

#include <cstring>
#include <iostream>
#include <queue>
#include <GL/glut.h>
#include <deque>
#include "../GameManager.h"



// Check if it is possible to go to (x, y) from current position. The 
// function returns false if the cell has value 0 or already visited
bool isSafe(int** mat, int visited[rows][rows], int x, int y);

// if not a valid position, return false
bool isValidS(int x, int y);


int findShortestPath(int** mat, int visited[rows][rows], int i, int j,
	int x, int y, int& min_dist, int dist);

#endif