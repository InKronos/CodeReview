#include "stdafx.h"





List<City> getCitiesFromFile() {
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
	return ListofCities;
}




void mainMenu() {

}


void printCities(List<City> ListOfCities) {
	ListOfCities.PrintList();
}