// PointersInGeneral.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
using namespace std;

void passByValue(int x);
void passByRefrence(int * x);

int main()
{
	//char: 1 byte
	//int: 4 bytes
	//float: 4 byte
	//double: 8 bytes
	//sizeof(): Gives us byte of value

	//The pointer DOESNT hold a value in the traditional sense; 
	//INSTEAD it holds the address of another variable. 
	//A pointer "points to" that other variable by holding a copy of its address. 
	//Because a pointer holds an address rather than a value, it has two parts.

	// &: Address of, 
	// *: Get value of,	Dereferencing

	int a = 5;
	//int * b = a; WONT WORK, because it would hold 5
	int * b = &a;//WORKS, because its holding the address of " a "
	int c = *b;//GETS VALUE, of ADDRESS, pointed by b

	cout << "A: " << a << endl;
	cout << "*B: " << b << endl; //Address of " a "
	cout << "C: " << c << endl; //Value of a
	
	int randomArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };//Since int, 4 bits between index

	int *pLocation6 = &randomArray[6];//Holds address of index 6
	int *pLocation0 = &randomArray[0];//Holds address of index 0
	int difference = pLocation6 - pLocation0;//Gets difference of addresses
	//1 Difference = 4 bits 

	cout << "\npLocation6: " << (int)pLocation6 << endl; //Add
	cout << "pLocation0: " << (int)pLocation0 << endl;
	cout << "Difference is: " << difference << endl;

	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << randomArray + i << " = " << *(randomArray + i) << endl;
		//Address of randomArray + i	AND		Value of address 
	}

	cout << endl;
	int x;//Random integer with random address
	int * ptr_p;//Random pointer

	ptr_p = &x; //ptr_p holds address of x
	
	cout << int(ptr_p)<<endl;//Address of x
	cout << int(&x)<<endl;//Address of x
	
	* ptr_p = 5;//Address of which ptr_p points to holds value of 5
	cout << x << endl;

	int number = 15;
	int numberTwo = 15;

	passByValue(number);//We pass value of number
	passByRefrence(&numberTwo);//We pass address of numberTwo

	cout << "\nPass by Value: " << number << endl;
	cout << "Pass by Refrence: " << numberTwo << endl;

	return 0;
}

void passByValue(int x) {// x is a copy of number
	x = 99;//Since passed by value the value doesnt change
}

void passByRefrence(int * x) {//We get value of the address passed
	* x = 99; //Since passed by refrence, the address's value can be changed
}
