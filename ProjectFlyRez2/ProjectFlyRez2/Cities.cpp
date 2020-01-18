#include "stdafx.h"


City::City(string _name, int _number) {
	this->name = _name;
	this->number = _number;
}

void City::print() {
	std::cout << this->number << ". " << this->name << std::endl;
}
/*
template <class T>
List<class T>::List() {
	this->head = nullptr;
	this->curr = this->head;
	this->count = 0;
}

template <class T>
void List<class T>::AddNode(const T & addData) {
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

template <class T>
void List<class T>::PrintList() {
	node* tmp = this->head;
	while (tmp != nullptr)
	{
		tmp->data.print();
	}
}
*/

