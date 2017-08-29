#include <iostream>
using namespace std;

int main() {

	int firstValue = 0;
	int secondValue = 0;
	int thirdValue = 0;
	int selectedValue = 0;

	cout << "Enter 1 to continue otherwise enter 0: ";

	cin >> selectedValue;

	if (selectedValue == 0) {
		exit(1);
	} else if (selectedValue == 1) {

		cout << "Please enter the first value: ";

		cin >> firstValue;

		if (!cin || firstValue < 0) {
			cout << "You have entered an invalid value!" << endl;
			exit(1);
		} else {
			cout << "Please enter the second value: ";

			cin >> secondValue;

			if (!cin || secondValue < 0) {
				cout << "You have entered an invalid value!" << endl;
				exit(1);
			} else {
				cout << "Please enter the third value: ";

				cin >> thirdValue;

				if (!cin || thirdValue < 0) {
					cout << "You have entered an invalid value!" << endl;
					exit(1);
				} else {
					cout << "You have ented only valid values congrats." << endl;

					cout << endl << endl;
				}
			}

		}
	} else {
		exit(1);
	}
}
