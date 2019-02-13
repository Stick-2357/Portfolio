#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_OF_COUNTRIES = 5;

struct moneyType {
	string name;
	double value;
	string sigular;
};

int main() {
	ifstream inFile;

	moneyType currencies[NUM_OF_COUNTRIES];
	moneyType start;
	moneyType end;

	string input;
	int choice;

	double amount;
	bool test = true;

	cout << fixed << showpoint << setprecision(2);
	
	inFile.open("C:/Users/emonnig738/Desktop/Files/CurrencyIn.txt");
	if (!inFile) {
		cout << "In file does not exist.";
		system("pause");
	}

	while (inFile) {
		for (int i = 0; i <= NUM_OF_COUNTRIES - 1; i++) {
			inFile >> currencies[i].name;
			inFile >> currencies[i].value;
			inFile >> currencies[i].sigular;
		}
	}

	do {
		test = true;
		cout << "Welcome to my currency converter. Which location are you from?\n";
		for (int i = 0; i <= NUM_OF_COUNTRIES - 1; i++) {
			cout << i + 1 << ". " << currencies[i].name << '\n';
		}
		cin >> input;
		try {
			choice = stoi(input);
			if (choice > NUM_OF_COUNTRIES || choice <= 0) {
				cout << "Choose from the given options.";
				Sleep(500);
				system("cls");
				test = false;
			}
		}
		catch (...) {
			cout << "Wrong type entered.";
			Sleep(500);
			system("cls");
			test = false;
		}
	} while (!test);
	system("cls");
	test = true;

	start = currencies[choice - 1];


	do {
		test = true;
		cout << "Which location are you going to?\n";
		for (int i = 0; i <= NUM_OF_COUNTRIES - 1; i++) {
			cout << i + 1 << ". " << currencies[i].name << '\n';
		}
		cin >> input;
		try {
			choice = stoi(input);
			if (choice > NUM_OF_COUNTRIES || choice <= 0) {
				cout << "Choose from the given options.";
				Sleep(500);
				system("cls");
				test = false;
			}
		}
		catch (...) {
			cout << "Wrong type entered.";
			Sleep(500);
			system("cls");
			test = false;
		}
		if (start.name == currencies[choice - 1].name) {
			cout << "You can't go to the same place.";
			Sleep(500);
			system("cls");
			test = false;
		}
	} while (!test);
	test = true;

	end = currencies[choice - 1];


	do {
		test = true;
		cout << "How " << (start.name != "JPY" ? "many " : "much " ) << start.sigular 
			<< (start.name != "JPY" ? "s " : " ") << "do you have? \n";
		cin >> input;
		try {
			amount = stod(input);
			if (amount <= 0) {
				cout << "You can't 0 or less.";
				Sleep(500);
				system("cls");
				test = false;
			}
		}
		catch (...) {
			cout << "Wrong type entered.";
			Sleep(500);
			system("cls");
			test = false;
		}
	} while (!test);
	test = true;

	cout << amount << " " << start.sigular << (start.name != "JPY" ? "s in " : " in ") << start.name << " would be the same as " 
		<< (amount / start.value) * end.value << " " << end.sigular << (end.name != "JPY" ? "s in " : " in ") <<  end.name << ".\n";
	system("pause");

	return 0;
}
