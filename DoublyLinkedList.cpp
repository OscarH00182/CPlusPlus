// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "List.h"

#include <iostream>
using namespace std;
int main()
{
	List doublyLinkList;
	doublyLinkList.insertAtEnd(5);
	doublyLinkList.insertAtEnd(10);
	doublyLinkList.insertAtEnd(15);
	doublyLinkList.insertAtEnd(20);

	cout << endl;
	doublyLinkList.printList();

	cout << endl;
	doublyLinkList.printListBackwards();

	cout << endl;
	doublyLinkList.deleteValue(5);
	doublyLinkList.printListBackwards();

	cout << endl;
	doublyLinkList.deleteValue(15);
	doublyLinkList.printListBackwards();

	cout << endl;
	doublyLinkList.deleteValue(20);
	doublyLinkList.printListBackwards();

	return 0;
}
