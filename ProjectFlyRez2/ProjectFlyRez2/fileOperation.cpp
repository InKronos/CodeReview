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


void SynchroPersons(List<Person>& ListOfPersons) {
	std::ofstream PersonFile;
	PersonFile.open("Persons.txt", std::ios::out | std::ios::app);
	auto currentPerson = ListOfPersons.getNodeCurr();
	if (PersonFile) {
		PersonFile << currentPerson->data.getId() << " " << currentPerson->data.getName() << " " << currentPerson->data.getPassword() << std::endl;
	}
	PersonFile.close();
}

void SynchroTickiet(List<Ticket>& ListOfTickiets) {
	std::ofstream TickietsFile;
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
