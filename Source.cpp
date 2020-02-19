/*
* Main Lab 7: Restaurants
* Acacia Ricks, Section 4, alricks1922@gmail.com
*
* Test Case #1: 
* Input: (add, Tucanos, add, Burger King, add, Wendys, add McDonalds, shuffle, display, remove, McDonalds, display, quit)
* Expected Output: (Tucanos has been added, Burger King has been added, Wendys has been added, McDonalds has been added, 
* "Wendys", "Tucanos", "McDonalds", "Burger King", McDonalds has been removed, "Wendys", "Tucanos", "Burger King", Goodbye!) 
* Result: Passed
*
* Test Case #2: 
* Input: (add, Wendys, add, Taco Bell, add, Chick-Fil-A, cut, 2, display, quit)
* Expected Output: (Wendys has been added, Taco Bell has been added, Chick-Fil-a has been added, 
* "Chick-Fil-A", "Wendys", "Taco Bell", Goodbye!)
* Result: Passed
*
* Test Case #3:
* Input: (add, Wendys, add, Costa Vida, add, Arbys, battle, add, Chick-Fil-A, battle, 2, 1, 2)
* Expected Output: (Wendys has been added, Costa Vida has been added, Arbys has been added, 
* The current tournament size (3) is not a power of two (2, 4, 8...). A battle is not possible.
* Please add or remove restaurants. Chick-Fil-A has been added, The winning restaurant is Arbys. Goodbye!)
* Result: Passed
*/

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;
int numberOfRestaurants = 0;
vector<string> restaurantList(numberOfRestaurants);

void ShowOptions() {

	cout << "Please select one of the following options: " << endl << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
}

void DisplayList() {

	cout << "Here are the current restaurants:" << endl << endl;
	for (int i = 0; i < numberOfRestaurants; i++) {
		cout << "\t\"" << restaurantList.at(i) << "\"" << endl;
	}
	cout << endl;
}

bool CheckRestaurantRedundancy(string restaurantToCheck) {

	bool existsAlready = false; 
	for (int i = 0; i < numberOfRestaurants; i++) {
		if (restaurantList.at(i) == restaurantToCheck) {
			existsAlready = true; 
		}
	}
	return existsAlready; 
}

void AddRestaurant(string newRestaurant) {
	
	if (!CheckRestaurantRedundancy(newRestaurant)) {
		restaurantList.push_back(newRestaurant); 
		cout << newRestaurant << " has been added." << endl << endl;
		numberOfRestaurants++; 
	}
	else {
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
	}
}

void RemoveRestaurant(string newRestaurant) {
	
	if (CheckRestaurantRedundancy(newRestaurant)) {
		for (int i = 0; i < numberOfRestaurants; i++) {
			if (restaurantList.at(i) == newRestaurant) {
				restaurantList.erase(restaurantList.begin() + i);
				numberOfRestaurants--;
			}
		}
		cout << newRestaurant << " has been removed." << endl << endl;
	}
	else {
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}
}

int CheckInt(int rangeStart = 0, int rangeEnd = numberOfRestaurants) {

	int userInput = 0;
	cin >> userInput;

	while (cin.fail() || userInput < rangeStart || userInput > rangeEnd) {
		cout << "The cut number must be between 0 and " << numberOfRestaurants << endl;
		cout << "How many restaurants should be taken from the top and put on the bottom? " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> userInput;
	}
	return userInput;
}

	

vector<string> Cut(int cutPosition) {

	vector<string> cutDeck;
	if (cutPosition == numberOfRestaurants || cutPosition == 0) {
		for (int i = 0; i < numberOfRestaurants; i++) {
			cutDeck.push_back(restaurantList.at(i));
		}
	}
	else {
		for (int i = cutPosition; i < numberOfRestaurants; i++) {
			cutDeck.push_back(restaurantList.at(i));
		}
		for (int i = 0; i < cutPosition; i++) {
			cutDeck.push_back(restaurantList.at(i));
		}
	}
	restaurantList = cutDeck; 
	return restaurantList; 
}

bool PowerOfTwo(int numberToCheck) {

	bool number = false; 
	unsigned checkNum = numberToCheck; 
	if (checkNum && !(checkNum & (checkNum - 1))) {
		number = true;
	}

	return number;
}
void Shuffle() {

	vector<string> secondHalf;
	vector<string> firstHalf;
	vector<string> shuffleString;
	if (PowerOfTwo(numberOfRestaurants)) {
		for (int i = (numberOfRestaurants / 2); i < numberOfRestaurants; i++) {
			secondHalf.push_back(restaurantList.at(i)); 
		}
		for (int i = 0; i < numberOfRestaurants / 2; i++) {
			firstHalf.push_back(restaurantList.at(i)); 
		}
		for (int i = 0; i < numberOfRestaurants / 2; i++) {
			shuffleString.push_back(secondHalf.at(i));
			shuffleString.push_back(firstHalf.at(i));
		}
		restaurantList = shuffleString;
	}
	else {
		cout << "The current tournament size(" << numberOfRestaurants << ") is not a power of two(2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}
}

vector<string> GetWinner(vector<string> winnerVec, int winnerVecSize) {

	string contestant1;
	string contestant2; 
	string userChoice = "";
	bool validChoice = false;
	vector<string> winners;

	for (int i = 0; i < winnerVecSize; i++) {
		
		contestant1 = winnerVec.at(i); 
		contestant2 = winnerVec.at(i + 1); 
		validChoice = false; 
		while (!validChoice) {
			cout << "Type \"1\" if you prefer " << contestant1 << " or" << endl;
			cout << "type \"2\" if you prefer " << contestant2 << endl;
			cout << "Choice: " << endl;
			
			cin >> userChoice; 

			if (userChoice == "1") {
				winners.push_back(contestant1); 
				validChoice = true;
				if (!(i == (winnerVecSize - 1))) {
					i++;
				}
			}
			else if (userChoice == "2") {
				winners.push_back(contestant2); 
				validChoice = true;
				if (!(i == (winnerVecSize - 1))) {
					i++;
				}
			}
			else {
				cout << "Invalid choice" << endl;
				validChoice = false;
			}
		}
	}
	winnerVec = winners;
	return winnerVec; 
}

void Battle() {
	
	vector<string> restaurants = restaurantList;
	int numRests = numberOfRestaurants;
	int numRounds = sqrt(numberOfRestaurants);

	if (PowerOfTwo(numberOfRestaurants)) {
		for (int i = 0; i < numRounds; i++) {
			cout << "Round: " << i + 1 << endl << endl;
			restaurants = GetWinner(restaurants, restaurants.size());
		}
		cout << "The winning restaurant is " << restaurants.at(0) << "." << endl;
	}
	else {
		cout << "The current tournament size (" << numberOfRestaurants << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
	}
}


int main() {

	vector<string> Restaurants();
	string userInput = "";
	
	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl << endl;
	cout << "Enter your selection: " << endl;
	cin >> userInput; 

	while (userInput != "quit") {
		if (userInput == "options") {
			ShowOptions(); 
		}
		else if (userInput == "display") {
			DisplayList();
		}
		else if (userInput == "add") {
			cout << "What is the name of the restaurant you want to add? " << endl;
			string addRestaurant;
			cin.ignore(); 
			getline(cin, addRestaurant);
			AddRestaurant(addRestaurant);
		}
		else if (userInput == "remove") {
			cout << "What is the name of the restaurant you want to remove? " << endl;
			string removeRestaurant;
			cin.ignore(); 
			getline(cin, removeRestaurant);
			RemoveRestaurant(removeRestaurant);
		}
		else if (userInput == "cut") {
			int userInt = 0; 
			cout << "How many restaurants should be taken from the top and put on the bottom? " << endl;
			userInt = CheckInt(); 
			Cut(userInt);
		}
		else if (userInput == "shuffle") {
			Shuffle();
		}
		else if (userInput == "battle") {
			Battle();
		}
		else {
			cout << "Invalid Selection" << endl;
			ShowOptions();
		}
		
		cout << "Enter your selection: " << endl;
		cin >> userInput;
	}
	cout << "Goodbye!" << endl;

	system("pause");
	return 0;
}