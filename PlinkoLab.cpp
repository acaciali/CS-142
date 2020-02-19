/*
Main Lab 4: Plinko
Sadie Tayler, sadietayler@gmail.com, Section 6
Acacia Ricks, alricks1922@gmail.com, Section 4
Created with proper pair programming, in Visual Studio
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>



using namespace std;

int main() {
	const int RANDOM_SEED = 42;
	int userChoice;
	int userSlot;
	int numberOfChips;
	double slotPosition;
	double winnings;
	double totalWinnings;
	double avgWinPerChip;

	srand(RANDOM_SEED);

	cout << "Welcome to the Plinko simulator! Enter 3 to see options.\n" << endl;
	cout << "Enter your selection now:" << endl;
	cin >> userChoice;

	while (userChoice != 4) {

		if (userChoice == 1) {
			cout << "*** Drop a single chip ***\n" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
			cin >> userSlot;

			if (userSlot >= 0 && userSlot <= 8) {
				cout << "*** Dropping chip into slot " << userSlot << " ***" << endl;
				cout << fixed << setprecision(1) << "Path: [" << static_cast<double>(userSlot) << ", ";
				slotPosition = static_cast<double>(userSlot);

				for (int i = 0; i < 12; i++) {
					if (slotPosition == 8) {
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

					if (i != 11) {
						cout << fixed << setprecision(1) << slotPosition << ", ";
					}
					else {
						cout << fixed << setprecision(1) << slotPosition << "]" << endl;
					}
				}

				if (slotPosition == 3.0 || slotPosition == 5.0) {
					winnings = 0.00;
					cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
				}
				else if (slotPosition == 0.0 || slotPosition == 8.0) {
					winnings = 100.00;
					cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
				}
				else if (slotPosition == 1.0 || slotPosition == 7.0) {
					winnings = 500.00;
					cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
				}
				else if (slotPosition == 2.0 || slotPosition == 6.0) {
					winnings = 1000.00;
					cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
				}
				else if (userSlot == 4) {
					winnings = 10000.00;
					cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
				}
			}

			else {
				cout << "Invalid slot." << endl;
			}
		}


		else if (userChoice == 2) {
			cout << "*** Drop multiple chips ***\n" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl;
			cin >> numberOfChips;

			if (numberOfChips <= 0) {
				cout << "Invalid number of chips." << endl;
			}
			else {
				cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
				cin >> userSlot;

				if (userSlot >= 0 && userSlot <= 8) {
					totalWinnings = 0.0;

					for (int i = 0; i < numberOfChips; i++) {
						slotPosition = static_cast<double>(userSlot);

						for (int i = 0; i < 12; i++) {
							if (slotPosition == 8) {
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
						}

						if (slotPosition == 3.0 || slotPosition == 5.0) {
							totalWinnings += 0.00;
						}
						else if (slotPosition == 0.0 || slotPosition == 8.0) {
							totalWinnings += 100.00;
						}
						else if (slotPosition == 1.0 || slotPosition == 7.0) {
							totalWinnings += 500.00;
						}
						else if (slotPosition == 2.0 || slotPosition == 6.0) {
							totalWinnings += 1000.00;
						}
						else if (slotPosition == 4.0) {
							totalWinnings += 10000.00;
						}

					}

					cout << fixed << setprecision(2) << "Total winnings on " << numberOfChips << " chips: $" << totalWinnings << endl;
					avgWinPerChip = totalWinnings / numberOfChips;
					cout << "Average winnings per chip: $" << avgWinPerChip << endl;
				}

				else {
					cout << "Invalid slot." << endl;
				}
			}
		}


		else if (userChoice == 3) {
			cout << "Menu: Please select one of the following options:\n " << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl;
		}


		else {
			cout << "Invalid selection. Enter 3 to see options." << endl;
		}

		cout << "Enter your selection now:" << endl;
		cin >> userChoice;
	}

	cout << "Goodbye!" << endl;
	system("pause");
	return 0;
}