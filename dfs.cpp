/* Author: Santosh B R (santoshbr4@gmail.com)*/
#include <iostream>
#include "graph.h"

using namespace std;

void dfsRec(graph *g, adjNode *n)
{
	while (n)
	{
		int vertex = n->vertex;
		if (!g->visited[vertex])
		{
			g->visited[vertex] = 1;
			cout << vertex << '\t';
			adjNode *p = g->arr[vertex].head;
			dfsRec(g, p);
		}
		n = n->next;
	}
}

void dfs(graph *g)
{
	cout << "visited ";

	for (int i = 0; i < g->v; i++)
	{
		if (!g->visited[i])
		{
			g->visited[i] = 1;
			cout << i << '\t';
			adjNode *p = g->arr[i].head;
			dfsRec(g, p);
		}
	}
}
