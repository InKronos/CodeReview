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


template <class T>
class List {
private:
	struct node {
		T data;
		node* next;

		inline node(const T& data) : data(data), next(nullptr) {}
	};
	typedef struct node* nodePtr;
	nodePtr head;
	nodePtr curr;
	int count;

public:
	
	List() {
		this->head = nullptr;
		this->curr = this->head;
		this->count = 0;
	}
	void AddNode(const T& addData) {
		if (this->head == nullptr) {
			this->head = new node(addData);
			this->curr = this->head;
		}
		else {
			this->curr->next = new node(addData);
			this->curr = this->curr->next;
		}
		this->count++;
	}
	node* getNodeHeader() {
		return this->head;
	}

	node* getNodeCurr() {
		return this->curr;
	}

	int getSize() {
		return this->count;
	}
	void deleteNode(T& delData) {
		node* tmp = this->head;
		if (tmp->data.getId() == delData.getId()) {
			this->head = tmp->next;
			delete tmp;
		}
		else {
			while (tmp->next != nullptr) {
				if (tmp->next->data.getId() == delData.getId()) {
					if (tmp->next->next != nullptr) {
						node* nextToDel = tmp->next->next;
						delete tmp->next;
						tmp->next = nextToDel;
					}
					else {
						delete tmp->next;
						tmp->next = nullptr;
					}
					
				}
			}
		}
	}
	void PrintList() {
		node* tmp = this->head;
		while (tmp != nullptr)
		{
			tmp->data.print();
			tmp = tmp->next;
		}
		std::cout << this->count;
	}
};

