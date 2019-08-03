// SingleLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"

#include "List.h"
#include <iostream>
using namespace std;
int main()
{

	List singleLinkedList;
	singleLinkedList.isEmpty();
	singleLinkedList.insertAtEnd(5);
	singleLinkedList.insertAtEnd(10);
	singleLinkedList.insertAtEnd(15);
	singleLinkedList.insertAtEnd(20);
	singleLinkedList.printList();
	cout << endl;
	singleLinkedList.searchValue(5);
	singleLinkedList.searchValue(15);
	singleLinkedList.searchValue(20);
	singleLinkedList.searchValue(99);

	singleLinkedList.deleteValue(5);
	singleLinkedList.printList();

	singleLinkedList.deleteValue(15);
	singleLinkedList.printList();

	singleLinkedList.deleteValue(20);
	singleLinkedList.printList();

	singleLinkedList.isEmpty();
	
}
