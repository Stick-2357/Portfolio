#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "addressBookType.h"

using namespace std;

void loadAddressBook(addressBookType& adBook);
void saveData(addressBookType& adBook);

void showMenu();

int main() {
	addressBookType addressBook;
	string str;
	string str1;
	string str2;
	int choice = 1;
	int loc;
	int month;

	loadAddressBook(addressBook);

	addressBook.sort();


	while (choice != 0) {
		showMenu();

		cin >> choice;
		cin.ignore(100, '\n');

		switch (choice) {
			case 1: {
				cout << "Enter the last name of the person: ";
				getline(cin, str);
				cout << "\n";

				loc = addressBook.search(str);

				if (loc != -1)
					cout << str << " is in the address book.\n";
				else
					cout << str << " is not in the address book.\n";
				break;
			}//end case 1
			case 2: {
				cout << "Enter the last name of the person: ";
				getline(cin, str);
				cout << "\n";

				loc = addressBook.search(str);

				if (loc != -1)
					addressBook.printAt(loc);
				else
					cout << str << " is not in the address book.\n";
				break;
			}//end case 2
			case 3: {
				cout << "Enter the month number: ";
				cin >> month;
				cout << "\n";

				cin.ignore(100, '\n');
				cout << "\n";

				addressBook.printNameInTheMonth(month);
				break;
			}//end case 3
			case 4: {
				cout << "Enter starting last name: ";
				getline(cin, str1);
				cout << "\nEnter ending last name: ";
				getline(cin, str2);
				cout << '\n';

				addressBook.printNamesBetweenLastNames(str1, str2);
				break;
			}//end case 4
			case 5: {
				cout << "Enter person type Family, Friend, Business: ";
				getline(cin, str);
				cout << "\n";
				addressBook.printNamesWithStatus(str);
				break;
			}//end case 5
			case 6: {
				addressBook.print();
				break;
			}//end case 6
			case 7: {
				saveData(addressBook);
				break;
			}//end case 7
			default:
				cout << "Invalid choice \n";
				showMenu();
				cin >> choice;
				cin.ignore(100, '\n');
		}//end swtich
	}//end while
	system("pause");
	return 0;
}
//end main()

void loadAddressBook(addressBookType& adBook) {
	ifstream infile;

	string fileName;
	string first;
	string last;

	int month;
	int day;
	int year;

	string street;
	string city;
	string state;
	string zip;

	string phone;
	string pStatus;

	string tempString;

	extPersonType temp;

	cout << "Enter file name: ";
	cin >> fileName;
	fileName = "C:/Users/emonnig738/Desktop/Files/" + fileName + ".txt";
	cout << "\n";

	infile.open(fileName);
	if (!infile) {
		cout << "Input file does not exists. Program terminates!!! \n";
		system("pause");
		exit(0);
	}//end if

	int i = 0;

	infile >> first >> last >> month >> day >> year;
	infile >> street >> city >> state;
	infile >> zip >> phone >> pStatus;

	while (infile) {
		temp.setInfo(first, last, month, day, year, street, city, state, zip, phone, pStatus);

		adBook.insertAt(temp, i);
		i++;

		infile >> first >> last >> month >> day >> year;
		infile >> street >> city >> state;
		infile >> zip >> phone >> pStatus;
	}//end while
}
//end addressBookLoad()
	
void saveData(addressBookType& adBook) {
	ofstream outfile;
	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;
	fileName = "C:/Users/emonnig738/Desktop/Files/" + fileName + ".txt";
	cout << "\n";
	outfile.open(fileName);
	if (!outfile){
		cout << "Unable to create the output file. "
			<< "Program terminates!!! \n";
		return;
	}//end if
	adBook.saveData(outfile);
}
//end saveData()

void showMenu() {
	cout << "Welcome to the address book program. \n";
	cout << "Choose among the following options: \n";
	cout << "1: To see if a person is in the address book\n";
	cout << "2: Print the information of a person \n";
	cout << "3: Print the names of person having birthday in a particular month \n";
	cout << "4: Print the names of persons between two last names \n";
	cout << "5: Print the names of persons having a particular status \n";
	cout << "6: Print the address book \n";
	cout << "7: Save data \n";
	cout << "0: Terminate the program \n";
}
//end showMenu()
