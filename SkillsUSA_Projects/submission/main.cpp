// This project was used in the school's competition to 
// see who would and wouldn't got to the SkillsUSA Regional.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	//variables
	int row;
	int col;
	char choice;
	ofstream outf;
	string filePath;
	string fileName;

	//user input
	do {
		cout << "How many rows would you like? (between 1 and 12) ";
		cin >> row;
		if (row > 12) //if rows is too big
			cout << "Maximum rows is twelve.\n";
		if (row < 1) //if rows it too small
			cout << "Minimum rows is one.\n";
	} while (row < 1 || row > 12);

	cout << '\n';
	do {
		cout << "How many columns would you like? (between 1 and 12) ";
		cin >> col;
		if (col > 12) //if col is too big
			cout << "Maximum columns is twelve.\n";
		if (col < 1) //if col is too small
			cout << "Minimum columns is one.\n";
	} while (col < 1 || col > 12);

	//output
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++)
			cout << (x + 1) * (y + 1) << '\t';
		cout << '\n';
	}

	//saving
	do {
		cout << "Would you like to save to a new file? (y/Y or n/N) ";
		cin >> choice;
		switch (choice) {
			case 'y': //if they want to save
			case 'Y':
				cout << "Please enter your full file path.\n";
				cin >> filePath;
				cout << "What would you like your file name to be?\n";
				cin >> fileName;
				outf.open(filePath + fileName + ".txt"); //opens filepath/fileName.txt
				for (int x = 0; x < row; x++) {
					for (int y = 0; y < col; y++) {
						outf << (x + 1) * (y + 1); //prints numbers
						if (y != col - 1)
							outf << ", "; //prints comma if not the last # in row
					}
					outf << '\n'; //moves to next row
				}
				if (!outf)
					outf.close(); //creates the file if it doesn't already exist
				break;
			case 'n':
			case'N':
				break;
			default:
				cout << "Please choose yes or no.\n";
		}
	} while (toupper(choice) != 'Y' && toupper(choice) != 'N'); //makes sure user says yes or no
	
	//closer
	cout << "\\ the end \\\n";
	system("pause");
	return 0;
}