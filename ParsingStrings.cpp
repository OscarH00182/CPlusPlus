#include "pch.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void charConverter(string &input,vector<string> &results);
void deleteDuplicates(vector<string> &words);

int main() {

	string input = ("2.5,1aa3,1a5,3aaa3");//Input too be proccessed
	vector<string> results;//We make a vector of strings called results

	charConverter(input,results);//Pass input into the converter function
	return 0;
}

void charConverter(string &input, vector<string> &results) {//Passes input to be proccesed

	string newString = "";//We set newString to empty to be edited

	for (int i = 0; i < input.size(); i++) {//We run through input character by character

		if (input[i] == '.' || isdigit(input[i])) {//We check to see if current character is decimal or a digit
			newString = newString + input[i];//If it is, we add this to newString

			if(i == input.size() - 1) {//IF at last character in string,input final newString
				results.push_back(newString);//Push back final value into vector
				deleteDuplicates(results);
			}
		}

		else if (newString != ""){//IF newstring ISNT EMPTY (contain value/decimal) we add newString to the vector
				results.push_back(newString);//Push back into the vector
				deleteDuplicates(results);
				newString = "";//Reset String
		}
	}

	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
}

void deleteDuplicates(vector<string> &words){

	sort(words.begin(), words.end());//Sort vector first

	for (int i = 1; i < words.size(); i++) {//Run through entire current Vector

		if (words[i - 1] == words[i]) {//Checks if theres a duplicate
			words.erase(words.begin() + i);//If there is, remove the duplicate
		}
	}			
}
