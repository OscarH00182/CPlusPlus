#include "pch.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void charConverter(string &input);

int main(){
	string input = ("3.5,55AV:1,V.5");
	charConverter(input);
	return 0;
}

void charConverter(string &input) {

	string newString = "";
	vector<string> results;

	for (int i = 0; i < input.size(); i++) {

		if (input[i] == '.'|| isdigit(input[i])) {
			newString = newString + input[i];
			if (i + 1 == input.size()) {
				results.push_back(newString);
			}
		}

		else {
			if (newString != "") {
				results.push_back(newString);
				newString = "";
			}
		}
	}

	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
}
