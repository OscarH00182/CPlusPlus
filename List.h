#ifndef LIST_H
#define LIST_H

#include "Node.h"
#pragma once

class List {

	private:
		node * head = NULL;
		node * tail = NULL;
		int size = 0;

	public:
		List();
		~List();
		void insertAtEnd(int data);
		void deleteValue(int dataToDelete);
		void printList();

		void isEmpty();
		void searchValue(int valueToSearch);
};


List::List() {}


List::~List() {}


void List::insertAtEnd(int data) {

	node * newNode = new node;
	newNode->data = data;

	if (head == NULL) {
		head = newNode;
		tail = head;
		cout << "Added new value: " << data << " to the list!" << endl;
	}

	else {
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
		cout << "Added new value: " << data << " to the list!" << endl;
	}
}


void List::deleteValue(int dataToDelete) {
	node * currentNode = head;
	node * followNode = head;

	if (currentNode->data == dataToDelete && currentNode == head) {
		head = head->next;
		delete currentNode;
	}

	else {

		while (currentNode->next != NULL) {

			if (currentNode->data == dataToDelete) {
				break;
			}
			else {
				followNode = currentNode;
				currentNode = currentNode->next;
			}
		}

		if (currentNode->next == NULL) {
			cout << "Value isn't in the list" << endl;
		}

		followNode->next = currentNode->next;
		delete currentNode;
	}
}


void List::printList() {

	node *currentNode = head;

	cout << "\n" << endl;

	while (currentNode != NULL) {
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
		size += 1;
	}
	
	cout << "The linked list has a size of: " << size << endl;
	size = 0;
}

void List::isEmpty() {

	if (head == NULL) {
		cout << "The List is Empty" << endl;
	}

	else {
		cout << "The List ISNT Empty" << endl;
	}
}

void List::searchValue(int valueToSearch) {
	node * currentNode = head;

	if (currentNode->data == valueToSearch && currentNode == head) {
		cout << "The value: " << valueToSearch << " was found at the head" << endl;
	}

	else {

		while (currentNode->next != NULL) {

			if (currentNode->data == valueToSearch) {
				cout << "The value: " << valueToSearch << " was found!" << endl;
				break;
			}

			currentNode = currentNode->next;
		
		}

		if (currentNode->next == NULL && currentNode->data == valueToSearch) {
			cout << "The value: " << valueToSearch << " was found!" << endl;
		}

		if (currentNode->next == NULL && currentNode->data != valueToSearch){
			cout << valueToSearch << " ISNT in the list!" << endl;
		}
	}
}

#endif
