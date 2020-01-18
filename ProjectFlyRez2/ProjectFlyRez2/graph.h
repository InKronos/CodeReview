#pragma once
#include "stdafx.h"

int minDistance(int dist[], bool sptSet[], int size);

vector<int> printPath(int parent[], int j);

void printSolution(int dist[], int n, int parent[]);

int* dijkstra(int** graph, int src, int size);

