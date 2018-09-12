/* Author: Santosh B R (santoshbr4@gmail.com)*/

#include <iostream>
#include <malloc.h>
#include "graph.h"

using namespace std;

adjNode *add_node(int vertex)
{
	adjNode *tmp = (adjNode *)malloc(sizeof(adjNode));
	tmp->vertex = vertex;
	tmp->next = 0;
	return tmp;
}

void add_edge(graph* g, int src, int dst)
{
	if (!g)
		return;

	adjNode *p = add_node(dst);
	p->next = g->arr[src].head;
	g->arr[src].head = p;

	//For undirected graph
	adjNode *t = add_node(src);
	t->next = g->arr[dst].head;
	g->arr[dst].head = t;
}

graph *init_graph(int vertices)
{
	graph *g = (graph *)malloc(sizeof(graph));
	g->v = vertices;

	g->arr = (adjList *)malloc(sizeof(adjList) * vertices);
	for (int i = 0; i < vertices; i++)
	{
		g->arr[i].head = 0;
	}

	g->visited = (int *)malloc(sizeof(int) * vertices);
	for (int i = 0; i < vertices; i++)
	{
		g->visited[i] = 0;
	}

	g->processed = (int *)malloc(sizeof(int) * vertices);
	for (int i = 0; i < vertices; i++)
	{
		g->processed[i] = 0;
	}

	return g;
}

void print_graph(graph *g)
{
	for (int i = 0; i < g->v; i++)
	{
		adjNode *p = g->arr[i].head;
		cout << "adj[" << i << "]";
		while (p)
		{
			cout << "->" << p->vertex;
			p = p->next;
		}
		cout << endl;
	}
}

int main()
{
	graph *g = init_graph(5);

	add_edge(g, 0, 1);
	add_edge(g, 0, 4);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 1, 4);
	add_edge(g, 2, 3);
	add_edge(g, 3, 4);

	print_graph(g);
	cout << endl;
	bfs(g);

	for (int i = 0; i < g->v; i++)
		g->visited[i] = 0;
	
	dfs(g);
	return 0;
}
