	#include "backtracking.h" 
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;


// Check if it is possible to go to (x, y) from current position. The 
// function returns false if the cell has value 0 or already visited
bool isSafe(int** mat, int visited[rows][rows], int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return false;
	
	return true;
}

// if not a valid position, return false
bool isValidS(int x, int y)
{
	if (x < rows && y < rows && x >= 0 && y >= 0)
		return true;

	return false;
}

// Find Shortest Possible Route in a Matrix mat from source cell (0, 0) 
// to destination cell (x, y)
// min_dist is passed by reference and stores length of longest path 
// from source to destination found so far dist maintains length of 
// path from source cell to current cell (i, j)
int findShortestPath(int** mat, int visited[rows][rows], int i, int j,
	int x, int y, int& min_dist, int dist)
{
	int xs = 0;
	// if destination is found, update min_dist
	if (i == x && j == y)
	{

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				std::cout << visited[i][j]<<" ";
				if (visited[i][j]) {
					g->tiles[j][i].highlighted = -2;
					glutPostRedisplay();
				}
			}
			std::cout << std::endl;
		}
		min_dist = min(dist, min_dist);
		 return 1;
	}

	// set (i, j) cell as visited
	visited[i][j] = 1;
	g->tiles[j][i].highlighted = -1;
	glutPostRedisplay();


	// go to bottom cell
	if (isValidS(i + 1, j) && isSafe(mat, visited, i + 1, j))
	
		 xs= findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
	//if (xs)
	//	return 1;

	// go to left cell
	if (isValidS(i, j - 1) && isSafe(mat, visited, i, j - 1))
		 xs = findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
	//if (xs)
	//	return 1;
		
	// go to right cell		 
	if (isValidS(i, j + 1) && isSafe(mat, visited, i, j + 1))
		xs=findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);

	//if (xs)
	//	return 1;
	// go to top cell
	if (isValidS(i - 1, j) && isSafe(mat, visited, i - 1, j))
		xs =findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
	//if (xs)
	//	return 1;
	// Backtrack - Remove (i, j) from visited matrix
	visited[i][j] = 0;

}



