#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct employee {
	int ID;
	string name;
	int rating;
	double currentSalary;
	double newSalary;
};

const int NUM_OF_EMPLOYEES = 5;
const string NAMES[] = { "John Eggbert", "Roxy Llaond", "Dave Strider", "Jade Janson", "Dirk Strider" };

int main() {
	ifstream inFile;

	vector<employee> employees;
	vector<employee> sortedEmployees;
	employee tempEmployee;

	string input;
	double tempDouble;
	bool test;

	cout << fixed << showpoint << setprecision(2);

	for (int i = 0; i <= 4; i++) {
		do {
			test = true;
			cout << "What is employee number " << i + 1 << "'s ID?\n";
			cin >> input;
			try {
				tempEmployee.ID = stoi(input);
				for (int j = 0; j < employees.size(); j++) {
					if (tempEmployee.ID == employees.at(j).ID) {
						cout << "IDs must be unique. You have already used " << tempEmployee.ID << ".";
						Sleep(500);
						system("cls");
						test = false;;
					}
				}
				if (tempEmployee.ID > NUM_OF_EMPLOYEES || tempEmployee.ID <= 0) {
					cout << "IDs must be between 1 and 5.";
					Sleep(500);
					system("cls");
					test = false;
				}
			}
			catch (...) {
				cout << "Wrong type. Please enter a whole number.";
				Sleep(500);
				system("cls");
				test = false;
			}
		} while (!test);

		do {
			test = true;
			cout << "What is employee number " << i + 1 << "'s rating for the year?\n";
			cin >> input;
			try {
				tempEmployee.rating = stoi(input);
				if (tempEmployee.rating > 3 || tempEmployee.rating <= 0) {
					cout << "Ratings must be between 1 and 3.";
					Sleep(500);
					system("cls");
					test = false;
				}
			}
			catch (...) {
				cout << "Wrong type. Please enter a whole number.";
				Sleep(500);
				system("cls");
				test = false;
			}
		} while (!test);

		do {
			test = true;
			cout << "What is employee number " << i + 1 << "'s current salary?\n";
			cin >> input;
			try {
				tempEmployee.currentSalary = stod(input);
				if (tempEmployee.currentSalary <= 0.0) {
					cout << "Salary must be greater than 0.";
					Sleep(500);
					system("cls");
					test = false;
				}
			}
			catch (...) {
				cout << "Wrong type. Please enter a decimal number.";
				Sleep(500);
				system("cls");
				test = false;
			}
		} while (!test);
		employees.push_back(tempEmployee);
	}
	system("cls");


	while (!(employees.empty())) {
		int lowestID = 99;
		int lowestIndex = 99;
		for (int i = 0; i < employees.size(); i++) {
			if (employees.at(i).ID < lowestID) {
				lowestID = employees.at(i).ID;
				lowestIndex = i;
			}
		}
		sortedEmployees.push_back(employees.at(lowestIndex));
		employees.erase(employees.begin() + lowestIndex);
	}

	for (int i = 0; i < sortedEmployees.size(); i++) {
		sortedEmployees.at(i).name = NAMES[i];
		switch (sortedEmployees.at(i).rating) {
			case 1: {
				sortedEmployees.at(i).newSalary = sortedEmployees.at(i).currentSalary + (sortedEmployees.at(i).currentSalary * .05);
				break;
			}
			case 2: {
				sortedEmployees.at(i).newSalary = sortedEmployees.at(i).currentSalary + (sortedEmployees.at(i).currentSalary * .07);
				break;
			}
			case 3: {
				sortedEmployees.at(i).newSalary = sortedEmployees.at(i).currentSalary + (sortedEmployees.at(i).currentSalary * .09);
				break;
			}
		}
		if (i != 0) {
			cout << "\n\n";
		}
		cout << sortedEmployees.at(i).ID << ".\t" << sortedEmployees.at(i).name << '\n';
		cout << "Rated " << sortedEmployees.at(i).rating << '\n';
		cout << "Was paid $" << sortedEmployees.at(i).currentSalary << '\n';
		cout << "Will be paid $" << sortedEmployees.at(i).newSalary << '\n';
		cout << "Difference of $" << abs(sortedEmployees.at(i).newSalary - sortedEmployees.at(i).currentSalary);
	}

	cout << '\n';
	system("pause");
	return 0;
}
