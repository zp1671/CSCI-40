#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

//if currentStore == 1 then they are in the Clothing Store
//if currentStore == 2 then they are in the Medical Office
//if currentStore == 3 then they are in the Gun Shop
//if currentStore == 4 then they are in the Food Court
int currentStore = 0;

//Random Vars worth a look at
int selectedOption = 0;
int amountOfRolls = 0;
int rollOfDice = 0;
bool isMedicOfficeOpen = false;

//World Info
int dayCnt = 1;

// Creates user global data
string globalPlayerName = "";
int completedPuzzles = 0;

float globalPlayerHeath = 100;
int globalPlayerStamina = 0;
int globalPlayerSpeed = 0;
int globalPlayerArmor = 0;

int globalNumberofBandages = 0;
int globalPiecesofFood = 0;
int globalNumberofBullets = 10;
int globalNumberofGunKilledZombies = 0;
int globalNumberofSilentKilledZombies = 0;

//Puzzle Info
//Has killed 2 zombies silently
//Has 20 bandages
//Has 10 pieces of food
//Has killed 5 zombies with a gun
//Has found 50 pieces of ammo.
int numberOfPuzzlesCompleted = 0;
int ans1 = 0;
int ans2 = 0;
int ans3 = 0;

void clrScreen() {
	cout << "\033[2J\033[1;1H";
}

void die() {
	cout << "You're an asshole. Stop." << endl;
	exit(0);
}

void rollDice(int lo, int hi) {
	amountOfRolls++;
	cout << "Rolling the dice..." << '\n';
	sleep(1);
	int n = hi - lo + 1;
	int i = rand() % n;
	if (i < 0) {
		i = -i;
	}
	cout << "You have rolled: " << i + 1 << '\n';
	rollOfDice = i + 1;
	sleep(1);
	clrScreen();
}

void incorrectPuzzleAnswer() {
	cout << "You suck. You can't get into the medic room yet. Please reroll the dice." << '\n';
	rollDice(1, 10);
}

int randomNumberGenerator() {
	int n = 10 - 1 + 1;
	int i = rand() % n;
	if (i < 0) i = -i;
	return 1 + i;
}

//Sets up the different locations.
void medicalOffice() {
	cout << "You are in the medical office." << endl;
	sleep(1);
	clrScreen();
	if (isMedicOfficeOpen == false) {
		cout << "You move toward the door and open it." << endl;
		cout << "As the door creaks open the light from the halway shows the destruction within the room." << endl;
		cout << "Broken chairs along the floor, the desk flipped on the side with bullet holes around the outside, and floor matresses covered in blood." << endl;
		sleep(15);
		cout << "As you search the room you notice a metal standing book shelf still right side up." << endl;
		cout << "You go over to it and notice that it hiding something attached to the wall." << endl;
		cout << "With all your might you push the shelf to the side, and notice a metal box on the wall." << endl;
		cout << "The box had the Red Cross icon on the front read 'First Aid' around the bottom of the box." << endl;
		cout << "On the side you notice a spin dial lock, and attached to it was piece on paper." << endl;
		cout << "On the paper were several question to getting the number to unlock the lock" << endl;
		sleep(1);

		clrScreen();

		cout << "Question 1) Jane has 48 apples to sell. While she wasn't looking a robber steals 1/2 of them. How many apple does she have?" << endl;
		cin >> ans1;
		if (!cin) die();
		if (ans1 == 24) {
			clrScreen();
			cout << "Question 2) Diana went to the movie 3 times a month. If a movie ticket cost 8 dollars per movie, how many movies did she watch in a year." << endl;
			cin >> ans2;
			if (!cin) die();
			if (ans2 == 24) {
				cout << "Question 3) They're 10 marbles inside a green bag. 4 blue, 2 red, 2, yellow, and 2 white. What is the possibility you get a black marble." << endl;
				cin >> ans3;
				if (!cin) die();
				if (ans3 == 0) {
					isMedicOfficeOpen = true;
					cout << "The medic office is now open to you. Also you have gained 20 bandages." << '\n';
					cout << "Congradulations you have completed the medic puzzle!" << '\n';
					completedPuzzles++;
				}
			} else {
				incorrectPuzzleAnswer();
			}
		} else {
			incorrectPuzzleAnswer();
		}
	} else {
		if (randomNumberGenerator() > 5) {
			cout << "You have gained 5 bandages" << '\n';
			globalNumberofBandages += 5;
		} else {
			cout << "You have found nothing. Please comeback later" << '\n';

		}
	}


}

void winnerChickenDinner() {
	cout << "Congradulations you unworthy sack of shit. You have beat the game." << '\n';
	cout << "You have completed all 5 puzzles" << '\n';
	cout << "Thank you for playing" << globalPlayerName << '\n';
	exit(0);
}

void haveBeenKilled() {
	cout << "You have died" << endl << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Number of puzzles completed = " << numberOfPuzzlesCompleted;

	cout << endl << endl;
	cout << "Thank you for playing " << globalPlayerName << endl;

	cin >> selectedOption;

	exit(0);
}

void foodCourt() {
	clrScreen();
	cout << "As you arrive to the food court you begin to hear alot of commotion" << endl;
	cout << "In the middle of the room stood four people, one man holding a gun, and another man with his family." << endl;
	sleep(4);
	cout << "'Come on man', said man without the gun,'You've taken all the food.'Can't we find a resonable way to share it with everyone" << endl;
	cout << "'Why don't you give me a reason to share it, because the way I see it i have no reason to give you any at all, said the man with the gun.'" << endl;
	cout << "In this incounter you only have one way to a solve this problem." << endl;
	cout << "1 - Come out of hiding and try to deal with the situation calmly." << endl;
	cin >> selectedOption;
	if (!cin || selectedOption != 1) die();

	if (selectedOption == 1) {
		clrScreen();
		cout << "'Hey', you shout out, 'You know that not very nice.'" << endl;
		cout << "The man and the family turn and face you, surprised by your apperance." << endl;
		cout << "'What did you say', said the man with the gun." << endl;
		sleep(4);
		cout << "'All I'm saying is, you have enough food to stuff yourself full for days, it wouldn't hurt to share a few', you explain." << endl;
		cout << "The man begins to chuckle, which slowly turns into a malicious laugh." << endl;
		cout << "'You know what I'll cut you a deal then hero', he says. 'How about you give me all of your food and then I will give them some of mine, you know as a little payment for their food'." << endl;

		cout << "1) Give him all of your food" << endl;
		cout << "2) You try to reason with him with a more reasonable deal" << endl;
		cout << "3) You see the father ready to attack and wait till he does." << endl;

		cin >> selectedOption;
		if (!cin || selectedOption > 3 || selectedOption < 1) die();

		if (selectedOption == 1 && globalPiecesofFood == 0) {
			cout << "Your a dumbass. You promised him food that you didn't have any of, so due to natural selection. You die." << endl;
			haveBeenKilled();
		} else if (selectedOption == 1 && globalPiecesofFood != 0) {
			cout << "'Here', you say as you pass the remainder of your food supplies over." << endl;
			cout << "'Nice doing business with you', said the man, and here is your food for your family." << endl;
			cout << "The man give them half of what you gave him" << endl;
			sleep(10);
			cout << "'Well I'll be on my way.', said the man as he walked out of the room." << endl;
			cout << "'Thank you', said the Father, 'I don't know what would of happened without you.'" << endl;
			cout << "'Here, I know it's much but it should help you',said the mother" << endl;
			cout << "She hands you 5 pieces of food and 2 bandages." << endl;
			cout << "She says good bye and leaves with her family" << endl;

			globalPiecesofFood = 5;
			globalNumberofBandages = 2;
			completedPuzzles++;

		} else if (selectedOption == 2) {
			clrScreen();
			cout << "'Okay how about a counter offer', you state" << endl;
			cout << "'How about I give you nothing and you just help these people out'" << endl;
			cout << "'I see, that your decision', said the man, 'Well then I guess were going to have alot more dummy bodies for the zombies.'" << endl;
			cout << "He turns to the family and points the gun at them." << endl;
			sleep(10);
			cout << "As you begins to pull on the trigger a loud and raspey grunt comes from behind the counter of one of the food court booth." << endl;
			cout << "A zombie spring out of the booth and attacks the man with the gun." << endl;
			cout << "While he is attacked the family gets up and starts to run." << endl;
			cout << "The man screams out, 'Help, please help me!'" << endl;
			cout << "As you look at the man you notice the bag full of food on the floor." << endl;
			cout << "You are left between a hard choice" << endl;
			//option for the players to choose.
			cout << "1) Save the man and forget the food." << endl;
			cout << "2) Grab the food and run." << endl;

			cin >> selectedOption;
			if (!cin || selectedOption > 2 || selectedOption < 1) die();

			if (selectedOption == 1) {
				cout << "You are too nice. He was going to die anyways, so due to natural selection you have died because of stupidity." << endl;
				haveBeenKilled();
			} else if (selectedOption == 2) {
				cout << "You look at the man and then down at the food." << endl;
				cout << "You grab the bag and begin to sprint towards the family's direction" << endl;
				cout << "'Hey!', he screams, 'Come back here, come back here you thief.'" << endl;
				cout << "As he screams more and more zombies begin to show up drawn by the commotion" << endl;
				cout << "In the back of your mind, as you run from the scene you here the man screams echo throughout the mall." << endl;
				cout << "After you regroup with the family, you open the bag full of food and spilt it with the family." << endl;
				cout << "They thank you and begin to run back out into the mall, trying to find a safe place to stay." << endl;
				cout << "You gained 10 pieces of food." << endl;
				globalPiecesofFood += 10;
				completedPuzzles++;
				goToNextDay();
			}

		} else if (selectedOption == 3) {
			clrScreen();
			cout << "As the man rants on, you try to find a way to get the gun away from him." << endl;
			cout << "You then notice the father inching closer and closer to the man." << endl;
			cout << "Finally, the father jumped up onto the man and grabbed the gun." << endl;
			cout << "Once the fighting started you begin to rush to the scuffle. However as you soon as you gotten closer to the struggle to help, a gun shot echos through the mall." << endl;
			cout << "Both of the men look at each other, and both of them looked down." << endl;
			sleep(15);
			cout << "Around the waist of the father, a circle blood stain started to grow." << endl;
			cout << "The father stumbled back and fell into his family arms, choking on his last breath." << endl;
			cout << "The man however, looking at himself, snickered and laughed at the scene." << endl;
			cout << "He then again pointed the gun back at you." << endl;
			cout << "'So, as you can see I still got alot of control here', he says proudly" << endl;
			cout << "'So why don't you just hand over all of your--'" << endl;
			sleep(15);

			clrScreen();
			cout << "For a short second the man with the gun paused." << endl;
			cout << "He felt a sharp pain in his side. As he looked downto chekc on what it was, he saw the face of the child standing there, tears coming down his face, jaming a knife into his side." << endl;
			cout << "'Why you little brat', he says as he shoves the kid to the side." << endl;
			cout << "The man looks at his side and touches it. His own blood cover his hands" << endl;
			cout << "At the sight of his blood he began to laugh crazyily, until finally he collapses and dies. " << endl;
			cout << "With the man with the gun lies dead on the ground, you go over to aid the father." << endl;
			cout << "'Here let me help you', you say asy you try to grab your medical supplies." << endl;
			cout << "The father then grabs your hand and shakes his head from side to side." << endl;
			sleep(15);
			clrScreen();
			cout << "'There is no need for that young one save that for those you can save, I am nothing but a old man who is ready to leave.'" << endl;
			cout << "'Honey, please don't go we need you', said the mom. 'Yeah, Dad please don't go', cried the child." << endl;
			cout << "'You guys will be fine', he implied ,'Just stick together and make it to the quantine area okay please be strong.'" << endl;
			cout << "As those words came out so did his final breath." << endl;
			cout << "You walk over to the other man body and pick up the bag of food." << endl;
			cout << "You come back over to the crying mother and give it to her." << endl;
			sleep(15);
			clrScreen();
			cout << "As she looks up she grabs the bag and takes out some of the food and hands it back to you." << endl;
			cout << "'You need this food as much as we do', she said ,'This is our thank you for trying to help us.'" << endl;
			cout << "You reply,'I'm sorry that I coudln't save your husband, If I just gotten there sooner.'" << endl;
			cout << "'No, no need to blame yourself, my husband was always like this', she said. 'He was aleays wanted to be the hero'." << endl;
			cout << "On that note she walks back to her child and and mourns with him." << endl;
			cout << "With nothing else you can do, you walk away give them the time they need." << endl;
			cout << "You've aquired 10 pieces of food." << endl;
			globalPiecesofFood += 10;
			completedPuzzles++;
			sleep(15);
			goToNextDay();
		}

	}

}

void clothingStore() {
	cout << "You are in the clothing store." << endl;
	sleep(1);
	clrScreen();
	if (randomNumberGenerator() > 5) {
		cout << "You have found 5 bandages. Would you like to take them?" << '\n';
		cout << "1 - Yes" << '\n';
		cout << "2 - No" << '\n';
		cin >> selectedOption;
		if (!cin || selectedOption > 2 || selectedOption < 1) die();
		if (selectedOption == 1) {
			globalNumberofBandages += 5;
			cout << "You now have " << globalNumberofBandages << " bandages" << '\n';
			sleep(1);
			if (rollOfDice > 5) {
				cout << "Would you like to go to the medical office or the food court?" << '\n';
				cout << "1 - Medical Office" << '\n';
				cout << "2 - Food Court" << '\n';
				cin >> selectedOption;
				if (!cin || selectedOption > 2  || selectedOption < 1) die();
				if (selectedOption == 1) {
					medicalOffice();
					sleep(1);
				} else {
					foodCourt();
					sleep(1);
				}
			}
		} else {
			cout << "You are stupid for not taking the help thus you die. #NaturalSelection" << '\n';
			haveBeenKilled();
		}
	} else {
		cout << "The store has already been raided. You should comeback another time to check for any goods." << '\n';
		sleep(1);
	}
	goToNextDay();
	main();
}

void gunStore() {
	cout << "You close up onto the gun store and peer through one of the glas display windows you see a few zombies already inside." << endl;
	cout << "You realize that there is only two options for you to do." << endl;
	cout << "You only have " << globalNumberofBullets << " bullets" << endl;
	cout << "1 - Take out your gun and shoot them." << endl;
	cout << "2 - take them out quietly one by one." << endl;
	cin >> selectedOption;
	if (!cin || selectedOption > 2 || selectedOption < 1) die();

	if (selectedOption == 1) {
		killWithGun();
	} else {
		killSilently();
	}

}

void killWithGun() {
	if (globalNumberofBullets == 0) {
		cout << "You have been killed by the zombies due to not having bullets." << endl;
		haveBeenKilled();
	} else if (globalNumberofBullets != 0) {
		for (size_t i = 0; i < globalNumberofBullets; i++) {
			cout << "Shooting zombie..." << endl;
			sleep(1);
			if (randomNumberGenerator() > 4) {
				globalNumberofGunKilledZombies++;
			} else {
				cout << "You missed try again!" << endl;
			}
			if (globalNumberofGunKilledZombies == 5) break;
		}
		cout << "You have killed " << globalNumberofGunKilledZombies << " zombies." << endl;
		if (globalNumberofGunKilledZombies >= 5) {
			cout << "You have completed the killing zombies by gun puzzle";
			completedPuzzles++;
		}
		sleep(4);
		goToNextDay();
		sleep(1);
		clrScreen();
		main();
	}
}

void killSilently() {
	for (size_t i = 0; i < 10; i++) {
		cout << "You are attacking a zombie..." << endl;
		sleep(1);
		if (randomNumberGenerator() > 3) {
			globalNumberofSilentKilledZombies++;
		} else {
			globalPlayerHeath = globalPlayerHeath * 0.95;
			cout << "Ouch!!! That one hurt" << endl;
			cout << "Your health has been dropped to: " << globalPlayerHeath << endl;
		}
		if (globalNumberofSilentKilledZombies == 2) break;
	}
	cout << "You have killed " << globalNumberofSilentKilledZombies << " zombies silently." << endl;
	if (globalNumberofSilentKilledZombies >= 2) {
		cout << "You have completed the killing zombies silently puzzle.";
		completedPuzzles++;
		cout << "You have completed " << completedPuzzles << " of 5" << endl;
	}
	sleep(4);
	goToNextDay();
	sleep(1);
	clrScreen();
	main();
}

void day1BullShit() {
	char enter;
	clrScreen();

	//Title
	cout <<  "Hi, welcome to the SURVIVING ALONE." << endl;
	cout << "To start the game please prese [ENTER] ";
	cin.get(enter);
	clrScreen();
	sleep(1);

	cout <<  "My name is Iris and I will be your AI companion throughout this journey" << endl;
	cout <<  "Our story starts in the year 2100." << endl;
	cout <<  "During this time a toxic and viral virus has spread throughtout the population, turing the people into mad and zombie-like creatures." << endl;
	cout <<  "This virus turned the world into a wasteland." << endl << endl;

	//Player Name
	cout << "For us to get a better sense of who you are pleae enter your name: ";
	getline(cin, globalPlayerName);
	if (!cin) die();
	clrScreen();

	cout << "You will follow the story of " + globalPlayerName + " in their daily survival within this post-apocalyptic crisis" << endl;
	clrScreen();

	cout << "Day " << dayCnt << endl;
	cout << "Setting: Los Angles" << endl;
	cout << "You are driving down the highway to the abandon city of Los Angles. You have been out on the road for days." << endl;
	cout << "You look at your supplies and see that you have very little left." << endl;
	cout << "A few cans of food, 3 bandages, and 1 gallon of water" << endl;
	cout << "You were also on your last gallon of gas" << endl;
	cout << "As you drive in into the abandon streets of Los Angles, you notice a mall with loads of cars within the parking lot" << endl;
	cout << "You turn into the parking lot to refill on all of your supplies" << endl << endl;
	cout << "1) Siphon the Cars for gas" << endl;
	cout << "2) Go straight into the mall to look for the other supplies there" << endl;
	cout << "However you first need to choose which supplies you like to collect first: ";
	cin >> selectedOption;
	if (!cin || selectedOption < 1 || selectedOption > 2) die();

	if (selectedOption == 1) {
		clrScreen();
		cout << "You begin to siphon out the gas from the car, until you begin to hear grunts from the road you came from." << endl;
		cout << "You look in the direction and begin to panic. There across the road you see a bunch of zombies pop out between the alleys of the buildings." << endl;
		cout << "You frantically start to bring back the tube within the gas tank of the car and began carfully walking to your car." << endl;
		cout << "However, as soon as you start moving the zombies spot you. To far from the safety of you own car. you began running in the direction of the mall." << endl;
		cout << endl;
		sleep(18);
		cout << "While running you begin to look back to see how far the zombies are to reaching you and to your horror it alot worse." << endl;
		cout << "Emerging from the shadows of the alleys, more and more zombies came. You did not step upon a group of zombies but a hoard instead." << endl;
		cout << "You begin to run faster and faster until you reached the entrance of the mall. As you quickly walk in you, wihtout paying much attension, you foot it triped by the uneven ground below." << endl;
		cout << "You fall down the escaltor stairs and black out." << endl;
		cout << endl;
		sleep(25);
		clrScreen();
		cout << "You wake up hours later on the floor of the mall." << endl;
		cout << "Your as you begin to move he hear loud grunting sounds all around you." << endl;
		cout << "Sacred, you open your eyes to see about 5-6 zombies walking all around you." << endl;
		cout << "Out the corner of your eye you spot two store which sutible places to hide in" << endl;

		cout << "1 - The Clothing Store" << endl;
		cout << "2 - The Medical Office" << endl;
		cin >> currentStore;

		if (!cin || currentStore > 2 || currentStore < 1) {
			die();
		}

		if (currentStore == 1) {
			clrScreen();
			//Create a function that creates a random experience everytime you enter the clothing store.
			clothingStore();
			amountOfRolls = 5;
		} else {
			clrScreen();
			//Create a function that creates a random experience everytime you enter the medical office.
			medicalOffice();
			amountOfRolls = 5;
		}

	} else {

		clrScreen();
		cout << "You begin to walk to the mall" << endl;
		cout << "As you approach the doors you check the inside first to make sure that no on else is around." << endl;
		cout << "Seeing no one, you enter in the mall and see alot of stores. The stores varied from a gun shop to the food court." << endl;
		cout << "However you are not able to get a good glance at any of them, because in the reflection of the mall map glass you begin to see a hoard of zombies emerge form the shadows of the alley ways" << endl;
		cout << "To far from the car to get out of there you are force to choose between the two store closes that peak you attetion the first time you came in." << endl;
		cout << "1 - The Gun Store" << endl;
		cout << "2 - The Food Court" << endl;

		cin >> selectedOption;
		if (!cin || selectedOption < 1 || selectedOption > 2) die();

		if (selectedOption == 1) {
			sleep(4);
			gunStore();
		} else {
			sleep(4);
			foodCourt();
		}
	}
}

void multiDay(int dayCounter) {
	clrScreen();
	cout << "Day " <<  dayCounter << endl;
	if (currentStore == 1) {
		cout << "You are in the Clothing Store." << endl;
		sleep(4);
		clothingStore();
	} else if (currentStore == 2) {
		cout << "You are in the Medical Office." << endl;
		sleep(4);
		medicalOffice();
	} else if (currentStore == 3) {
		cout << "You are in the Gun Shop." << endl;
		sleep(4);
		gunStore();
	} else if (currentStore == 4) {
		cout << "You are in the Food Court." << endl;
		sleep(4);
		foodCourt();
	}

}

int main() {

	while (globalPlayerHeath > 0) {
		if (completedPuzzles == 5) {
			winnerChickenDinner();
		}

		if (amountOfRolls <= 5) {
			dayCnt++;
		}

		if (dayCnt == 1) {
			day1BullShit();
		} else {
			clrScreen();
			multiDay(dayCnt);
		}
	}

}

void goToNextDay() {
	sleep(1);
	clrScreen();
	amountOfRolls++;
	cout << "You have worked hard for today time to go to sleep and get some rest." << endl;
	clrScreen();
	for (int i = 0; i < 2; i++) {
		cout << "ZZZZZZZZZZZZZZZZ......" << endl;
		sleep(1);
		clrScreen();
	}
	main();
}


