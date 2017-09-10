#include <iostream>
using namespace std;

int main() {

	int selectedHeight = 0;

	cout << "Height in number of stars for your triangle: ";

	cin >> selectedHeight;

	for (int i = 0; i < selectedHeight; i++) {

		cout << "* ";

		for (int j = 0; j < i; j++) {

			cout << "* ";

		}

		cout << endl;

	}
	/*
		for (int y = selectedHeight; y > -1; y--) {

			cout << "* ";

			for (int z = 0; z < y; z++) {

				cout << "* ";

			}

			cout << endl;

		}
	*/
}
