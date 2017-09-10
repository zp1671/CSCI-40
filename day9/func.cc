#include <iostream>
#include <cmath>
using namespace std;

float printZero() {

	return 0;

}

float func1(float x) {

	float temp = 2 * x;

	return temp;

}

float func2(float y) {

	float temp = 0;
	temp = y * y;
	return temp * 2;

}

float func3(float z) {

	float lolz = 0;
	lolz = (3 - ((z * z) * 2));
	return lolz * lolz;

}

float func4(float k) {

	return sin(k);

}

int main() {

	while (true) {
		cout << "************************" << endl;
		cout << "1 - returns 0" << endl;
		cout << "2 - 2x" << endl;
		cout << "3 - 2x^2" << endl;
		cout << "4 - (3-2x^2)^2" << endl;
		cout << "5 - sin(x)" << endl;
		cout << "************************" << endl;
		cout << "Please select a function to call: ";

		int selectedThing = 0;
		float valueForX = 0;

		cin >> selectedThing;

		if (!cin || selectedThing < 0) exit(1);

		switch (selectedThing) {
		case 1:
			cout << "You selected 1, your returned value is: " << printZero() << endl << endl << endl << endl;
			break;
		case 2:
			cout << "You selected 2, please enter a value for x: ";
			cin >> valueForX;
			if (!cin) exit(1);
			cout << "Your returned value is: " << func1(valueForX) << endl << endl << endl << endl;
			break;
		case 3:
			cout << "You selected 3, please enter a value for x: " << endl << endl << endl << endl;
			cin >> valueForX;
			if (!cin) exit(1);
			cout << "Your returned value is: " << func2(valueForX) << endl << endl << endl << endl;
			break;
		case 4:
			cout << "You selected 4, please enter a value for x: ";
			cin >> valueForX;
			if (!cin) exit(1);
			cout << "Your returned value is: " << func3(valueForX) << endl << endl << endl << endl;
			break;
		case 5:
			cout << "You selected 5, please enter a value for x: ";
			cin >> valueForX;
			if (!cin) exit(1);
			cout << "Your returned value is: " << func4(valueForX) << endl << endl << endl << endl;
			break;
		default:
			break;
		}

	}
}
