// MinHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Heap.h"
#include <iostream>
using namespace std;

int main()
{
	heap minHeap;
	minHeap.push(55);
	minHeap.push(50);
	minHeap.push(85);
	minHeap.push(75);
	minHeap.push(35);
	
	minHeap.peek();
	minHeap.printHeap();
	minHeap.pop();
	minHeap.printHeap();
	const int size = 5;

	int bsarray[size];
	for (int i = 0; i < size; i++) {
		bsarray[i] = i;
	}
	for (int i = 0; i < size; i++) {
		cout << bsarray[i] << endl;
	}
	bsarray[4] = { };
	cout << bsarray[4]<<endl;
	//cout << bsarray[4];
	
	cout << endl;
	for (int i = 1; i < 5; i++) {
		cout << i << endl;
	}
}
