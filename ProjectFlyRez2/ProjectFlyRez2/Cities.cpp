#include "stdafx.h"


City::City(string _name, int _number) {
	this->name = _name;
	this->number = _number;
}

void City::print() {
	std::cout << this->number << ". " << this->name << std::endl;
}


Flight::Flight(int _leftnode, int _rightnode, int _distance) {
	this->leftnode = _leftnode;
	this->rightnode = _rightnode;
	this->distance = _distance;
}