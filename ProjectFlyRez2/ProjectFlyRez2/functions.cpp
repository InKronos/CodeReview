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
		int id, leftnode, rightnode, distance;
		while (citiesFile >> id >> leftnode >> rightnode >> distance) {
			Flight flight(id, leftnode, rightnode, distance);
			ListOfFlights.AddNode(flight);
		}
	}
	return ListOfFlights;
}

int getIdByName(List<City> &ListofCities, std::string &name) throw (MyException){
	auto head = ListofCities.getNodeHeader();
	while (head != nullptr) {
		City city = head->data;
		if (city.getName() == name) 
			return city.getId();
		head = head->next;
	}
	throw MyException("Error", "getIdByName", "This city is not in list");
}

Flight getFlight(List<Flight> &ListOfFlight, int source, int destinaion) throw (MyException) {
	auto head = ListOfFlight.getNodeHeader();
	while (head != nullptr) {
		Flight flight = head->data;
		if ((flight.getLeftNode() == source && flight.getRightNode() == destinaion)
			|| (flight.getRightNode() == source && flight.getLeftNode() == destinaion)) {
			return flight;
		}
		head = head->next;
	}
	throw MyException("Error", "getFlight", "This such flight doesn't exist");
}

List<Flight> getFlights(vector<int> &path, List<Flight> &ListOfFlight) {
	List<Flight> ListOfFlightsbyPath;
	try {
		for(int i = 0; i < path.size()-1;i++) {
			ListOfFlightsbyPath.AddNode(getFlight(ListOfFlight, path[i] + 1, path[i + 1] + 1));
		}
	}
	catch (MyException & e) {
		e.what();
		e.get_info();
	}
	

	return ListOfFlightsbyPath;
}

std::string getNameById(List<City> &ListOfCities, int id) {
	std::string name = "";
	auto head = ListOfCities.getNodeHeader();
	while (head != nullptr) {
		City city = head->data;
		if (city.getId() == id) {
			name = city.getName();
			break;
		}
		head = head->next;
	}
	return name;
}

void PrintFlights(List<City> &ListOfCities, List<Flight> &ListOfFlight) {
	auto head = ListOfFlight.getNodeHeader();
	while (head != nullptr) {
		Flight flight = head->data;
		std::cout << getNameById(ListOfCities, flight.getLeftNode()) << " " << getNameById(ListOfCities, flight.getRightNode()) << " " << flight.getDistance();
		head = head->next;
	}
}

void bookFlight(List<City> ListOfCities, List<Flight> ListOfFlight, int** graph) {
	try {
		int source, destination;
		std::string sourceStr, destinationStr;
		printCities(ListOfCities);
		std::cout <<"\nType source: ";
		std::cin >> sourceStr;
		source = getIdByName(ListOfCities, sourceStr);
		std::cout << "\nType destination: ";
		std::cin >> destinationStr;
		destination = getIdByName(ListOfCities, destinationStr);
		int * dijkstraArr = dijkstra(graph, source-1, ListOfCities.getSize());
		vector<int> path = printPath(dijkstraArr, destination - 1);

		path[0] = source - 1;
		List<Flight> FligthsByPath = getFlights(path, ListOfFlight);
		PrintFlights(ListOfCities, FligthsByPath);
		int a;
		std::cin >> a;

	}
	catch (MyException & e) {
		e.what();
		e.get_info();
	}
}

void draw(std::string info) {
	system("CLS");
	std::cout << "\n\n \t\tWelcome To Flight Reservation System" << endl << endl;
	std::cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
	std::cout << "\t   Book your Flight tickets at affordable prices!" << endl;
	std::cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";
	std::cout << "\n \t\t" << info;
	std::cout << "\n\t\t\t\ 1.Book Flight(1) \n\t\t\t\ 2.Cancel Fight(2) \n\t\t\t\ 3.Check Ticket(3) \n\t\t\t\ 4.Exit(4)" << endl;
	std::cout << "\n\t\t Please enter your choice:";
}



void mainMenu() {

}


void printCities(List<City> ListOfCities) {
	ListOfCities.PrintList();
}