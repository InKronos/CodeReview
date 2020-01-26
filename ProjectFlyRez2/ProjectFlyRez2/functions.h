#pragma once
#include "stdafx.h"

void draw(std::string info);

void deleteTickiet(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets);

vector<int> showTickiets(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets);

void bookFlight(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets, Graph graph);