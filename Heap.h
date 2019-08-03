#pragma once
#ifndef HEAP_H
#define HEAP_H

#pragma once
#include <array>
#include <iostream>
using namespace std;


class heap {

private:
	
	int heapArray[11];
	int index = 0;
	int data;
	

public:
	void peek();
	void push(int dataToAdd);
	void pop();
	void bubbleDown(int index);
	void floatUp(int dataToAdjust);
	void swap(int &index, int &parent);
	void printHeap();

};

void heap::peek() {
	cout << "The root is: " << heapArray[1] << endl;
}

void heap::push(int dataToAdd) {
	index += 1;
	heapArray[index] = dataToAdd;
	floatUp(index);
}

void heap::floatUp(int index) {
	int parent = index / 2;

	if (parent == 0) {
		parent = 1;
	}


	if (heapArray[parent] > heapArray[index]) {

		swap(heapArray[index], heapArray[parent]);

		floatUp(parent);
		
	}
}

void heap::pop() {
	cout << "Removing: " << heapArray[1] << endl;
	if (index > 2) {


		swap( heapArray[1],heapArray[index]);
		
		heapArray[index] = {};
		index -= 1;
		/*for (int i = 1; i < index; i++) {
			heapArray[i] = heapArray[i + 1];
		}
		*/
		//cout << heapArray[1]<< endl;
		bubbleDown(1);
		//heapArray[index] = heapArray[index - 1];
		/*for (int i = 1; i <= index; i++) {
			cout << heapArray[i] << endl;
		}*/
		//index -= 1;
		
		
		
		//heapArray[index] = NULL;
		
		
	}

}

void heap::bubbleDown(int index) {

	int smallest = index;
	int left = smallest * 2;
	int right = left + 1;

	//cout << left << ": "<< heapArray[left] << " " << right << ": " << heapArray[right] << endl;

	if (/*largest > left &&*/ heapArray[smallest] > heapArray[left]) {
		smallest = left;
	}

	else if (/*largest > right &&*/ heapArray[smallest] > heapArray[right]) {
		smallest = right;
	}

	if (smallest != index) {
		swap( heapArray[smallest],heapArray[index]);
		bubbleDown(smallest);
	}
	

}


void heap::swap(int &index, int &parent) {
	int temp = index;
	index = parent;
	parent = temp;
}

void heap::printHeap() {
	for (int i = 1; i <= index; i++) {
		cout << heapArray[i] << endl;
	}
	cout << "There are:  " << index << " elements in your heap" << endl;
}

#endif
