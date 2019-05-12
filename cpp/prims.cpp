#include <iostream>

using namespace std;

#define INFINITY 1000000
#define MAX_V 100

int graph[5][5] = {{0, 2, 0, 6, 0},
                   {2, 0, 3, 8, 5},
                   {0, 3, 0, 0, 7},
                   {6, 8, 0, 0, 9},
                   {0, 5, 7, 9, 0},
};
int V=0;

int findMinKey(bool mst[], int key[])
{
	int minIndex = -1;
	int minKey = INFINITY;

	for(int i =0; i<V;i++)
	{
		if(!mst[i] && key[i] < minKey)
		{
			minIndex = i;
			minKey = key[i];
		}
	}
	return minIndex;
}

void printMST(bool mst[], int key[], int parent[])
{
	cout << "edge" << '\t' << "weight" << endl;
	for(int i=1;i<V;i++)
	{
		cout << parent[i] << "->" << i << '\t' << key[i] << endl;
	}
	cout << "MST -> ";
	for(int i=0;i<V;i++)
	{
		if(mst[i])
			cout << "1 ";
		else
			cout << "0 ";
	}	
	cout << endl;
}

void prim()
{
	bool mst[MAX_V] = {false,};
	int key[MAX_V];
	int parent[MAX_V];

	for(int i=0;i<V;i++)
	{
		mst[i] = false;
		key[i]=1000000;
		parent[i]=-1;
	}

	key[0]=0;
	parent[0]=-1;

	for(int l=0;l<V-1;l++)
	{
		int u = findMinKey(mst,key);
		mst[u] = true;

		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && !mst[v] && graph[u][v] < key[v])
			{
				key[v] = graph[u][v];
				parent[v]=u;
			}
		}
		printMST(mst, key, parent);
	}

	printMST(mst, key, parent);
}

int main()
{
	V=5;

	prim();
	return 0;
}
