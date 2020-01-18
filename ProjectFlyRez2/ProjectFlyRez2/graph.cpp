#include "stdafx.h"

int** createGraph(List<Flight> list, int size) {
	int** graph = new int* [size];
	for (int i = 0; i < size; i++) {
		graph[i] = new int[size];
		for (int j = 0; j < size; j++) {
			graph[i][j] = 0;
		}
	}

	auto head = list.getNodeHeader();
	auto p = head;
	while (p->next != nullptr)
	{
		Flight flight = p->data;
		int left = flight.getLeftNode() - 1;
		int right = flight.getRightNode() - 1;
		int distance = flight.getDistance();
		graph[left][right] = distance;
		graph[right][left] = distance;
		p = p->next;
	}
	return graph;
}

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

vector<int> printPath(int parent[], int j, int source)
{

	// Base Case : If j is source 
	vector<int> arrayOfNodes;
	int k = j;
	int count = 0;
	do{
		arrayOfNodes.push_back(k);
		k = parent[k];
		count++;
	} while (k != source);
	arrayOfNodes.push_back(0);
	std::reverse(arrayOfNodes.begin(), arrayOfNodes.end());

	return arrayOfNodes;
}



int* dijkstra(int **graph, int src, int size)
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

	return parent;
}