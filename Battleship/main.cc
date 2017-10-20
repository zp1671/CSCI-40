#include <iostream>
#include <cstdlib>
using namespace std;

const size_t SIZE = 12;
int board[SIZE][SIZE] = {};

//Makes a bunch of constants for the letters to be printed on the board
enum tiles { CLEAR = 0, DESTROYER, SUBMARINE, BATTLESHIP, AIRCRAFT_CARRIER, HIT, MISS };
int message = 0; //If a ship has been destroyed, it will be set to BATTLESHIP or whatever
int numOfDestroyedShips = 0;

//Holds how big each ship is
enum sizes { DESTROYER_SIZE = 2, SUBMARINE_SIZE = 3, BATTLESHIP_SIZE = 4, AIRCRAFT_CARRIER_SIZE = 5 };

void die() {
	cout << "Bad input!\n";
	exit(1);
}

bool isDestroyer = true;
bool isSubmarine = true;
bool isBattleship = true;
bool isAircraftCarrier = true;

void win(); //Function prototype, ends the game successfully
void lose(); //Ends the game with failure

void print_board() {
	system("clear");
	cout << "BATTLESLOOP 2000(tm)\n";
	//Print column headers
	cout << "\t";
	for (size_t i = 0; i < SIZE; i++)
		cout << i << "\t";
	cout << endl;
	//Print board
	for (size_t i = 0; i < SIZE; i++) {
		//Print row headers
		cout << i << "\t";
		for (size_t j = 0; j < SIZE; j++) {
			if (board[j][i] == CLEAR) cout << "." << "\t";
			else if (board[j][i] == DESTROYER) cout << "D" << "\t";
			else if (board[j][i] == SUBMARINE) cout << "S" << "\t";
			else if (board[j][i] == BATTLESHIP) cout << "B" << "\t";
			else if (board[j][i] == AIRCRAFT_CARRIER) cout << "A" << "\t";
			else if (board[j][i] == HIT) cout << "*" << "\t";
			else if (board[j][i] == MISS) cout << "X" << "\t";
			else die();
		}
		cout << endl;
	}
	if (message == MISS) 		cout << "MISS!\n";
	else if (message == HIT) 		cout << "HIT!\n";
	else if (message == DESTROYER) 	cout << "You sank my destroyer!\n";
	else if (message == SUBMARINE) cout << "You sank my submarine!\n";
	else if (message == BATTLESHIP) cout << "You sank my battleship!\n";
	else if (message == AIRCRAFT_CARRIER) cout << "You sank my aircraft carrier!\n";
	//YOU: Do the rest

	message = 0; //Clear the message so it doesn't display again.
}

int main() {
	cout << "Welcome to Battlesloop 2000(tm)\n";
	cout << "Press any key and hit enter to continue.\n";
	getchar();

	//PHASE 1 - Set up the ships on the board

	//DESTROYER PLACEMENT
	print_board();
	cout << "Please insert the (x,y) starting location for the destroyer:\n";
	int x = 0, y = 0;
	cin >> x >> y;
	if (!cin) die();
	//YOU: Error check the coordinates
	if (x < 0 || x > SIZE - 1 || y < 0 || y > SIZE - 1) die(); 
	cout << "Is the destroyer vertical (v) or horizontal (h)?\n";
	char c = 0;
	cin >> c;
	if (!cin) die();
	if (c == 'v') { //If vertical, we start at the top and go down
		for (int i = 0; i < DESTROYER_SIZE; i++) {
			//YOU: Error check the coordinates
			if (y < SIZE) {
				board[x][y] = DESTROYER;
				y++;
			} else {
				die();
			}
		}
	} else if (c == 'h') {
		//YOU: Do the same for a horizontal ship
		for (int i = 0; i < DESTROYER_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (x < SIZE) {
					board[x][y] = DESTROYER;
					x++;
				} else {
					die();
				}
			} else die();
	
		}
	} else die();
	print_board();

	//YOU: Do the same for the other three ships
	//SUBMARINE PLACEMENT
	cout << "Please insert the (x,y) starting location for the submarine:\n";
	cin >> x >> y;
	if (!cin || x > SIZE - 1 || x < 0 || y > SIZE - 1 || y < 0) die();
	cout << "Is the submarine vertical (v) or horizontal (h)?\n";
	cin >> c;
	if (c == 'v') {
		for (int i = 0; i < SUBMARINE_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (y < SIZE) {
					board[x][y] = SUBMARINE;
					y++;
				} else die();	
			} else die();
		}
	} else if (c == 'h') {
		for (int i = 0; i < SUBMARINE_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (x < SIZE) {
					board[x][y] = SUBMARINE;
					x++;
				} else {
					die();
				}
			} else die();
	
		}
	} else die();
	print_board();

	//BATTLESHIP PLACEMENT
	cout << "Please insert the (x,y) starting location for the battleship: \n";
	cin >> x >> y;
	if (!cin || x > SIZE - 1 || x < 0 || y > SIZE - 1 || y < 0) die();
	cout << "Is the battleship vertical (v) or horizontal (h)?\n";
	cin >> c;
	if (c == 'v') {
		for (int i = 0; i < BATTLESHIP_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (y < SIZE) {
					board[x][y] = BATTLESHIP;
					y++;
				} else die();
			} else die();
		}
	} else if (c == 'h') {
		for (int i = 0; i < BATTLESHIP_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (x < SIZE) {
					board[x][y] = BATTLESHIP;
					x++;
				} else die();
			} else die();
		}
	} else die();
	print_board();

	cout << "Please insert the (x,y) starting location for the aircraft carrier: \n";
	cin >> x >> y;
	if (!cin || x > SIZE -1 || x < 0 || y > SIZE - 1 || y < 0) die();
	cout << "Is the aircraft carrier vertical (v) or horizontal (h)? \n";
	cin >> c;
	if (c == 'v') {
		for (int i = 0; i < AIRCRAFT_CARRIER_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (y < SIZE) {
					board[x][y] = AIRCRAFT_CARRIER;
					y++;
				} else die();
			} else die();
		}
	} else if (c == 'h') {
		for (int i =0; i < AIRCRAFT_CARRIER_SIZE; i++) {
			if (board[x][y] == CLEAR) {
				if (x < SIZE) {
					board[x][y] = AIRCRAFT_CARRIER;
					x++;
				} else die();
			} else die();
		}
	} else die();

	//PHASE 2 - Shoot torpedoes at the ships until they're all destroyed
	int torpedoes = 40; //If these run out, we lose

	//Main loop
	while (true) {  
		print_board(); //Display the world state
		//Input next move
		cout << "Please enter where you want to shoot a torpedo:\n";
		cin >> x >> y;
		if (!cin || x < 0 || x > 11 || y < 0 || y > 11) die(); //YOU: Add in bounds checks for x and y

		if (board[x][y] == CLEAR || board[x][y] == HIT || board[x][y] == MISS) {
			message = MISS; //This will do a cout << "MISS!\n"; when the board is next printed

			//YOU: When should it not register a miss? Add an if statement for that

			if (board[x][y] == HIT || board[x][y] == MISS) {

			} else {
				board[x][y] = MISS;
			}
		} else { 
			//Hit!
			message = HIT;
			//YOU: Mark the board with a hit
			board[x][y] = HIT;
			//YOU: If that was the last one of a certain ship, set message.
			// In other words, if that was the last of the battleship,
			// set message = BATTLESHIP. This will cause "You sank my battleship!" to be
			// printed the next time the board is displayed instead of just "HIT!"
			int dShipCtn = 0;
			int sShipCtn = 0;
			int bShipCtn = 0;
			int aShipCtn = 0;

			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					if (board[i][j] == DESTROYER) {
						dShipCtn++;
					} else if (board[i][j] == SUBMARINE) {
						sShipCtn++;
					} else if (board[i][j] == BATTLESHIP) {
						bShipCtn++;
					} else if (board[i][j] == AIRCRAFT_CARRIER) {
						aShipCtn++;
					}
				}
			}

			if (dShipCtn == 0 && isDestroyer == true) {
				message = DESTROYER;
				isDestroyer = false;
			} else if (sShipCtn == 0 && isSubmarine == true) {
				message = SUBMARINE;
				isSubmarine = false;
			} else if (bShipCtn == 0 && isBattleship == true) {
				message = BATTLESHIP;
				isBattleship = false;
			} else if (aShipCtn == 0 && isAircraftCarrier == true) {
				message = AIRCRAFT_CARRIER;
				isAircraftCarrier = false;
			} 

			if (dShipCtn == 0 && sShipCtn == 0 && bShipCtn == 0 && aShipCtn == 0) {
				win();
			}
		}
		//YOU: Reduce torpedoes by 1
		torpedoes--;
		//YOU: If torpedoes is < 0, call lose();
		if (torpedoes <= 0) lose();

	}
}

void beep() {
	cout << "";
}
void win() {
	beep();
	cout << "    _     __        _____ _   _ _   _ _____ ____    ___ ____\n";
	cout << "   / \\    \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\  |_ _/ ___|\n";
	cout << "  / _ \\    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) |  | |\\___ \\\n";
	cout << " / ___ \\    \\ V  V /  | || |\\  | |\\  | |___|  _ <   | | ___) |\n";
	cout << "/_/   \\_\\    \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\ |___|____/\n";
	cout << "\n";
	cout << "__   _____  _   _\n";
	cout << "\\ \\ / / _ \\| | | |\n";
	cout << " \\ V / | | | | | |\n";
	cout << "  | || |_| | |_| |\n";
	cout << "  |_| \\___/ \\___/\n";
	beep();
	exit(0);
}

void lose() {
	beep();
	cout << "__   _____  _   _   _     ___  ____  _____\n";
	cout << "\\ \\ / / _ \\| | | | | |   / _ \\/ ___|| ____|\n";
	cout << " \\ V / | | | | | | | |  | | | \\___ \\|  _|\n";
	cout << "  | || |_| | |_| | | |__| |_| |___) | |___\n";
	cout << "  |_| \\___/ \\___/  |_____\\___/|____/|_____|\n";
	beep();

	exit(0);
}
