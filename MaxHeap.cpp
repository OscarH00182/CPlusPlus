// MaxHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Heap.h"
#include <iostream>
using namespace std;
int main()
{
	heap maxHeap;
	maxHeap.push(15);
	maxHeap.push(5);
	maxHeap.push(15);
	maxHeap.push(20);
	maxHeap.push(25);
	maxHeap.push(5);
	maxHeap.push(1);
	maxHeap.push(50);
	maxHeap.push(100);
	
	maxHeap.printHeap();
	cout << endl;
	maxHeap.peek();
	cout << endl;
	maxHeap.pop();
	maxHeap.printHeap();
    
}
