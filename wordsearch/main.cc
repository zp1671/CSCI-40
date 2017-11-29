#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void die() {
	cout << "Invalid input!\n";
	exit(EXIT_FAILURE);
}

void uppercaseify(string &s) {
	for (char &c : s)
		c = toupper(c);
}

bool upperCheck(string s) {
	char c;
	for (size_t i = 0; i < s.size(); i++) {
		while (s.at(i)) {
			c = s.at(i);
			if (!isalpha(c)) die();
			if (isupper(c)) return true;
		}
	}
	return false;
}

bool lowerCheck(string s) {
	for (char &c : s) {
		if (!islower(c)) return true;
	}
	return false;
}

bool numberCheck(string s) {
	for (char &c : s) {
		if (isdigit(c)) return true;
	}
	return false;
}

void continue_check() {
	cout << "Do you want to continue?\n";
	char c;
	cin >> c;
	if (c == 'n' || c == 'N') exit(0);
}

//Returns true if needle is in haystack, false otherwise
bool string_search(const string &needle, const string &haystack) {
	size_t loc = haystack.find(needle);
	if (loc != string::npos) return true;
	return false;
}

//YOU: Write this function
bool word_find(string s, const vector<string> &vec) {
	const size_t height = vec.size(); //How tall the table is

	//Search through the vector
	for (size_t i = 0; i < height; i++) {
		//Search horizontal
		if (string_search(s, vec.at(i))) return true;
		//Search backwards horizontal
		string horizontal = vec.at(i);
		reverse(horizontal.begin(), horizontal.end());
		if (string_search(s, horizontal)) return true;
		//Search top to bottom
		string top;
		for (unsigned int j = 0; j < height; j++) {
			top += vec.at(j).at(i);
		}
		if (string_search(s, top)) return true;
		//Search bottom to up
		reverse(top.begin(), top.end());
		if (string_search(s, top)) return true;
	}
	//Search diagonal down right (main diagonal only)
	string diag1;
	for (unsigned int z = 0; z < height; z++) {
		diag1 += vec.at(z).at(z);
	}
	if (string_search(s, diag1)) return true;
	//Search back up diag1
	reverse(diag1.begin(), diag1.end());
	if (string_search(s, diag1)) return true;
	//Search the diagonal down left (main diagonal only)
	string diag2;
	for (unsigned int k = 0; k < height; k++) {
		diag2 += vec.at(k).at(height - k - 1);
	}
	if (string_search(s, diag2)) return true;
	//Search back up diag2
	reverse(diag2.begin(), diag2.end());
	if (string_search(s, diag2)) return true;

	return false;
}

int main() {
	//PHASE 1 - Build up our table of letters for doing word searches
	cout << "Please enter lines of letters, all uppercase and the same length (blank line to stop):\n";
	vector<string> wordsearch; //All the words as entered

	string lolz;
	while (true) {
		getline(cin, lolz);
		if (lolz.length() < 3 && lolz.length() != 0) die();
		if (lolz.length() == 0) break;
		//if (!upperCheck(lolz)) die();
		wordsearch.push_back(lolz);
	}

	//YOU: Die if no strings were entered
	if (wordsearch.empty()) die();
	//YOU: Now vet the vector of strings to make sure they are all the same length
	for (unsigned int i = 0; i < wordsearch.size() - 1; i++) {
		if (wordsearch.at(i).length() == wordsearch.at(i + 1).length()) {
			continue;
		} else {
			die();
		}
	}

	if (wordsearch.at(0).length() != wordsearch.size()) {
		die();
	}
//YOU: Now print the table
	for (unsigned j = 0; j < wordsearch.size(); j++) {
		cout << wordsearch.at(j) << endl;
	}
	continue_check();

	//PHASE 2 - Load the dictionary
	ifstream dict_file("/usr/share/dict/words");
	if (!dict_file) {
		cout << "Error opening dictionary file!\n";
		exit(1);
	}

	//YOU: Load from the dictionary into a vector
	vector<string> dict;
	while (dict_file) {
		string tmp;
		getline(dict_file, tmp);
		if (!dict_file) break;
		if (lowerCheck(tmp)) continue;
		uppercaseify(tmp);
		if (tmp.length() >= 3) {
			dict.push_back(tmp);
		}
	}

	cout << dict.size() << " words loaded.\n";
	continue_check();

	//PHASE 3 - For each word in the dictionary, look through the wordsearch vector and print it if it is in there
	for (string s : dict) {
		//YOU: Uppercaseify S so that it can match
		uppercaseify(s);
		//YOU: Write this function above
		if (word_find(s, wordsearch)) {
			cout << "FOUND: " << s << endl;
		}
	}
	//GL; HF
}
