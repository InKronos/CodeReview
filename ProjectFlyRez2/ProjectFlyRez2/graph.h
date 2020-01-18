#pragma once
#include "stdafx.h"

int minDistance(int dist[], bool sptSet[], int size);

void printPath(int parent[], int j);

void printSolution(int dist[], int n, int parent[]);

void dijkstra(int** graph, int src, int size);

