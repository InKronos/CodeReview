#pragma once
#include "stdafx.h"

class Graph
{
	int nrOfVertices;
public:

	std::list<std::pair<int, int>>* listForGraph;

	Graph(int _nrOfVertices);  // Constructor 

   // function to add an edge to graph 
	void addEdge(int _sideOne, int _sideTwo, int weight);

	// prints shortest path from s 
	vector<int> shortestPath(int source, int destination);
};