#include <iosteam>
using namespace std;

int main() {
	int moneyValue = 0;
	int selectedFunc = 0;
	int dollarAmmount = 0;

	cout << "Would you like to deposit or withdrawl? " << endl;
	cout << "1 for deposit and 2 for withdrawl: ";
	cin >> selectedFunc;

	if (!cin) {
		cout << "You selected an invalid function." << endl;
		cout << "You have " << moneyValue << " left in your bank account" << endl;
	//Deposit
	} else if (selectedFunc == 1) {
		cout << "How much would you like to deposit? ";
		cin >> dollarAmmount;

		if (dollarAmmount < 0 or dollarAmmount == 0) {
			cout << "What are you trying to do asshole?" << endll
		} else {
			moneyValue += dollarAmmount;
			cout << "You now have: $" << moneyValue << endl;
		}

	} else if (selectedFun == 2) {
		cout << "How much would you like to take out?" << endl << "You have " << moneyValue << " left in your account." << endl;
		cin >> dollarAmmount;

		if (dollarAmmount > moneyValue) {
			cout << "Your a poor asshole. Comeback when you get some money" << endl;
		}
		
	}
}
