#pragma once
#include "stdafx.h"

List<City> getCitiesFromFile();

List<Flight> getFlightsFromFile();

List<Person> getPersonsFromFile();

List<Ticket> getTickietsFromFile();

void SynchroPersons(List<Person>& ListOfPersons);

void SynchroTickiet(List<Ticket>& ListOfTickiets);


