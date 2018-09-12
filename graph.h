/* Author: Santosh B R (santoshbr4@gmail.com)*/

typedef struct adjNode_t
{
	int vertex;
	adjNode_t *next;
}adjNode;

typedef struct adjList_t
{
	adjNode *head;
}adjList;

typedef struct graph_t
{
	int v;
	int *visited;
	int *processed;
	adjList *arr;
}graph;

void bfs(graph *g);
void dfs(graph *g);
