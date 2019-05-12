#include <iostream>
#include "graph.h"

using namespace std;

static int visited[V];

void dfsRec(int g[][V],int u)
{
	cout << u << '\t';
	visited[u] = true;
	for(int i=0;i<V;i++)
	{
		if(g[u][i] && !visited[i])
			dfsRec(g,i);
	}
}

void dfs(int g[][V])
{
	for(int i=0;i<V;i++)
		visited[i]=0;

	cout << "visited ";
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			dfsRec(g,i);
		}
	}
	cout << endl;
}

void main()
{
	   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

	   //dfs(graph);
	   bfs(graph, V);
	return;
}
