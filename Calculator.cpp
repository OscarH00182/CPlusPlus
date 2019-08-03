#include "pch.h"
#include "Calculations.h"
/*
Approach:
	NOTE: I kept the complexity of the equation as those examples given so the equations can only be held as single digit values! In other words, (5*8)/(5+5) will
	run and give you answer, but 10*10 WONT. However I did implement multiplication,division,addition,subtraction.

	The way I wanted this program to function is that I wanted the equation to be input by the user. So the way I approached this type of implementation is
	by using a string and vector. The equation would be stored in a string, which would then be checked by my valueChecker() function that would convert a string
	value into the actual number it represented, other was it would return 0. The vector would then be filled by these numbers, either the value or 0, with the 0 
	indictating it was some sort of mathematical operation or paratheses. 

	For the calculation we check each bit of the entire string. If the vector's is not 0, then we know it hold a number, we then check the string's one value over to
	see the operation (*,/,+,-)/. Then we calculate the vector two values, by the operation it is, this gives me our temp value. Which is then added
	to our vector, then the vector and string are adjusted by 2 values over.This is done until there is only one vector value, which holds the answer!

	EX: Let's say our input is: (3*5)+1
		string |(|3|*|5|)|+|1|
		vector |0|3|0|5|0|0|1|
		
		After multplication and adjusting string/vector
		string |(|3|)|+|1|
		vector |0|15|0|0|1|

		After removing paratheses and adjusting string/vector
		string |3|+|1|
		vector |15|0|1|

		After final addition!
		string |3|
		vector |16| <-- Answer

*/
int main() {

	for (int i = 0; i < 5; i++) {//Loop 5 times to try 5 different equations

		string input;
		vector<int> intValues;//Vector that will handle all of the values 
		cout << "Enter a single digit mathematical equation: ";
		cin >> input;//Allows user to insert any equation

		for (int i = 0; i < input.length(); i++) {//Loops throughout the entire equation
			string value;
			value = input[i];//Each value of string passed is set to value
			int result = valueChecker(value);//I pass value to the valueChecker function to see if its a number, if not it returns a 0
			intValues.push_back(result);//I add result to the vector,if the value is (,),*,/,+,- its a 0 otherwise its respective number
		}

		while (intValues.size() > 1) {//Until vector holds one value, it loops,that one value will be the answer!
			//DUE TO THE ORDER OF OPERATIONS,THE 1ST LOOP HANDLES MULTIPLICATION AND DIVISION
			for (int i = 0; i < input.length(); i++) {//Loops through entire string

				int temp = 0;

				if (intValues[i] > 0 || intValues[i] < 0) {//If an actual value we check if we can multiply or divide

					temp = multiplication(intValues, input, i);//First check for multiplication

					if (temp == 0) {//If temp is STILL 0, then there wasnt a multiplcation sign, so we check for division

						temp = division(intValues, input, i);//Now we check for division

						if ((input[i] == '(') && (input[i + 2] == ')')) {//Checks for paratheses

							paraCheck(intValues, input, i);//If there are, remove and break from loop
							break;
						}

						if (temp > 0 || temp < 0) {//Add calculation to vector and adjusts

							addTemp(intValues, input, i, temp);
							break;
						}
					}
				}

				if ((input[i] == '(') && (input[i + 2] == ')')) {//The process is the same for all operations,however each is done indivually 

					paraCheck(intValues, input, i);
					break;//Because I changed size of input
				}

				if (temp > 0 || temp < 0) {

					addTemp(intValues, input, i, temp);
					break;//breaks out of big loop
				}
			}//If theres no multiplication or division, it checks next value until it runs through the entire string

			//NOW WE CHECK FOR ADDITION AND SUBTRACTION
			for (int i = 0; i < input.length(); i++) {//Loop through entire string

				int temp = 0;

				if (intValues[i] > 0 || intValues[i] < 0) {

					temp = addition(intValues, input, i);//Now we check for Addition

					if (temp == 0) {//If temp is STILL 0, so we check for subtraction

						temp = subtraction(intValues, input, i);

						if ((input[i] == '(') && (input[i + 2] == ')')) {

							paraCheck(intValues, input, i);
							break;
						}

						if (temp > 0 || temp < 0) {

							addTemp(intValues, input, i, temp);
							break;
						}
					}
				}

				if ((input[i] == '(') && (input[i + 2] == ')')) {

					paraCheck(intValues, input, i);
					break;
				}

				if (temp > 0 || temp < 0) {

					addTemp(intValues, input, i, temp);
					break;
				}
			}
		}

		cout << "The Answer is: " << intValues[0] << endl;
	}
	return 0;
}
