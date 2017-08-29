#include <iostream>
using namespace std;

void die() {
	cout << "BAD INPUT\n";
	exit(1);
}

int main() {
	cout << "Welcome to the IfCorp Retirement Calculator.\n";
	cout << "Please consult a financial advisor and not rely\n";
	cout << " on a homework assignment for actual financial advice.\n";
	cout << "Please press 1 and hit return to continue:\n";
	int input = 0;
	cin >> input;
	if (!cin || input != 1) die();
	float retirement_balance = 0;
	cout << "Please enter: Current retirement balance:\n";
	//YOU: Input into retirement_balance and vet the input
	cin >> retirement_balance;

	if (retirement_balance < 0 || retirement_balance > 100000000000 || !cin) {
		die();
	}

	float years_to_retirement = 0;
	cout << "Please enter: Years to retirement:\n";
	//YOU: Input into years_to_retirement and vet the input
	cin >> years_to_retirement;
	if (years_to_retirement < 0.082 || years_to_retirement > 60 || !cin) {
		die();
	}

	float monthly_contribution = 0;
	cout << "Please enter: Monthly contribution:\n";
	//YOU: Input into monthly_contribution and vet the input
	cin >> monthly_contribution;
	if (monthly_contribution < 0 || monthly_contribution > 1000000 || !cin) {
		die();
	}
	//Example: if this is 10, this means your entire
	//investment will be increased by 10% (x1.1) at the
	//end of the investment period.
	float average_interest_rate = 0;
	cout << "Please enter: Average interest rate across total investment:\n";
	//YOU: Input into average_interest_rate and vet the input
	//     If they type a bad value, just call die();
	cin >> average_interest_rate;
	if (average_interest_rate < 0 || average_interest_rate > 1000 || !cin) {
		die();
	}
	float target = 0;
	cout << "Please enter: Your goal for how much money to have upon retirement:\n";
	//YOU: Input into target and vet the input
	cin >> target;
	if (target < 0 || target > 1000000000000 || !cin) {
		die();
	} else {
		double totalMoniesToInvest = ((monthly_contribution * 12) * years_to_retirement) + retirement_balance;
		double interestMonies = totalMoniesToInvest * (1 + ((average_interest_rate / 100) * years_to_retirement));
		if (interestMonies > target || interestMonies == target) {
			cout << "Congrats, you will be fine when you retire.\n";
		} else if (interestMonies < target) {
			cout << "Sorry, but you will need to invest more into retirement.\n";
		}
	}
	//YOU: Do the computations for how much money they will have at retirement

	//YOU: Compare the total amount they'll have with the target

	//YOU: If they will have enough, then print:

	//YOU: If they will not have enough, then print:

}
