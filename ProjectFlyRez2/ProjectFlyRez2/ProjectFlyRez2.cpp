#include "stdafx.h"

int main()
{
	try {
		List<City> ListofCities = getCitiesFromFile();
		List<Flight> ListofFlights = getFlightsFromFile();
		List<Person> ListofPerson = getPersonsFromFile();
		List<Ticket> ListofTickets = getTickietsFromFile();
		Graph graph = createGraph(ListofFlights, ListofCities.getSize());
		
		std::string info = "";
		vector<int> id;
		while (1)
		{
			try {
				draw(info);
				int choice;
				std::cin >> choice;
				if (choice == 4)
					break;
				else if (choice == 1)
					bookFlight(ListofCities, ListofFlights, ListofPerson, ListofTickets, graph);
				else if (choice == 2)
					deleteTickiet(ListofCities, ListofFlights, ListofPerson, ListofTickets);
				else if (choice == 3)
					id = showTickiets(ListofCities, ListofFlights, ListofPerson, ListofTickets);
				else
					throw exception("\n \t\t\terror option doesn't exist \n");
			}
			catch (exception & e) {
				info = e.what();
			}
			
		}
		std::cout << "Thank you for your visit";
		return 0;
	}
	catch (exception & e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
}

