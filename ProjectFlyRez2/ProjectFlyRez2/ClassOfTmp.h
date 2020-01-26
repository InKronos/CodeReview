#pragma once
#include "stdafx.h"


class City : public Tmp
{
	std::string name;
public:
	City(string _name, int _id);
	std::string getName() {
		return this->name;
	}
	void print();
};


class Flight : public Tmp
{
	int leftnode;
	int rightnode;
	int distance;
public:
	Flight(int _id, int _leftnode, int _rightnode, int _distance);
	int getLeftNode() {
		return this->leftnode;
	}
	int getRightNode() {
		return this->rightnode;
	}
	int getDistance() {
		return this->distance;
	}

};


class Person :
	public Tmp
{
	std::string name, password;
public:
	Person(int _id, std::string _name, std::string _password);
	std::string getName() {
		return this->name;
	}
	std::string getPassword() {
		return this->password;
	}
};

class Ticket :
	public Tmp
{
	int id_person, id_flight;
public:
	Ticket(int _id, int _id_person, int _id_flight);
	int getIdPerson() {
		return this->id_person;
	}
	int getIdFlight() {
		return this->id_flight;
	}
};


