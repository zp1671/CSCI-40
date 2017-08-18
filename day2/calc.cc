#include <iostream>

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

	cout << "Congrats you changed your values" << endl << "X = " << x << endl << "Y = " << y << endl << "Z = " << z << endl;

}

