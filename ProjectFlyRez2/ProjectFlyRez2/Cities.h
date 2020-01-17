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
	
	List();
	void AddNode(const T& addData);
	void deleteNode(T& delData);
	void PrintList();
};

