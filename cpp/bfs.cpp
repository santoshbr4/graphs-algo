/* Author: Santosh B R (santoshbr4@gmail.com)*/
#include <iostream>
#include "graph.h"

using namespace std;

#define QUEUE_SIZE 100
int queue[QUEUE_SIZE];
int front = -1, rear = -1, empty = 1;

void enqueue(int vertex)
{
	if (rear == QUEUE_SIZE)
	{
		return;
	}
	queue[++rear] = vertex;
	empty = 0;
}

int dequeue()
{
	if (front == rear)
	{
		front = -1;
		rear = -1;
		return -1;
	}
	else
	{
		++front;
		if (front == rear)
			empty = 1;
		return queue[front];
	}
}

int empty()
{
	return empty;
}

void bfs(graph *g)
{
	cout << "visited ";

	for(int i = 0; i < g->v; i++)
	{
		if (!g->visited[i])
		{
			g->visited[i] = 1;
			enqueue(i);
		}
		while (!empty())
		{
			int v = dequeue();
			g->processed[v] = 1;
			//cout << v << '\t';
			adjNode *p = g->arr[v].head;
			while (p)
			{
				if (!g->visited[p->vertex])
				{
					g->visited[p->vertex] = 1;
					enqueue(p->vertex);
				}
				p = p->next;
			}
		}
	}
}
