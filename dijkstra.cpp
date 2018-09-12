#include <iostream>

using namespace std;

#define INFINITY 1000000
#define MAX_V 100

int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

int V=0;

int findMinKey(bool spt[], int dist[])
{
	int minIndex = -1;
	int minKey = INFINITY;

	for(int i =0; i<V;i++)
	{
		if(!spt[i] && dist[i] < minKey)
		{
			minIndex = i;
			minKey = dist[i];
		}
	}
	return minIndex;
}

void printSPT(int dist[], int parent[])
{
	cout << "edge" << '\t' << "weight" << endl;
	for(int i=1;i<V;i++)
	{
		cout << parent[i] << "->" << i << '\t' << dist[i] << endl;
	}
}

void dijkstra()
{
	bool spt[MAX_V] = {false,};
	int dist[MAX_V];
	int parent[MAX_V];

	for(int i=0;i<V;i++)
	{
		spt[i] = false;
		dist[i]=1000000;
		parent[i]=-1;
	}

	dist[0]=0;
	parent[0]=-1;

	for(int l=0;l<V-1;l++)
	{
		int u = findMinKey(spt,dist);
		spt[u] = true;

		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && !spt[v] && ((graph[u][v]+dist[u]) < dist[v]))
			{
				dist[v] = graph[u][v]+dist[u];
				parent[v]=u;
			}
		}
	}

	printSPT(dist,parent);
}

int main()
{
	V=9;

	dijkstra();
	return 0;
}
