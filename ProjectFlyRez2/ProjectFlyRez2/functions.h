#pragma once
#include "stdafx.h"

List<City> getCitiesFromFile();

void mainMenu();

void printCities(List<City> ListOfCities);

List<Flight> getFlightsFromFile();

int** createGraph(List<Flight> list, int size);