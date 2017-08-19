#include <iostream>
#include <cmath>

using namespace std;


int main() {

	int x = 0;
	int y = 0;
	int z = 0;

	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

	x = 5;
	y = 23456789;
	z = 987654321;

	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Z = " << z << endl;

	cout << 1234567890 * x % y << endl;
	cout << 987654321 + y << endl;

	y = 34567.34567;
	z = 23456789.987654321;

	cout << 3456789 * y % x << endl;

	float b = 345678.76543, a = 23456789.87654321;
	cout << b / a << endl;

	cout << "Pick a new x value: " << endl;
	cin >> x;

	cout << "Pick a new y value: " << endl;
	cin >> y;

	cout << "Pick a new z value: " << endl;
	cin >> z;

	cout << endl << endl << endl;

	cout << "Congrats you changed your values" << endl << "X = " << x << endl << "Y = " << y << endl << "Z = " << z << endl << endl << endl << endl << endl;

	cout << "Lets do some maths! Please select an option:" << endl;
	cout << "1 - Addition" << endl;
	cout << "2 - Subtract" << endl;
	cout << "3 - Multiply" << endl;
	cout << "4 - Divide" << endl;
	cout << "5 - Advanced Options" << endl;

	int selectedValue = 0;
	int firstValue = 0;
	int secondValue = 0;

	cin >> selectedValue;
	cout << selectedValue;

	cout << "Enter the first value: " << endl;
	cin >> firstValue ;

	cout << "Enter the second value: " << endl;
	cin >> secondValue;

	switch (selectedValue) {

	case 1:
		cout << "Your result value is... " << firstValue + secondValue << endl;
		break;
	case 2:
		cout << "Your result value is... " << firstValue - secondValue << endl;
		break;
	case 3:
		cout << "Your result value is... " << firstValue * secondValue << endl;
		break;
	case 4:
		cout << "Your result value is... " << firstValue / secondValue << endl;
		break;
	case 5:
		cout << "You have selected Advanced Options. Please select one of the options below." << endl << endl;
		cout << "1 - Exponential" << endl;
		cout << "2 - Square Root" << endl;

		int advancedOption = 0;

		switch (advancedOption) {
		case 1:
			cout << pow(firstValue, secondValue) << endl;
			break;
		case 2:
			cout << sqrt(firstValue) << endl;
			break;
		}


	}
}



















