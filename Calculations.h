#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
/*
Here in the Calulations.h file I created all the functions that I would use to calculatio the equation that the user types in,the function do as follows:

int valueChecker(): checks if the string passed is a number, if it is it, "convert it into a integer

int multiplication():checks if string is '*' if it is its multiplies the two values together and saves it to temp
int division():checks if string is '/' if it is its divides the two values together and saves it to temp
int addition():checks if string is '+' if it is its addition the two values together and saves it to temp
int subtraction():checks if string is '-' if it is its subtraction the two values together and saves it to temp

void addTemp(): passes the value temp created by one of the (*,/,+,or=) functions and adds it to the vector, then adjusts the string and vector
void paraCheck(): if paratheses are discovered, I remove them using this function BUT I adjust the string & vector without the paratheses
					EX: string: (3)+6	-->  with paraCheck() -->  string: 3+6
*/

int valueChecker(string value) {//Value to be checked is passed through the parameters
	stringstream check(value);//We use stringstream and pass value into it
	int number = 0;//We use number and set it as an integer to compare to the string
	if ((check >> number)) {//If the string "is" a number, then I return that value that was an string now emulated as a integer
		if (number == 0) {
			number = 00;
			return number;
		}
		return number;
	}
	return 0;
}

/*The following four functions are the operation functions, mostly similiar with minor changes, I attempted to create them all together
with one function due to their similiarties but it just resulted in bugs and crahes, so I decided to seperate them*/

int multiplication(vector<int> &intValues, string &input, int i) {//Multiplication function
	int temp = 0;
	if (input[i + 1] == '*') {//If value next to i is '*' we check a further step to see if multiplcation is needed
		if (intValues[i + 2] > 0 || intValues[i + 2] < 0) {//If i+2 is another value then we multiply them! CHECK FOR BUG HERE!!!!
			temp = intValues[i] * intValues[i + 2];//we multiply does two values together
		}
	}
	return temp;//we return temp to be added to vector and adjust vector and string!
}

int division(vector<int> &intValues, string &input, int i) {//Divide function divides 
	int temp = 0;
	if (input[i + 1] == '/') {//If value next to i is '/' we check a further step to see if division is needed
		if (intValues[i + 2] > 0 || intValues[i + 2] < 0) {//If i+2 is another value then we divide them!
			temp = intValues[i] / intValues[i + 2];
		}
	}
	return temp;//we return temp to be added to vector and adjust vector and string!
}

//Next two function are nearly the same just with addition and subtraction
int addition(vector<int> &intValues, string &input, int i) {//Addition function
	int temp = 0;
	if (input[i + 1] == '+') {
		if (intValues[i + 2] > 0||intValues[i+2]<0) {
			temp = intValues[i] + intValues[i + 2];
		}
	}
	return temp;
}

int subtraction(vector<int> &intValues, string &input, int i) {//Subtraction function
	int temp = 0;
	if (input[i + 1] == '-') {
		if (intValues[i + 2] > 0 || intValues[i + 2] < 0) {
			temp = intValues[i] - intValues[i + 2];
		}
	}
	return temp;
}

void paraCheck(vector<int> &intValues, string &input, int i) {//If paratheses are discovered, we remove them and adjust the vector and string
	intValues.erase(intValues.begin() + i);//Adjust Vector and remove'('
	intValues.erase(intValues.begin() + i + 1);//Adjust Vector and remove ')'

	for (int j = i + 1; j < input.size(); j++) {//Now I adjust the string
		input[j - 1] = input[j];//move over to the left one for: '('
	}
	for (int j = i + 2; j < input.size(); j++) {
		input[j - 1] = input[j];//move over to the left one for: ')'
	}
	input = input.substr(0, (input.size() - 2));//Make input string smaller by 2 because '(' ')' were removed
}

void addTemp(vector<int> &intValues, string &input, int i, int temp) {//We add temp to our vector and update the string and vector 
	intValues[i] = temp;//Insert Value inside of vector
	intValues.erase(intValues.begin() + (i + 1));//We erase index of i+1
	intValues.erase(intValues.begin() + (i + 1));//We erase index of i+1
	for (int j = i + 3; j < input.size(); j++) {//Adjust input string
		input[j - 2] = input[j];//Move over string input value's by 2
		/*EX: string: (5*3)+5 Let's say "j" is index 1 (so string value 5) so after adjustment..
			  string: (5)+5
			  THIS HOWEVER IS NOT THE EQUATION TO BE SOLVED, I DO THAT IN THE VECTOR I JUST NEED TO MOVE OVER ITEMS FROM LEFT TO RIGHT
		*/
	}
	input = input.substr(0, (input.size() - 2));//Adjust size of input string
}
#endif
