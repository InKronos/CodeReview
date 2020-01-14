#pragma once
#include "stdafx.h"


template <class T>
class LinkedList {

private:
	struct Node {
		Node* next;
		T     value;
		int	number;
		inline Node(const T& value, int number) : value(value), next(nullptr), number(number) {}
		inline Node(T&& value, int _number) : value(std::move(value)), next(nullptr), number(_number) {}
	};
	Node* root;
	Node* curr;
	int count = 0;

public:
	void add(const T& val) {
		if (this->root == nullptr) {
			this->root = new Node(val, this->count);
			this->curr = root;
		}
		else {
			this->curr->next = new Node(val, this->count);
			this->curr = this->curr->next;
		}

		this->count++;
	}

	void add(T&& val, int number) {
		if (this->root == nullptr) {
			this->root = new Node(std::move(val), number);
			this->curr = root;
		}
		else {
			this->curr->next = new Node(std::move(val), number);
			this->curr = this->curr->next;
		}

		this->count++;
	}

	void print() {
		for (Node* itr = root; itr != NULL; itr = itr->next) {
			std::cout << itr->value << endl;
		}
	}
};



