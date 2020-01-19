#include "stdafx.h"

int main()
{
	List<City> ListofCities = getCitiesFromFile();
	List<Flight> ListofFlights = getFlightsFromFile();
	List<Person> ListofPerson = getPersonsFromFile();
	List<Ticket> ListofTickets = getTickietsFromFile();
	int** graph = createGraph(ListofFlights, ListofCities.getSize());
	std::string info = "";
	while (1)
	{
		draw(info);
		int choice;
		std::cin >> choice;
		if (choice == 4) {
			break;
		}
		switch (choice) {
		case 1:
			bookFlight(ListofCities, ListofFlights, ListofPerson, ListofTickets, graph);
			break;
		case 2:
			
			break;
		case 3:
			showTickiets(ListofCities, ListofFlights, ListofPerson, ListofTickets);
			break;
		default:
			info = "\n \t\t\terror option doesn't exist \n";
			break;
		}
	}
	std::cout << "Thank you for your visit";
	return 0;
}

