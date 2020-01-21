#include "stdafx.h"




List<City> getCitiesFromFile() {
	bool isGood = true;
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
	else
		isGood = false;
	if (ListofCities.getNodeHeader() == nullptr) 
		isGood = false;
	if (!isGood) 
		throw exception("Error can get to file");
	citiesFile.close();
	return ListofCities;
}

List<Flight> getFlightsFromFile() {
	bool isGood = true;
	fstream fightsFile;
	fightsFile.open("Flights.txt");
	List<Flight> ListOfFlights;
	if (fightsFile) {
		int id, leftnode, rightnode, distance;
		while (fightsFile >> id >> leftnode >> rightnode >> distance) {
			Flight flight(id, leftnode, rightnode, distance);
			ListOfFlights.AddNode(flight);
		}
	}
	else
		isGood = false;
	if (ListOfFlights.getNodeHeader() == nullptr)
		isGood = false;
	if (!isGood)
		throw exception("Error can get to file");
	fightsFile.close();
	return ListOfFlights;
}


List<Person> getPersonsFromFile() {
	bool isGood = true;
	fstream personsFile;
	personsFile.open("Persons.txt");
	List<Person> ListOfPersons;
	if (personsFile) {
		int id;
		std::string name, password;
		while (personsFile >> id >> name >> password) {
			Person person(id, name, password);
			ListOfPersons.AddNode(person);
		}
	}
	else
		isGood = false;
	if (!isGood)
		throw exception("Error can get to file");
	personsFile.close();
	return ListOfPersons;
}

List<Ticket> getTickietsFromFile() {
	bool isGood = true;
	fstream ticketsFile;
	ticketsFile.open("Tickiets.txt");
	List<Ticket> ListOfTickiets;
	if (ticketsFile) {
		int id, id_person, id_flight;
		while (ticketsFile >> id >> id_person >> id_flight) {
			Ticket tickiet(id, id_person, id_flight);
			ListOfTickiets.AddNode(tickiet);
		}
	}
	else
		isGood = false;
	if (!isGood)
		throw exception("Error can get to file");
	ticketsFile.close();
	return ListOfTickiets;
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
		std::cout << e.what() << std::endl;
		std::cout << e.get_info() << std::endl;
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
		std::cout << getNameById(ListOfCities, flight.getLeftNode()) << "\t" << getNameById(ListOfCities, flight.getRightNode()) << "\t" << flight.getDistance() << " km" << std::endl;
		head = head->next;
	}
}

void SynchroPersons(List<Person>& ListOfPersons) {
	std::fstream PersonFile;
	PersonFile.open("Persons.txt", std::ios::out | std::ios::app);
	auto currentPerson = ListOfPersons.getNodeCurr();
	if (PersonFile) {
		PersonFile << currentPerson->data.getId() << " " << currentPerson->data.getName() << " "<< currentPerson->data.getPassword() << std::endl;
	}
	PersonFile.close();
}

void SynchroTickiet(List<Ticket>& ListOfTickiets) {
	std::fstream TickietsFile;
	TickietsFile.open("Tickiets.txt");
	auto pTickiet = ListOfTickiets.getNodeHeader();
	if (TickietsFile) {
		while (pTickiet != nullptr)
		{
			TickietsFile << pTickiet->data.getId() << " " << pTickiet->data.getIdPerson() << " " << pTickiet->data.getIdFlight() << std::endl;
			pTickiet = pTickiet->next;
		}
	}
	TickietsFile.close();
}



Person getPerson(List<Person>& ListOfPersons, std::string name, std::string password, std::string function) throw (MyException) {
	auto head = ListOfPersons.getNodeHeader();
	int lastid = 0;
	while (head != nullptr) {
		Person person = head->data;
		if (person.getName() == name  && person.getPassword() == password) {
			return person;
		}
		lastid = person.getId();
		head = head->next;
	}
	if (function == "print") {
		throw MyException("Error person not found", "getPerson", "Person is not in list");
	}
	else {
		std::string answer;
		std::cout << "No such person in database add it (y/n): ";
		std::cin >> answer;
		if (answer == "y") {
			Person newperson(lastid + 1, name, password);
			ListOfPersons.AddNode(newperson);
			SynchroPersons(ListOfPersons);
			return newperson;
		}
		else {
			throw MyException("Error person not found", "getPerson", "Person is not in list");
		}
	}
	
}

void saveTickiet(List<Ticket> ListOfTickiets, Person person, List<Flight> ListOfFlights) {
	auto headFlights = ListOfFlights.getNodeHeader();
	auto TicketCurr = ListOfTickiets.getNodeCurr();
	int id;
	if (TicketCurr == nullptr)
		id = 1;
	else
		id = TicketCurr->data.getId();
	while (headFlights != nullptr)
	{
		ListOfTickiets.AddNode(Ticket(id, person.getId(), headFlights->data.getId()));
		headFlights = headFlights->next;
		id++;
	}
	SynchroTickiet(ListOfTickiets);
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
	catch (MyException & e) {
		std::cout << e.what() << std::endl;
		std::cout << e.get_info() << std::endl;
	}
}

void deleteTickietById(int id, List<Ticket>& ListOfTickiets) {
	auto head = ListOfTickiets.getNodeHeader();
	while (head != nullptr) {
		auto tmp = head->next;
		if (head->data.getIdFlight() == id) {
			ListOfTickiets.deleteNode(head->data);
		}
		head = tmp;
	}
	SynchroTickiet(ListOfTickiets);
}

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



void bookFlight(List<City> &ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets, int** graph) {
	try {
		int source, destination;
		std::string sourceStr, destinationStr;
		printCities(ListOfCities);
		std::cout <<"\nType source: ";
		std::cin >> sourceStr;
		source = getIdByName(ListOfCities, sourceStr);
		std::cout << "\nType destination: ";
		std::cin >> destinationStr;
		if (destinationStr == sourceStr) {
			throw MyException("Error", "getFlight", "This such flight doesn't exist");
		}

		int destinationId = getIdByName(ListOfCities, destinationStr);
		int * dijkstraArr = dijkstra(graph, source-1, ListOfCities.getSize());
		vector<int> path = printPath(dijkstraArr, destinationId - 1, source-1);
		path[0] = source - 1;
		List<Flight> FligthsByPath = getFlights(path, ListOfFlight);


		std::cout << "We find " << path.size() - 1 << " flight" << std::endl;
		std::cout << "\t\t \t\t Distance" << std::endl;
		PrintFlights(ListOfCities, FligthsByPath);
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
			catch (MyException & e) {
				std::cout << e.what() << std::endl;
				std::cout << e.get_info() << std::endl;
			}
			
		}
		

	}
	catch (MyException & e) {
		std::cout << e.what() << std::endl;
		std::cout << e.get_info() << std::endl;
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



void mainMenu() {

}


void printCities(List<City> ListOfCities) {
	ListOfCities.PrintList();
}