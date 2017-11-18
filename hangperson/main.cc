#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

void die() {
	cout << "INVALID INPUT!\n";
	exit(1);
}

void uppercaseify(string &s) {
	for (char &c : s) 
		c = toupper(c);
}

void continue_check() {
	cout << "Do you want to continue?\n";
	char c;
	cin >> c;
	if (c == 'n' || c == 'N') exit(0);
}

int main() {
	cout << "Welcome to Hangperson(tm)!\n";

	//PHASE 1 - Enter difficulty
    int diff = 0;
    cout << "What difficulty do you want?\n" << endl;
    cin >> diff;
    if (!cin || diff < 0 || diff > 10) die();
    cout << "Difficulty set to " << diff << ".\n" << endl; 
	continue_check();
	//PHASE 2 - Read the dictionary
	//Note: the file is in /usr/share/dict/words

	continue_check();

	//PHASE 3 - Pick a random word

	continue_check();

	//PHASE 4 - MAIN LOOP
}
