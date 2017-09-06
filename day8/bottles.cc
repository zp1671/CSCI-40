#include <iostream>
using namespace std;

int main() {

	for (int i = 0; i < 100; i++) {

		int x = 0;
		x = 99 - i;

		if (x > 0 || x == 0) {

			if (x == 1) {
				cout << x << " bottle of beer on the wall." << endl << x << " bottle of beer." << endl << "Take one down, pass it around." << endl;
				cout << "No more bottles of beer on the wall." << endl << endl;
				cout << "No more bottles of beer on the wall." << endl << "No more bottles of beer." << endl << "Go to the store, buy some more." << endl << "99 bottles of beer on the wall." << endl;
			} else if (x > 2) {

				cout << x << " bottles of beer on the wall." << endl << x << " bottles of beer." << endl << "Take one down, pass it around." << endl;
				cout << x - 1 << " bottles of beer on the wall." << endl << endl;

			} else if (x == 2) {
				cout << x << " bottles of beer on the wall." << endl << x << " bottles of beer." << endl << "Take one down, pass it around." << endl;
				cout << x - 1 << " bottle of beer on the wall." << endl << endl;
			}

		}
	}

}
