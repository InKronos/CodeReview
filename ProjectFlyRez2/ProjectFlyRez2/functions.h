#pragma once
#include "stdafx.h"

List<City> getCitiesFromFile();

void mainMenu();

void draw(std::string info);

void printCities(List<City> ListOfCities);

List<Flight> getFlightsFromFile();

List<Person> getPersonsFromFile();

List<Ticket> getTickietsFromFile();

int** createGraph(List<Flight> list, int size);

void showTickiets(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets);
//int getIdByName(List<City>& ListofCities, std::string& name) throw (MyException);

void saveTickiet(List<Ticket> ListOfTickiets, Person person, List<Flight> ListOfFlights);

void bookFlight(List<City>& ListOfCities, List<Flight>& ListOfFlight, List<Person>& ListOfPersons, List<Ticket>& ListOfTickiets, int** graph);