#pragma once
#include "stdafx.h"

List<City> getCitiesFromFile();

void mainMenu();

void draw(std::string info);

void printCities(List<City> ListOfCities);

List<Flight> getFlightsFromFile();

int** createGraph(List<Flight> list, int size);

//int getIdByName(List<City>& ListofCities, std::string& name) throw (MyException);

void bookFlight(List<City> ListOfCities, List<Flight> ListOfFlight, int** graph);