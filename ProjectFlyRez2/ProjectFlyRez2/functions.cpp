#include "stdafx.h"

void deleteTickiet(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets) {
	vector<int> ids = showTickiets(ListOfCities, ListOfFlight, ListOfPersons, ListOfTickiets);
	int whichToDel;
	std::cout << "Które usun¹æ? wpisz id: ";
	std::cin >> whichToDel;
	if (ids.size() == 0) {
		for (int i = 0; i < ids.size(); i++) {
			if (ids[i] == whichToDel) {
				deleteTickietById(whichToDel, ListOfTickiets);
				std::cout << std::endl << "Ok";
				return;
			}
		}
	}

	std::cout << std::endl << "wrong id";

}

vector<int> showTickiets(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets) {
	vector<int> ids;
	std::string name, password;
	std::cout << std::endl << "Your name: ";
	std::cin >> name;
	std::cout << std::endl << "Your password: ";
	std::cin >> password;
	try {
		auto person = getPerson(ListOfPersons, name, password, "print");
		auto headTickiets = ListOfTickiets.getNodeHeader();
		
		while (headTickiets != nullptr)
		{
			auto headFlights = ListOfFlight.getNodeHeader();
			if (headTickiets->data.getIdPerson() == person.getId())
			{
				while (headFlights != nullptr)
				{
					if (headTickiets->data.getIdFlight() == headFlights->data.getId()) {
						ids.push_back(headTickiets->data.getId());
						Flight flight = headFlights->data;
						std::cout << headTickiets->data.getId() << " " << getNameById(ListOfCities, flight.getLeftNode()) << "\t" << getNameById(ListOfCities, flight.getRightNode()) << "\t" << flight.getDistance() << " km" << std::endl;
					}
					headFlights = headFlights->next;
				}
			}
			headTickiets = headTickiets->next;
		}
		std::cout << "Type something: ";
		std::string info;
		std::cin >> info;
		return ids;
		
	}
	catch (exception & e) {
		std::cout << e.what() << std::endl;
		
	}
	return ids;
}




void bookFlight(List<City> &ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets, Graph graph) {
	try {
		std::string sourceStr, destinationStr;
		printCities(ListOfCities);
		std::cout <<"\nType source: ";
		std::cin >> sourceStr;
		int sourceId = getIdByName(ListOfCities, sourceStr);
		std::cout << "\nType destination: ";
		std::cin >> destinationStr;
		if (destinationStr == sourceStr) {
			throw exception("This such flight doesn't exist");
		}
		int destinationId = getIdByName(ListOfCities, destinationStr);
		
		vector<int> path = graph.shortestPath(sourceId - 1, destinationId - 1);
		List<Flight> FligthsByPath = getFlights(path, ListOfFlight);


		std::cout << "We find " << path.size() - 1 << " flight" << std::endl;
		std::cout << "\t\t \t\t Distance" << std::endl;
		PrintFlights(ListOfCities, FligthsByPath, path);
		std::cout << "Do you want book it?(y/n) ";
		std::string answer;
		std::cin >> answer;
		if (answer == "y") {
			std::string name, password;
			std::cout << "What your username: ";
			std::cin >> name;
			std:cout << "Whats your password: ";
			std::cin >> password;
			try {
				auto person = getPerson(ListOfPersons, name, password, "new");
				saveTickiet(ListOfTickiets, person, FligthsByPath);
			}
			catch (exception & e) {
				std::cout << e.what() << std::endl;
			}			
		}
	}
	catch (exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void draw(std::string info) {
	//system("CLS");
	std::cout << "\n\n \t\tWelcome To Flight Reservation System" << endl << endl;
	std::cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
	std::cout << "\t   Book your Flight tickets at affordable prices!" << endl;
	std::cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";
	std::cout << "\n \t\t" << info;
	std::cout << "\n\t\t\t\ 1.Book Flight(1) \n\t\t\t\ 2.Cancel Fight(2) \n\t\t\t\ 3.Check Ticket(3) \n\t\t\t\ 4.Exit(4)" << endl;
	std::cout << "\n\t\t Please enter your choice:";
}


void printCities(List<City> ListOfCities) {
	ListOfCities.PrintList();
}