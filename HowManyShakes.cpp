#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	const int NUM_DICE = 2;
	const int DICE_MAX = 6;
	const int DICE_MIN = 1;
	int firstDieRoll = 0;
	int secondDieRoll = 0;
	int numShakes = 0;
	int targetTotal = 0;
	int sumDice;
	int diceTotal;

	srand(time(0));
	cout << "Enter a total: " << endl;
	cin >> targetTotal;

	while (targetTotal >= NUM_DICE * DICE_MIN) && (targetTotal <= NUM_DICE * DICE_MAX)) {
		numShakes = 1;
		do {
			diceTotal = 0;
			firstDieRoll = rand() % 6 + 1;
			secondDieRoll = rand() % 6 + 1;
			sumDice = firstDieRoll + secondDieRoll;
			cout << "Shake " << numShakes << ": " << firstDieRoll << " " << secondDieRoll << " = " << sumDice << endl;
			numShakes++;
		} while (targetTotal != sumDice);

		cout << "Enter a total: " << endl;
		cin >> targetTotal;

		cout << firstDieRoll << " ";
		cout << secondDieRoll;

	}





	cout << endl << "Goodbye.";
	return 0;
}