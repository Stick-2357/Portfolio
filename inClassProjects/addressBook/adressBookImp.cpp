#include <iostream>
#include <fstream>
#include <string> 
#include "addressBookType.h"

using namespace std;

void addressBookType::print() const {
	for (int i = 0; i < length; i++)
		list[i].printInfo();
}
//end addressBookType::print()

void addressBookType::printNameInTheMonth(int month) {
	for (int i = 0; i < length; i++)
		if (list[i].isMonth(month)) {
			list[i].print();
			cout << "\n";
		}//end if
}
//end addressBookType::printNameInTheMonth()

void addressBookType::printInfoOf(string lName) {
	int i = search(lName);

	if (i != -1)
		list[i].printInfo();
	else
		cout << lName << " is not in address book.\n";
}
//end addressBookType::printInfoOf()

void addressBookType::printNamesWithStatus(string status) {
	for (int i = 0; i < length; i++)
		if (list[i].isStatus(status)) {
			list[i].print();
			cout << "\n";
		}//end if
}
//end addressBookType::printNamesWithStatus()

void addressBookType::printAt(int i) {
	if (i < length)
		list[i].printInfo();
	else
		cout << "No such person\n";
}
//end addressBookType::printAt()

void addressBookType::printNamesBetweenLastNames(string last1, string last2) {
	string lName;

	for (int i = 0; i < length; i++) {
		lName = list[i].getLastName();
		if (last1 <= lName && lName <= last2) {
			list[i].print();
			cout << "\n";
		}//end if
	}//end for i loop
}
//end addressBookType::printNamesBetweenLastNames()

void addressBookType::insertAt(const extPersonType&  eP, int i) {
	list[i] = eP;
	if (i == length)
		length++;
}
//end addressBookType::insertAt()

void addressBookType::insertLast(const extPersonType& eP) {
	list[length] = eP;
	length++;
}
//end addressBookType::insertLast()

int addressBookType::search(string lName) {
	bool found = false;
	int i;

	for (i = 0; i < length; i++)
		if (list[i].isLastName(lName)) {
			found = true;
			break;
		}//end for i loop

	if (found && i < length)
		return i;
	else
		return -1;
}
//end addressBookType::search()

void addressBookType::sort() {
	string str1;
	string str2;

	int i, j;

	extPersonType temp;

	int minIndex;

	for (i = 0; i < length - 1; i++) {
		minIndex = i;
		str1 = list[minIndex].getLastName();

		for (j = i + 1; j < length; j++) {
			str2 = list[j].getLastName();
			str1 = list[minIndex].getLastName();

			if (str1 > str2)
				minIndex = j;
		}//end for j loop

		temp = list[minIndex];
		list[minIndex] = list[i];
		list[i] = temp;
	}//end for i loop
}
//end addressBookType::sort()

addressBookType::addressBookType() {
	length = 0;
}
//end addressBookType::addressBookType()

void addressBookType::saveData(ofstream& outFile) {
	int month;
	int day;
	int year;
	string street;
	string city;
	string state;
	string zip;

	string phone;
	string pStatus;

	for (int i = 0; i < length; i++) {
		list[i].getDOB(month, day, year);
		list[i].getAddress(street, city, state, zip);

		outFile << list[i].getFirstName() << " " << list[i].getLastName() << "\n";
		outFile << month << " " << day << " " << year << "\n";
		outFile << street << "\n" << city << "\n" << state << "\n" << zip << "\n";
		outFile << list[i].getPhoneNumber() << "\n" << list[i].getStatus() << "\n";
	}//end for i loop
}
//end constructor