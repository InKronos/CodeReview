#include "stdafx.h"


City::City(string _name, int _id) {
	this->name = _name;
	this->id = _id;
}

void City::print() {
	std::cout << this->id << ". " << this->name << std::endl;
}


Flight::Flight(int _id, int _leftnode, int _rightnode, int _distance) {
	this->id = _id;
	this->leftnode = _leftnode;
	this->rightnode = _rightnode;
	this->distance = _distance;
}