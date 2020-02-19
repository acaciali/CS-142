/*
Main Lab 6: Plinko Lab with Functions
Acacia Ricks, alricks1922@gmail.com, Section 4
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <climits>

using namespace std;
const int NUM_ROWS = 12;
const int NUM_SLOTS = 9;

int CheckInput(string typeCheck, int rangeStart = 0, int rangeEnd = numeric_limits<int>::max()) {
	int userInput = 0;
	cin >> userInput;

	while (cin.fail() || userInput < rangeStart || userInput > rangeEnd) {
		if (typeCheck == "selection") {
			cout << "Invalid selection. Enter 4 to see options." << endl << endl;
			cout << "Enter your selection now: " << endl;
		}
		if (typeCheck == "slot") {
			cout << "Invalid slot." << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-" << NUM_SLOTS - 1 << ")?" << endl;
		}
		if (typeCheck == "chips") {
			cout << "Invalid number of chips." << endl;
			cout << "How many chips do you want to drop(> 0) ?" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> userInput;
	}

	return userInput;
}

double ComputeWinnings(int slot) {
	const double AWARDS_ARRAY[NUM_SLOTS] = { 100.00, 500.00, 1000.00, 0.00, 10000.00, 0.00, 1000.00, 500.00, 100.00 };

	return AWARDS_ARRAY[slot];
}

double DropOneChip(int dropSlot, bool printPath = false) {
	double slotPosition;
	slotPosition = static_cast<double>(dropSlot);

	for (int i = 0; i < NUM_ROWS; i++) {
		if (slotPosition == NUM_SLOTS - 1) {
			slotPosition -= 0.5;
		}
		else if (slotPosition == 0) {
			slotPosition += 0.5;
		}
		else {
			if (rand() % 2 == 0) {
				slotPosition -= 0.5;
			}
			else {
				slotPosition += 0.5;
			}
		}

		if (printPath) {
			if (i != NUM_ROWS - 1) {
				cout << fixed << setprecision(1) << slotPosition << ", ";
			}
			else {
				cout << fixed << setprecision(1) << slotPosition << "]" << endl;
			}
		}
	}

	return ComputeWinnings(static_cast <int>(slotPosition));
}

double DropMultipleChips(int numChips, int userSlot) {
	double userWinnings = 0;

	for (int i = 0; i < numChips; i++) {
		userWinnings += DropOneChip(userSlot);
	}

	return userWinnings;
}

int main() {
	const int RANDOM_SEED = 42;
	int userChoice;
	int userSlot;
	int numberOfChips;
	double totalWinnings;
	double avgWinPerChip;

	srand(RANDOM_SEED);

	cout << "Welcome to the Plinko simulator! Enter 4 to see options.\n" << endl;
	cout << "Enter your selection now:" << endl;
	userChoice = CheckInput("selection", 1, 5);
	while (userChoice != 5) {

		if (userChoice == 1) {
			cout << "*** Drop a single chip ***\n" << endl;
			cout << "Which slot do you want to drop the chip in (0-" << NUM_SLOTS - 1 << ")?" << endl;
			userSlot = CheckInput("slot", 0, NUM_SLOTS - 1);

			cout << "*** Dropping chip into slot " << userSlot << " ***" << endl;
			cout << fixed << setprecision(1) << "Path: [" << static_cast<double>(userSlot) << ", ";
			cout << fixed << setprecision(2) << "Winnings: $" << DropOneChip(userSlot, true) << endl;
		}

		else if (userChoice == 2) {
			totalWinnings = 0;
			cout << "*** Drop multiple chips ***\n" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl;
			numberOfChips = CheckInput("chips", 1);

			cout << "Which slot do you want to drop the chip in(0 - " << NUM_SLOTS - 1 << ") ? " << endl;
			userSlot = CheckInput("slot", 0, NUM_SLOTS - 1);

			totalWinnings = DropMultipleChips(numberOfChips, userSlot);

			cout << fixed << setprecision(2) << "Total winnings on " << numberOfChips << " chips: $" << totalWinnings << endl;
			avgWinPerChip = totalWinnings / numberOfChips;
			cout << "Average winnings per chip: $" << avgWinPerChip << endl;
		}

		else if (userChoice == 3) {
			totalWinnings = 0;
			cout << "*** Sequentially drop multiple chips ***" << endl << endl;
			cout << "How many chips do you want to drop (>0)?" << endl << endl;
			int numberChips = CheckInput("chips", 1);

			for (int i = 0; i < NUM_SLOTS; i++) {
				totalWinnings = 0;
				totalWinnings = DropMultipleChips(numberChips, i);
				cout << fixed << setprecision(2) << "Total winnings on " << numberChips << " chips in slot " << i << ": $" << totalWinnings << endl;
				avgWinPerChip = totalWinnings / numberChips;
				cout << "Average winnings per chip: $" << avgWinPerChip << endl << endl;
			}
		}

		else if (userChoice == 4) {
			cout << "Menu: Please select one of the following options:\n " << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Drop multiple chips into each slot" << endl;
			cout << "4 - Show the options menu" << endl;
			cout << "5 - Quit the program" << endl;
		}

		cout << "Enter your selection now:" << endl;
		userChoice = CheckInput("selection", 1, 5);
	}

	cout << "Goodbye!" << endl;
}