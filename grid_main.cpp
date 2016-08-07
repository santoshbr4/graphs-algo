/* Author Santosh B R (santoshbr4@gmail.com)
** Solution for grid problem in Spoj -> http://www.spoj.com/problems/GRID/
*/

#include <iostream>

using namespace std;

int q[1000000]; //Sufficiently large BFS queue
int visited[1000][1000];
int arr[1000];

int front = -1, rear = -1;

bool isEmpty()
{
	if (front != rear)
		return true;
	else
		return false;
}

int find_all_paths()
{
	int result = 0;

	//BFS
	q[++rear];
	while (!isEmpty())
	{
		int ele = q[++front];
		
	}

	return result;
}

int main()
{

	return 0;
}