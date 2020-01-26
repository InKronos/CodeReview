#include "stdafx.h"
# define INF 0x3f3f3f3f
Graph::Graph(int _nrOfVertices) {
	this->nrOfVertices = _nrOfVertices;
	listForGraph = new std::list<std::pair<int, int>>[_nrOfVertices];
}

void Graph::addEdge(int _sideOne, int _sideTwo, int weight) {
	listForGraph[_sideOne].push_back(std::make_pair(_sideTwo, weight));
	listForGraph[_sideTwo].push_back(std::make_pair(_sideOne, weight));
}

vector<int> Graph::shortestPath(int source, int destination) {
	// Create a set to store vertices that are being 
	// prerocessed 
	std::set< pair<int, int> > setds;

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(this->nrOfVertices, INF);

	// Insert source itself in Set and initialize its 
	// distance as 0. 
	setds.insert(make_pair(0, source));
	dist[source] = 0;
	int* parent = new int[this->nrOfVertices];
	/* Looping till all shortest distance are finalized
	   then setds will become empty */
	while (!setds.empty())
	{
		// The first vertex in Set is the minimum distance 
		// vertex, extract it from set. 
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = tmp.second;
		//vector<int> parent;
		// 'i' is used to get all adjacent vertices of a vertex 
		list< pair<int, int> >::iterator i;
		for (i = this->listForGraph[u].begin(); i != listForGraph[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first;
			int weight = (*i).second;

			//  If there is shorter path to v through u. 
			if (dist[v] > dist[u] + weight)
			{
				/*  If distance of v is not INF then it must be in
					our set, so removing it and inserting again
					with updated less distance.
					Note : We extract only those vertices from Set
					for which distance is finalized. So for them,
					we would never reach here.  */
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));

				// Updating distance of v 
				dist[v] = dist[u] + weight;
				parent[v] = u;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

	
	vector<int> path;
	int k = destination;
	while (k != source) {
		path.push_back(k);
		k = parent[k];
	}
	path.push_back(source);
	std::reverse(path.begin(), path.end());
	return path;
}