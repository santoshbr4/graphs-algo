/* Author: Santosh B R (santoshbr4@gmail.com)*/
#include <iostream>
#include "graph.h"

using namespace std;

int queue[10];
int front = 0, rear = -1, empt=1;

void enqueue(int vertex)
{
	//cout << "enqueued " << vertex << endl;
	if (rear == 10)
	{
		return;
	}
	rear++;
	queue[rear] = vertex;
	empt = 0;
}

int dequeue()
{
	//cout << "dequeued " << queue[front] << " front=" << front << endl;
	if (front > rear)
	{
		front = 0;
		rear = -1;
		return -1;
	}
	else
	{
		if (front == rear)
			empt = 1;
		return queue[front++];
	}
}

int empty()
{
	return empt;
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
			cout << v << '\t';
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
