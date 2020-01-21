#pragma once
#include "stdafx.h"

int** createGraph(List<Flight> list, int size);

int minDistance(int dist[], bool sptSet[], int size);

vector<int> printPath(int parent[], int j, int source);

int* dijkstra(int** graph, int src, int size);

