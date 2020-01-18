#include "stdafx.h"

int main()
{
	List<City> ListofCities = getCitiesFromFile();
	printCities(ListofCities);
	List<Flight> ListofFlights = getFlightsFromFile();
	int** graph = createGraph(ListofFlights, ListofCities.getSize());
	dijkstra(graph, 0, ListofCities.getSize());
}

