#include "stdafx.h"

Graph createGraph(List<Flight> listOfFlights, int size) {
	Graph graph(size);
	auto headOfFlights = listOfFlights.getNodeHeader();
	while (headOfFlights != nullptr) {
		graph.addEdge(headOfFlights->data.getLeftNode() - 1, headOfFlights->data.getRightNode() - 1, headOfFlights->data.getDistance());
		headOfFlights = headOfFlights->next;
	}

	return graph;
}