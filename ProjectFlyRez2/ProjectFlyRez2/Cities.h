#pragma once
#include "stdafx.h"

class Tmp
{
protected:
	int id;
public:
	virtual void print() {};
	int getId() {
		return this->id;
	}
};

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

	int getSize() {
		return this->count;
	}
	//void deleteNode(T& delData);
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

