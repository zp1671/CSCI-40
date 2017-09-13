#include <iostream>
#include <cmath>
using namespace std;

//Returns true if the point defined by (x,y) is within the circle defined
// by the center point (circle_x,circle_y) and radius "radius"
bool is_in_circle(int x, int y, int circle_x, int circle_y, float radius) {
	//YOU: Pythagorus calculation: a^2 + b^2 = c^2 and all that

	float fml = sqrt(pow(circle_x - x, 2) + pow(circle_y - y, 2));

	if (fml <= radius) {

		return true;

	} else {

		return false;

	}
}

//Returns true if x and y are within (>= min and <= max) the rectangle
bool is_in_rect(int x, int y, int x_min, int x_max, int y_min, int y_max) {
	//YOU
	if (x <= x_max && x >= x_min && y <= y_max && y >= y_min) {
		return true;
	} else {
		return false;
	}
}

//Returns true if x and y are within a right triangle that is the bottom left half
// of the equivalent right triangle
bool is_in_triangle(int x, int y, int x_min, int x_max, int y_min, int y_max) {
	//YOU
	if (x >= x_min && x <= x_max && y >= x_min && y <= x_max && ((x * (y_max - y_min)) > (y * (x_max - x_min)))) {

		return true;

	} else {
		return false;
	}
}

void die() {
	cout << "INVALID MEME ERROR.\n";
	exit(1);
}

int main() {
	cout << "Welcome to Microsloth Paint 1981 Edition!\n";
	cout << "You will draw a triangle, a rectangle, and a circle on the screen.\n";

	const int SIZE_X = 40; //The size of the field wide
	const int SIZE_Y = 20; //The size of the field high

	int circle_x = 0, circle_y = 0; //The center point for the circle
	float radius = 0; //The radius of the circle

	int rect_x_min = 0; //The left edge of the rect
	int rect_x_max = 0; //The right edge of the rect
	int rect_y_min = 0; //The top edge of the rect
	int rect_y_max = 0; //The bottom edge of the rect

	int tri_x_min = 0; //The left edge of the triangle
	int tri_x_max = 0; //The right edge of the triangle
	int tri_y_min = 0; //The top edge of the triangle
	int tri_y_max = 0; //The bottom edge of the triangle

	cout << "Please enter the center point for a circle (x,y):\n";
	cin >> circle_x >> circle_y; //Note: this is not a typo, y is x and vice versa.
	if (!cin) die();
	if (circle_x < 0 || circle_x >= SIZE_X) die();
	if (circle_y < 0 || circle_y >= SIZE_Y) die();

	cout << "Please enter the radius for the circle:\n";
	cin >> radius;
	//YOU: Vet the input

	cout << "Please enter the points defining a rectangle (x_min, x_max, y_min, y_max):\n";
	cin >> rect_x_min >> rect_x_max >> rect_y_min >> rect_y_max; //Get rect
	//YOU: Vet the input

	cout << "Please enter the points defining a triangle (x_min, x_max, y_min, y_max):\n";
	cin >> tri_x_min >> tri_x_max >> tri_y_min >> tri_y_max; //Tri hard
	//YOU: Vet the input

	//Main loop
	for (int i = 0; i < SIZE_Y; i++) { //Across every row
		for (int j = 0; j < SIZE_X; j++) { //Across every column
			//If the current pixel is within any of the three of them
			// draw a '*', otherwise a ' '.
			if (is_in_circle(j, i, circle_x, circle_y, radius) ||
			        is_in_rect(j, i, rect_x_min, rect_x_max, rect_y_min, rect_y_max) ||
			        is_in_triangle(j, i, tri_x_min, tri_x_max, tri_y_min, tri_y_max)) {
				cout << '*';
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}
