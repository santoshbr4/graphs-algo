/* Author Santosh B R (santoshbr4@gmail.com)
** Solution for grid problem in Spoj -> http://www.spoj.com/problems/GRID/
*/

#include <iostream>

using namespace std;

int visited[1000][1000];
unsigned long routes;

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

typedef struct node_t
{
	int x;
	int y;
}node;

node q[1000000]; //Sufficiently large BFS queue

int front = -1, rear = -1;
int m, n;
unsigned long K;

bool isEmpty()
{
	if (front != rear)
		return false;
	else
		return true;
}

bool isValid(int x, int y)
{
	if (x > m || y > n || x < 0 || y < 0)
		return false;
	else
		return true;
}

int find_all_paths()
{
	routes = 0;
	rear = -1;
	front = -1;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}

	//BFS
	node beg;
	beg.x = 0;
	beg.y = 0;

	q[++rear] = beg;

	while (!isEmpty())
	{
		node ele = q[++front];
		visited[ele.x][ele.y] = true;

		for (int i = 0; i < 2; i++)
		{
			int X = ele.x + dx[i];
			int Y = ele.y + dy[i];
			if (isValid(X, Y) && !visited[X][Y])
			{
				if (X == m && Y == n)
				{
					//cout << " Found a route " << endl;
					routes++;
				}
				else
				{
					node tmp = { X, Y };
					q[++rear] = tmp;
				}
			}
		}
	}

	return routes%K;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int T = 0;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> m;
		cin >> n;
		cin >> K;

		int result = find_all_paths();
		cout << result << endl;
	}

	return 0;
}
