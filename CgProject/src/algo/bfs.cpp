//#include <bits/stdc++.h>
//#define M 10
//#define N 10
//using namespace std;
//
//class Node
//{
//public:
//	int x;
//	int y;
//	int dist;
//
//	Node* parent;
//
//	Node(int ax, int ay, int adist, Node* aparent)
//	{
//		x = ax;
//		y = ay;
//		dist = adist;
//		parent = aparent;
//	}
//};
//
//void printPath(Node* node)
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	printPath(node->parent);
//	std::cout << "{" << node->x << ", " << node->y << "}" << std::endl;
//}
//
//bool isValid(int** mat, bool** visited, int row, int col)
//{
//	return ((row >= 0) && (row < M) && (col >= 0) && (col < N) &&
//		(mat[row][col] == 1) && (!visited[row][col]));
//}
//
//void BFS(int** mat, int i, int j, int x, int y)
//{
//
//	int row[4] = { -1, 0, 0, 1 };
//	int col[4] = { 0, -1, 1, 0 };
//	// construct a matrix to keep track of visited cells
//	bool** visited; /*= new bool[M][N]; */
//	visited = new bool* [10];
//	for (int i = 0; i < 10; i++)
//	{
//		visited[i] = new bool[10];
//		memset(visited[i], false, sizeof(visited[i]));
//	}
//	// create an empty queue
//	std::queue<Node> q;
//
//	// mark source cell as visited and enqueue the source node
//	visited[i][j] = true;
//	q.push(Node(i, j, 0, nullptr));
//
//	// stores length of longest path from source to destination
//	int min_dist = INT_MAX;
//	// run till queue is not empty
//	Node* node = NULL;
//	while (!q.empty())
//	{
//		// pop front node from queue and process it
//		node = &(q.front());
//		q.pop();
//		// (i, j) represents current cell and dist stores its
//		// minimum distance from the source
//		i = node->x;
//		j = node->y;
//		cout << i << "----- " << j << "\n";
//		int dist = node->dist;
//		if ((i == x) && (j == y))
//		{
//			//	cout<<"dasdas";
//			min_dist = dist;
//			break;
//		}
//
//		// check for all 4 possible movements from current cell
//		// and enqueue each valid movement
//		for (int k = 0; k < 4; k++)
//		{
//			// check if it is possible to go to position
//			// (i + row[k], j + col[k]) from current position
//			if (isValid(mat, visited, i + row[k], j + col[k]))
//			{
//				//	std::cout  << ":::::::::::::::::" << std::endl;
//					// mark next cell as visited and enqueue it
//				visited[i + row[k]][j + col[k]] = true;
//				q.push(Node(i + row[k], j + col[k], dist + 1, node));
//			}
//		}
//	}
//	//std::cout<<"dasdasdas";
//	if (min_dist < INT_MAX)
//	{
//		std::cout << "The shortest path from source to destination "
//			"has length " << min_dist;
//		printPath(node);
//
//	}
//	else
//	{
//		std::cout << "Destination can't be reached from given source";
//	}
//}
//
//int main()
//{
//	int mat[M][N] = {
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
//		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
//		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
//		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
//		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
//		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
//		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
//	};
//
//	int** array2D = 0;
//	array2D = new int* [10];
//	for (int h = 0; h < 10; h++)
//	{
//		array2D[h] = new int[10];
//	}
//
//
//	for (int hs = 0; hs < 10; hs++) {
//		for (int ws = 0; ws < 10; ws++) {
//			array2D[hs][ws] = mat[hs][ws];
//
//		}
//
//	}
//
//
//	for (int hs = 0; hs < 10; hs++) {
//		for (int ws = 0; ws < 10; ws++) {
//			std::cout << array2D[hs][ws] << " ";
//		}
//		std::cout << std::endl;
//	}
//
//
//	BFS(array2D, 0, 0, 7, 5);
//	return 0;
//}
