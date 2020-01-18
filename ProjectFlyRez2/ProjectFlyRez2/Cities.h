#pragma once
#include "stdafx.h"

class T
{
public:
	virtual void print() {};
};

class City : T
{
	std::string name;
	int number;
public:
	City(string _name, int _number);
	void print();
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

