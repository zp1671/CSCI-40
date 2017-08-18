#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int createZombie() {

	int generatedNumber;

	generatedNumber = rand() % 54;

	if (generatedNumber > 100)
		return 11;

	else
		return rand() % 10 + 1;

}

int main() {

	srand(time(NULL));
	char enter;

	//Game Starts
	int playerAlive = true;
	int playerSkill = 9;
	int playerScore = 1;
	string playerName = "";
	int zombieCount = 0;
	int zombiesKilled = 0;
	int playerHealth = 100;

	//Title
	cout << "Welcome to Zombie War." << endl << "Press [enter] to start.";
	cin.get(enter);

	//Player name
	cout << "Please enter your name: ";
	cin >> playerName;

	//Zombie count
	cout << "How many zombies would you like to fight? ";
	cin >> zombieCount;

	cout << "Get ready to fight for your life " << playerName << "!" << endl;
	cout << "You have " << playerHealth << " health!" << endl;

	sleep(2);

	//main loop
	while (playerAlive && zombiesKilled < zombieCount) {

		int zombieSkill = createZombie();

		//battle sequence
		if (zombieSkill > 10) {

			cout << endl << "Here comes a HUGE zombie!" << endl;


		} else {

			cout << endl << "Here comes a zombie!" << endl;

		}

		cout << "Fighting..." << endl;
		sleep(2);

		//zombie killed the player
		if (playerSkill < zombieSkill) {

			playerAlive = false;
			playerHealth = 0;
			cout << "You have died." << endl;

			//Player killed the zombie
		} else {

			if (playerSkill - zombieSkill > 7) {

				cout << "You wasted the zombie!" << endl;
				cout << "You have " << playerHealth << " health remaining." << endl;
				playerScore = playerScore * 2;

			} else if (playerSkill - zombieSkill > 5) {

				cout << "You decapitated the zombie!" << endl;
				cout << "You have " << playerHealth << " health remaining." << endl;
				playerScore = playerScore * 2;

			} else if (playerSkill - zombieSkill > 0) {

				cout << "You have killed the zombie!" << endl;
				cout << "You have " << playerHealth << " health remaining." << endl;
				playerScore = playerScore * 2;

			} else {

				playerHealth = playerHealth * 0.95;
				cout << "You killed the zombie, but suffered injuries" << endl;
				cout << "You have only " << playerHealth << " health remaining" << endl;

			}

			zombiesKilled ++;

		}

		cout << endl;
		sleep(1);

	}

	//End game
	if (playerHealth == 0) {

		cout << playerName << " has been infected with the virus. The world has lost all hope!" << endl;
		cout << "Congradulations " << playerName << " everyone now hates you. :)" << endl << endl;

	} else {

		cout << "You have successfully stopped the virus! The world gives you praise." << endl << endl;

	}

	cout << "Zombies Killed: " << zombiesKilled << endl;
	cout << "Final Score: " << playerScore << endl << endl;

}
















