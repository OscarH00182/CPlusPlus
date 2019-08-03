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
		void insertAtEnd(int dataToAdd);
		void deleteValue(int dataToDelete);
		void printList();
		void printListBackwards();
};

void List::insertAtEnd(int dataToAdd) {

	node * newNode = new node;
	newNode->data = dataToAdd;

	if (head == NULL) {
		head = newNode;
		tail = head;
		cout << "Added new value: " << dataToAdd << " to the list!" << endl;
	}

	else {

		while (tail->next != NULL) {
				tail = tail->next;
		}

		tail->next = newNode;
		newNode->prev = tail;

		cout << "Added new value: " << dataToAdd << " to the list!" << endl;
	}

}

void List::deleteValue(int dataToDelete) {

	node * currentNode = head;
	node * followNode = head;
	if (currentNode->data == dataToDelete && currentNode == head) {
		head = currentNode->next;
		head->prev = NULL;
		delete currentNode;
	}

	else {

		while(currentNode->next != NULL && currentNode->data != dataToDelete) {
			followNode = currentNode;
			currentNode = currentNode->next;
		}

		if (currentNode->next != NULL && currentNode->data ==dataToDelete){
			followNode->next = currentNode->next;
			currentNode->next->prev = followNode;
			delete currentNode;
		}

		else if (currentNode->next == NULL && currentNode->data == dataToDelete) {
			followNode->next = NULL;
			delete currentNode;
		}

		else {
			cout << "The value you want to delete isnt in the list! " << endl;
		}
	}

}

void List::printList(){

	node * currentNode = head;
	while (currentNode != NULL) {
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}


void List::printListBackwards() {
	node * currentNode = head;

	while (currentNode != NULL) {

		if (currentNode->next == NULL) {

			tail = currentNode;

			while (tail != NULL) {
				cout << tail->data << endl;
				tail = tail->prev;

			}
		}	
		currentNode = currentNode->next;
	}
}

#endif
