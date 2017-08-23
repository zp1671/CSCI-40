#include <iostream>
#include <typeinfo>
#include <cmath>

using namespace std;

int main() {

	long long x, y;

	cout << "Please enter the value for x: ";
	cin >> x;
	cout << endl;

	//if (typeid(x) == typeid(string())) {
	if (!cin) {

		cout << "oops" << endl;
		return 0;

	}

	cout << "Please enter the value for y: ";
	cin >> y;
	cout << endl;

	if (!cin) {

		cout << "oops" << endl;
		return 0;

	}

	cout << x << y << endl << endl;

	int selectedOperation = 0;
	cout << "1 - Addition" << endl;
	cout << "2 - Subtration" << endl;
	cout << "3 - Multiplication" << endl;
	cout << "4 - Division" << endl;
	cout << "Please select an opperation: ";

	cin >> selectedOperation;

	switch (selectedOperation) {

	case 1:
		cout << "x + y = " << x + y << endl;
		break;
	case 2:
		cout << "x - y = " << x - y << endl;
		break;
	case 3:
		cout << "x * y = " << x * y << endl;
		break;
	case 4:
		cout << "x / y = " << x / y << endl;
		break;

	}

	cout << "Thanks for calculating numbers!" << endl << endl << endl;
}
