#include "stdafx.h"


int minDistance(int dist[], bool sptSet[], int size)
{
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
			

	return min_index;
}

void printPath(int parent[], int j)
{

	// Base Case : If j is source 
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	printf("%d ", j);
}


void printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	printf("Vertex\t Distance\tPath");
	for (int i = 1; i < n; i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ",src, i, dist[i], src);
		printPath(parent, i);
	}
}

void dijkstra(int **graph, int src, int size)
{

	
	int *dist = new int[size];


	bool *sptSet = new bool[size];

	
	int *parent = new int[size];

	for (int i = 0; i < size; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;

	for (int count = 0; count < size - 1; count++)
	{
		
		int u = minDistance(dist, sptSet, size);

		// Mark the picked vertex  
		// as processed 
		sptSet[u] = true;
 
		for (int v = 0; v < size; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	printSolution(dist, size, parent);
}