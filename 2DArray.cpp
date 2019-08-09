#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	// an array with 5 rows and 2 columns.
	string a[3][5];
	//a[row number][column number]
	// output each array element's value                      
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			string b;
			cout << "Enter input: " << endl;
			cin >> b;
			a[i][j] = b;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
				cout << a[i][j];
		}
		cout << endl;
	}
		
	return 0;
}
