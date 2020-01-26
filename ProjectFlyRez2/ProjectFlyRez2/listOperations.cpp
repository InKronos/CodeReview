#include "stdafx.h"

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


Person getPerson(List<Person>& ListOfPersons, std::string name, std::string password, std::string function) {
	auto head = ListOfPersons.getNodeHeader();
	int lastid = 0;
	while (head != nullptr) {
		Person person = head->data;
		if (person.getName() == name && person.getPassword() == password) {
			return person;
		}
		lastid = person.getId();
		head = head->next;
	}
	if (function == "print") {
		throw exception("Person is not in list");
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
			throw exception("Your answer is not yes");
		}
	}

}

int getIdByName(List<City>& ListofCities, std::string& name) {
	auto head = ListofCities.getNodeHeader();
	while (head != nullptr) {
		City city = head->data;
		if (city.getName() == name)
			return city.getId();
		head = head->next;
	}
	throw exception("This city is not in list");
}

Flight getFlight(List<Flight>& ListOfFlight, int source, int destinaion) {
	auto head = ListOfFlight.getNodeHeader();
	while (head != nullptr) {
		Flight flight = head->data;
		if ((flight.getLeftNode() == source && flight.getRightNode() == destinaion)
			|| (flight.getRightNode() == source && flight.getLeftNode() == destinaion)) {
			return flight;
		}
		head = head->next;
	}
	throw new exception("This such flight doesn't exist");
}

List<Flight> getFlights(vector<int>& path, List<Flight>& ListOfFlight) {
	List<Flight> ListOfFlightsbyPath;
	try {
		for (int i = 0; i < path.size() - 1; i++) {
			ListOfFlightsbyPath.AddNode(getFlight(ListOfFlight, path[i] + 1, path[i + 1] + 1));
		}
	}
	catch (exception & e) {
		std::cout << e.what() << std::endl;
	}


	return ListOfFlightsbyPath;
}



std::string getNameById(List<City>& ListOfCities, int id) {
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

void PrintFlights(List<City>& ListOfCities, List<Flight>& ListOfFlight, vector<int> path) {
	auto head = ListOfFlight.getNodeHeader();
	int i = 0;
	while (head != nullptr) {
		Flight flight = head->data;
		if(path[i] !=  flight.getLeftNode()	)
			std::cout << getNameById(ListOfCities, flight.getLeftNode()) << "\t" << getNameById(ListOfCities, flight.getRightNode()) << "\t" << flight.getDistance() << " km" << std::endl;
		else
			std::cout << getNameById(ListOfCities, flight.getRightNode()) << "\t" << getNameById(ListOfCities, flight.getLeftNode()) << "\t" << flight.getDistance() << " km" << std::endl;
		head = head->next;
		i++;
	}
}

