#include "stdafx.h"




List<City> getCitiesFromFile() {
	fstream citiesFile;
	citiesFile.open("Cities.txt");
	List<City> ListofCities;
	if (citiesFile) {
		int number;
		std::string name;
		while (citiesFile >> number >> name) {
			City city(name, number);
			ListofCities.AddNode(city);
		}
	}
	return ListofCities;
}

List<Flight> getFlightsFromFile() {
	fstream citiesFile;
	citiesFile.open("Flights.txt");
	List<Flight> ListOfFlights;
	if (citiesFile) {
		int leftnode, rightnode, distance;
		while (citiesFile >> leftnode >> rightnode >> distance) {
			Flight flight(leftnode, rightnode, distance);
			ListOfFlights.AddNode(flight);
		}
	}
	return ListOfFlights;
}


int** createGraph(List<Flight> list, int size) {
	int** graph = new int *[size];
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


void mainMenu() {

}


void printCities(List<City> ListOfCities) {
	ListOfCities.PrintList();
}