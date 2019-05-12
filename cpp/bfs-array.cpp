#include <iostream>
#include "graph.h"

using namespace std;

int q[MAX];
int visited[V];

int front=-1,rear=-1;

bool isEmpty()
{
	if(front == rear)
		return true;
	else
		return false;
}

void addQ(int node)
{
	q[++front] = node;
}

int popQ()
{
	return q[++rear];
}

void bfs(int arr[][V], int size)
{
	for(int i=0;i<size;i++)
	{
		visited[V] = 0;
	}

	addQ(0);
	cout << "visited ";
	while(!isEmpty())
	{
		int src = popQ();
		
		if(!visited[src])
		{
			visited[src] = 1;
	
			cout << src << "->";
			for(int i=0; i<size; i++)
			{
				int dst = arr[src][i];
				if(dst && !visited[i])
					addQ(i);
			}
		}
	}
}
