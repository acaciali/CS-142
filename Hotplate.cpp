//
///* Mikayla Cheng, mikaylacheng@gmail.com, Section 004
// * Acacia Ricks, alricks1922@gmail.com, Section 004
// * Used proper pair programming
// * This program computes the steady state temperature distribution over a piece of metal.
// */
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <array>
//#include <fstream>
//#include <cmath>
//
//using namespace std;
//
//int main()
//{
//
//	const int NUM_ROWS = 10;
//	const int NUM_COLUMNS = 10;
//	const int DATA_PRECISION = 3;
//	const int DATA_WIDTH = 9;
//	double oldTemperatures[NUM_ROWS][NUM_COLUMNS];
//	double newTemperatures[NUM_ROWS][NUM_COLUMNS];
//	double maxDifference = 1;
//
//	ofstream outputFile;
//	ifstream inputFile;
//
//	cout << "Hotplate simulator" << endl << endl;
//
//	cout << "Printing initial plate..." << endl;
//
//
//	for (int i = 0; i < NUM_ROWS; ++i)
//	{
//		for (int j = 0; j < NUM_COLUMNS; ++j)
//		{
//			oldTemperatures[i][j] = 0.0;
//
//			if ((j != 0 && j != NUM_COLUMNS - 1) && (i == 0 || i == NUM_ROWS - 1))
//			{
//				oldTemperatures[i][j] = 100.0;
//
//			}
//
//			if (j != NUM_COLUMNS - 1)
//			{
//				cout << setw(DATA_WIDTH) << fixed << setprecision(DATA_PRECISION) << oldTemperatures[i][j] << ",";
//			}
//			else
//			{
//				cout << setw(DATA_WIDTH) << fixed << setprecision(DATA_PRECISION) << oldTemperatures[i][j] << endl;
//			}
//
//		}
//	}
//	cout << endl;
//
//	for (int i = 0; i < NUM_ROWS; ++i)
//	{
//		for (int j = 0; j < NUM_COLUMNS; ++j)
//		{
//			newTemperatures[i][j] = 0.0;
//
//			if ((j != 0 && j != NUM_COLUMNS - 1) && (i == 0 || i == NUM_ROWS - 1))
//			{
//				newTemperatures[i][j] = 100.0;
//			}
//
//			if ((i >= 1 && i <= NUM_ROWS - 2) && (j >= 1 && j <= NUM_COLUMNS - 2))
//			{
//				newTemperatures[i][j] = (oldTemperatures[i - 1][j] + oldTemperatures[i][j + 1] + oldTemperatures[i + 1][j] + oldTemperatures[i][j - 1]) / 4.0;
//			}
//		}
//	}
//
//	cout << "Printing plate after one iteration..." << endl;
//
//	for (int i = 0; i < NUM_ROWS; i++)
//	{
//		for (int j = 0; j < NUM_COLUMNS - 1; j++)
//		{
//			cout << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION) << newTemperatures[i][j] << ", ";
//		}
//
//		cout << newTemperatures[i][NUM_COLUMNS - 1] << endl;
//	}
//
//	while (maxDifference > 0.1)
//	{
//		maxDifference = 0;
//
//		for (int i = 0; i < NUM_ROWS; ++i)
//		{
//			for (int j = 0; j < NUM_COLUMNS; ++j)
//			{
//				if ((i >= 1 && i <= NUM_ROWS - 2) && ((j) >= 1 && j <= NUM_COLUMNS - 2))
//				{
//					newTemperatures[i][j] = (oldTemperatures[i - 1][j] + oldTemperatures[i][j + 1] + oldTemperatures[i + 1][j] + oldTemperatures[i][j - 1]) / 4;
//
//				}
//			}
//		}
//
//		for (int i = 0; i < NUM_ROWS; ++i)
//		{
//			for (int j = 0; j < NUM_COLUMNS; ++j)
//			{
//
//				if (fabs(oldTemperatures[i][j] - newTemperatures[i][j]) > maxDifference)
//				{
//					maxDifference = fabs(oldTemperatures[i][j] - newTemperatures[i][j]);
//				}
//			}
//		}
//
//		for (int i = 0; i < NUM_ROWS; ++i)
//		{
//			for (int j = 0; j < NUM_COLUMNS; ++j)
//			{
//				oldTemperatures[i][j] = newTemperatures[i][j];
//			}
//		}
//	}
//
//	cout << endl << "Printing final plate..." << endl;
//
//	for (int i = 0; i < NUM_ROWS; i++)
//	{
//		for (int j = 0; j < NUM_COLUMNS - 1; j++)
//		{
//			cout << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION) << newTemperatures[i][j] << ", ";
//		}
//
//		cout << newTemperatures[i][NUM_COLUMNS - 1] << endl;
//	}
//	cout << endl;
//
//
//	outputFile.open("Hotplate.csv");
//
//	if (!outputFile.is_open())
//	{
//		cout << "Could not open file myoutfile.txt." << endl;
//		return 1;
//	}
//
//
//	for (int i = 0; i < NUM_ROWS; i++)
//	{
//		for (int j = 0; j < NUM_COLUMNS - 1; j++)
//		{
//			outputFile << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION);
//			outputFile << newTemperatures[i][j] << ", ";
//		}
//		outputFile << newTemperatures[i][NUM_COLUMNS - 1] << endl;
//
//	}
//
//	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl << endl;
//
//	inputFile.open("Inputplate.txt");
//
//	if (!inputFile.is_open())
//	{
//		cout << "File not found" << endl;
//		return 1;
//	}
//
//	if (!inputFile.fail())
//	{
//		for (int i = 0; i < NUM_ROWS; i++)
//		{
//			for (int j = 0; j < NUM_COLUMNS; j++)
//			{
//				inputFile >> oldTemperatures[i][j];
//			}
//		}
//	}
//
//	for (int n = 0; n < 3; n++)
//	{
//		for (int i = 1; i <= NUM_ROWS - 2; i++)
//		{
//			for (int j = 1; j <= NUM_COLUMNS - 2; j++)
//			{
//				newTemperatures[i][j] = (oldTemperatures[i - 1][j] + oldTemperatures[i][j + 1] + oldTemperatures[i + 1][j] + oldTemperatures[i][j - 1]) / 4.0;
//			}
//
//		}
//
//		for (int k = 0; k < NUM_ROWS; k++)
//		{
//			for (int l = 0; l < NUM_COLUMNS; l++)
//			{
//				oldTemperatures[k][l] = newTemperatures[k][l];
//			}
//		}
//	}
//
//
//	cout << "Printing input plate after 3 updates..." << endl;
//	for (int i = 0; i < NUM_ROWS; i++)
//	{
//		for (int j = 0; j < NUM_COLUMNS - 1; j++)
//		{
//			cout << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION) << newTemperatures[i][j] << ", ";
//		}
//
//		cout << newTemperatures[i][NUM_COLUMNS - 1] << endl;
//	}
//
//
//	cout << endl;
//	system("pause");
//	inputFile.close();
//	outputFile.close();
//
//	cout << endl;
//	return 0;
//
//}


/* Mikayla Cheng, mikaylacheng@gmail.com, Section 004
 * Acacia Ricks, alricks1922@gmail.com, Section 004
 * Used proper pair programming
 * This program computes the steady state temperature distribution over a piece of metal.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

	const int NUM_ROWS = 10;
	const int NUM_COLUMNS = 10;
	const int DATA_PRECISION = 3;
	const int DATA_WIDTH = 9;
	double oldTemperatures[NUM_ROWS][NUM_COLUMNS];
	double newTemperatures[NUM_ROWS][NUM_COLUMNS];
	double maxDifference = 1;

	ofstream outputFile;
	ifstream inputFile;

	cout << "Hotplate simulator" << endl << endl;

	cout << "Printing initial plate..." << endl;


	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < NUM_COLUMNS; ++j)
		{
			oldTemperatures[i][j] = 0.0;

			if ((j != 0 && j != NUM_COLUMNS - 1) && (i == 0 || i == NUM_ROWS - 1))
			{
				oldTemperatures[i][j] = 100.0;

			}

			if (j != NUM_COLUMNS - 1)
			{
				cout << setw(DATA_WIDTH) << fixed << setprecision(DATA_PRECISION) << oldTemperatures[i][j] << ",";
			}
			else
			{
				cout << setw(DATA_WIDTH) << fixed << setprecision(DATA_PRECISION) << oldTemperatures[i][j] << endl;
			}

		}
	}
	cout << endl;

	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < NUM_COLUMNS; ++j)
		{
			newTemperatures[i][j] = 0.0;

			if ((j != 0 && j != NUM_COLUMNS - 1) && (i == 0 || i == NUM_ROWS - 1))
			{
				newTemperatures[i][j] = 100.0;
			}

			if ((i >= 1 && i <= NUM_ROWS - 2) && ((j) >= 1 && j <= NUM_COLUMNS - 2))
			{
				newTemperatures[i][j] = (oldTemperatures[i - 1][j] + oldTemperatures[i][j + 1] + oldTemperatures[i + 1][j] + oldTemperatures[i][j - 1]) / 4.0;
			}
		}
	}

	cout << "Printing plate after one iteration..." << endl;

	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS - 1; j++)
		{
			cout << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION) << newTemperatures[i][j] << ", ";
		}

		cout << newTemperatures[i][NUM_COLUMNS - 1] << endl;
	}

	while (maxDifference > 0.1)
	{
		maxDifference = 0;

		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLUMNS; ++j)
			{
				if ((i >= 1 && i <= NUM_ROWS - 2) && ((j) >= 1 && j <= NUM_COLUMNS - 2))
				{
					newTemperatures[i][j] = (oldTemperatures[i - 1][j] + oldTemperatures[i][j + 1] + oldTemperatures[i + 1][j] + oldTemperatures[i][j - 1]) / 4;

				}
			}
		}

		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLUMNS; ++j)
			{

				if (fabs(oldTemperatures[i][j] - newTemperatures[i][j]) > maxDifference)
				{
					maxDifference = fabs(oldTemperatures[i][j] - newTemperatures[i][j]);
				}
			}
		}

		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLUMNS; ++j)
			{
				oldTemperatures[i][j] = newTemperatures[i][j];
			}
		}
	}

	cout << endl << "Printing final plate..." << endl;

	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS - 1; j++)
		{
			cout << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION) << newTemperatures[i][j] << ", ";
		}

		cout << newTemperatures[i][NUM_COLUMNS - 1] << endl;
	}
	cout << endl;


	outputFile.open("Hotplate.csv");

	if (!outputFile.is_open())
	{
		cout << "Could not open file myoutfile.txt." << endl;
		return 1;
	}


	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS - 1; j++)
		{
			outputFile << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION);
			outputFile << newTemperatures[i][j] << ", ";
		}
		outputFile << newTemperatures[i][NUM_COLUMNS - 1] << endl;

	}

	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl << endl;

	inputFile.open("Inputplate.txt");

	if (!inputFile.is_open())
	{
		cout << "File not found" << endl;
		return 1;
	}

	if (!inputFile.fail())
	{
		for (int i = 0; i < NUM_ROWS; i++)
		{
			for (int j = 0; j < NUM_COLUMNS; j++)
			{
				inputFile >> oldTemperatures[i][j];
			}
		}
	}

	for (int n = 0; n < 3; n++)
	{
		for (int i = 1; i <= NUM_ROWS - 2; i++)
		{
			for (int j = 1; j <= NUM_COLUMNS - 2; j++)
			{
				newTemperatures[i][j] = (oldTemperatures[i - 1][j] + oldTemperatures[i][j + 1] + oldTemperatures[i + 1][j] + oldTemperatures[i][j - 1]) / 4.0;
			}

		}

		for (int k = 0; k < NUM_ROWS; k++)
		{
			for (int l = 0; l < NUM_COLUMNS; l++)
			{
				oldTemperatures[k][l] = newTemperatures[k][l];
			}
		}
	}


	cout << "Printing input plate after 3 updates..." << endl;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS - 1; j++)
		{
			cout << fixed << setw(DATA_WIDTH) << setprecision(DATA_PRECISION) << newTemperatures[i][j] << ", ";
		}

		cout << newTemperatures[i][NUM_COLUMNS - 1] << endl;
	}


	cout << endl;
	system("pause");
	inputFile.close();
	outputFile.close();

	cout << endl;
	return 0;

}

