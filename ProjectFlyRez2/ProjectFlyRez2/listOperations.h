#pragma once
#include "stdafx.h"

void printCities(List<City> ListOfCities);

void saveTickiet(List<Ticket> ListOfTickiets, Person person, List<Flight> ListOfFlights);

void deleteTickietById(int id, List<Ticket>& ListOfTickiets);

Person getPerson(List<Person>& ListOfPersons, std::string name, std::string password, std::string function);

void PrintFlights(List<City>& ListOfCities, List<Flight>& ListOfFlight, vector<int> path);

int getIdByName(List<City>& ListofCities, std::string& name);

Flight getFlight(List<Flight>& ListOfFlight, int source, int destinaion);

List<Flight> getFlights(vector<int>& path, List<Flight>& ListOfFlight);

std::string getNameById(List<City>& ListOfCities, int id);
