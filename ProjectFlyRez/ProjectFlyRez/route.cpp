#include "stdafx.h"

int minDistance(int dist[], bool sptSet[], int leghtTable)
{

	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 0; v < leghtTable; v++) {
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;
	}
	return min_index;
}


void printPath(int parent[], int j)
{

	// Base Case : If j is source 
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	std::cout << j;
}


int printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	for (int i = 1; i < n; i++)
	{
		
		printPath(parent, i);
	}
}

void dijkstra(int ** graph, int src, int lenght)
{

	int* dist = new int[lenght];

	
	bool *sptSet = new bool[lenght];


	int *parent = new int[lenght];

	
	for (int i = 0; i < lenght; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	 
	dist[src] = 0;


	for (int count = 0; count < lenght - 1; count++)
	{
		
		int u = minDistance(dist, sptSet, lenght);

		// Mark the picked vertex  
		// as processed 
		sptSet[u] = true;

		
		for (int v = 0; v < lenght; v++) {
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
			
	}

	// print the constructed 
	// distance array 
	printSolution(dist, lenght, parent, );
}