#pragma once
#include "stdafx.h"

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

