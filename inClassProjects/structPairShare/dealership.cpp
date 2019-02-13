/*
Name:	Eli Monnig & Jacob Winslow
Date:	10.29.18
Description: Using records to buy some cars
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

//enums
enum colorType {RED, BLUE, WHITE, SILVER, BLACK, NA};
enum isNewType {YES, NO, NONE};

//class
struct carType {
	string make;
	string model;
	int year;
	colorType color;
	double price;
	double priceWithTax;
	isNewType isNew;
};//end of carType class

//function prototype
void showMenu();
void getData(ifstream& inF, vector<carType>& list, int length);
void printCarData(vector<carType> list, int length, int playerNum);
void printData(vector<carType> list, int length);
void saveData(ofstream& outF, vector<carType> list, int length);
int searchData(vector<carType> list, int length, string n);
void updateMake(vector<carType>& list, int length, string newMake, int carNum);
void updateModel(vector<carType>& list, int length, string newModel, int carNum);
void updateYear(vector<carType>& list, int length, int newYear, int carNum);
void updateColor(vector<carType>& list, int length, colorType newColor, int carNum);
void updatePrice(vector<carType>& list, int length, double newPrice, int carNum);
void updateIsNew(vector<carType>& list, int length, isNewType newIsNew, int carNum);
void buyCar(vector<carType>& list, int& length, int carNum);
void addNewCar(vector<carType>& list, int& length);

int main() {
	//variables
	ifstream inFile;
	ofstream outFile;
	vector<carType> dealership; //New instance of the struct
	int numOfCars = 5;
	int choice;
	char input;
	int carNum;
	string carMake;
	string carModel;
	string temp;
	int carYear;
	colorType carColor;
	double carPrice;
	isNewType carIsNew;

	inFile.open("C:/Users/emonnig738/Desktop/CarDealershipIn.txt");

	if (!inFile) {
		cout << "Input file does not exist. Program terminates you dope!";
		return 1;
	}//end if

	getData(inFile, dealership, numOfCars);

	do {
		showMenu();
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);
				printCarData(dealership, numOfCars, carNum);
				break;
			}//end case 1
			case 2: {
				printData(dealership, numOfCars);
				break;
			}//end case 2
			case 3: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);

				cout << "Enter the new make of the car: ";
				cin >> carMake;
				cout << endl;

				updateMake(dealership, numOfCars, carMake, carNum);

				break;
			}//end case 3
			case 4: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);

				cout << "Enter the new model of the car: ";
				cin >> carModel;
				cout << endl;

				updateModel(dealership, numOfCars, carModel, carNum);

				break;
			}//end case 4
			case 5: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);

				cout << "Enter the new year of the car: ";
				cin >> carYear;
				cout << endl;

				updateYear(dealership, numOfCars, carYear, carNum);

				break; 
			}//end case 5
			case 6: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);

				do {
					cout << "Enter the new color of the car: ";
					cin >> temp;
					if (temp == "RED" || temp == "red" || temp == "Red")
						carColor = RED;
					else if (temp == "BLUE" || temp == "blue" || temp == "Blue")
						carColor = BLUE;
					else if (temp == "BLACK" || temp == "black" || temp == "Black")
						carColor = BLACK;
					else if (temp == "SILVER" || temp == "silver" || temp == "Silver")
						carColor = SILVER;
					else if (temp == "BLACK" || temp == "black" || temp == "Black")
						carColor = BLACK;
					else
						cout << "That is not a valid color. Please choose another.";
						carColor = NA;
				} while (carColor = NA);
				cout << endl;

				updateColor(dealership, numOfCars, carColor, carNum);

				break;
			}//end case 6
			case 7: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);

				cout << "Enter the new price of the car: ";
				cin >> carPrice;
				cout << endl;

				updatePrice(dealership, numOfCars, carPrice, carNum);

				break;

			}//end case 7
			case 8: {
				cout << "Enter the cars's model: ";
				cin >> carModel;
				cout << endl;

				carNum = searchData(dealership, numOfCars, carModel);
				
				cout << "Do you want the car to be new? (Y/y or N/n) :";
				cin >> input;
				if (toupper(input) == 'Y')
					carIsNew = YES;
				else
					carIsNew = NO;
				cout << endl;
				
				updateIsNew(dealership, numOfCars, carIsNew, carNum);
				
				break;
			}//end case 8
			case 9: {
				addNewCar(dealership, numOfCars);
				break;
			}//end case 9
			case 10: {
				printData(dealership, numOfCars);
				cout << "Which car do you want? 1 - " << numOfCars << ": ";
				cin >> choice;
				choice--;

				cout << endl << "Are you sure you want to buy this car?";
				printCarData(dealership, numOfCars, choice);
				cout << "(Y/y or N/n) : ";
				cin >> input;

				if (toupper(input) == 'Y')
					buyCar(dealership, numOfCars, choice);

				Sleep(700);
				choice = 0;
				break;
			}//end case 10
			default :
				choice = 0;
		}//end switch
	} while (choice != 0);
	saveData(outFile, dealership, numOfCars);
	return 0;
}
//end main

//function
void showMenu() {
	cout << "Select one of the following options: " << endl;
	cout << "\t1: To print a car's data" << endl;
	cout << "\t2: To print the entire data" << endl;
	cout << "\t3: To update a car's make" << endl;
	cout << "\t4: To update a car's model" << endl;
	cout << "\t5: To update a car's year" << endl;
	cout << "\t6: To update a car's color" << endl;
	cout << "\t7: To update a car's price" << endl;
	cout << "\t8: To update whether or not a car is new" << endl;
	cout << "\t9: To add a new car to the list" << endl;
	cout << "\t10: To buy a car" << endl;
	cout << "\t0: To quit the program" << endl;
}
//end showMenu

void getData(ifstream& inF, vector<carType>& list, int length) {
	string IsNewTemp;
	string colorTemp;
	
	list.resize(length);
	for (int i = 0; i < length; i++) {
		inF >> list.at(i).make >> list.at(i).model >> list.at(i).year >> colorTemp >> list.at(i).price >> IsNewTemp;
		if (colorTemp == "RED")
			list.at(i).color = RED;
		else if (colorTemp == "BLUE")
			list.at(i).color = BLUE;
		else if (colorTemp == "BLACK")
			list.at(i).color = BLACK;
		else if (colorTemp == "SILVER")
			list.at(i).color = SILVER;
		else if (colorTemp == "BLACK")
			list.at(i).color = BLACK;
		if (IsNewTemp == "New")
			list.at(i).isNew = YES;
		else
			list.at(i).isNew = NO;
		list.at(i).priceWithTax = list.at(i).price * .0715;
		list.shrink_to_fit();
	}//end for i loop
}
//end getData

void printCarData(vector<carType> list, int length, int carNum) {
	if (0 <= carNum && carNum < length) {
		cout << "\nMake: " << list.at(carNum).make
			<< "\nModel: " << list.at(carNum).model
			<< "\nYear: " << list.at(carNum).year
			<< "\nColor: ";
		if (list.at(carNum).color == RED)
			cout << "Red";
		else if (list.at(carNum).color == BLUE)
			cout << "Blue";
		else if (list.at(carNum).color == WHITE)
			cout << "White";
		else if (list.at(carNum).color == SILVER)
			cout << "Silver";
		else if (list.at(carNum).color == BLACK)
			cout << "Black";
		cout << "\nPrice: " << list.at(carNum).price 
			<< "\nPrice With Tax" << list.at(carNum).priceWithTax
			<< "\nCar Is New: ";
		if (list.at(carNum).isNew == YES)
			cout << "New";
		else
			cout << "Used";
		cout << endl;
	}//end if
	else
		cout << "Invalid Car model.\n\n";
	cout << "\n";
}
//end printCarData

void printData(vector<carType> list, int length) {
	cout << "Make\tModel\tYear\tColor\tPrice\tPrice With Tax\tCar Is New\n\b";

	for (int i = 0; i < length; i++) {
		cout << list.at(i).make;
		(i == 0 ? cout << "\b\b\b" : cout << "");
		cout << "\t" << list.at(i).model
			<< "\t" << list.at(i).year << "\t";
		if (list.at(i).color == RED)
			cout << "Red\t";
		else if (list.at(i).color == BLUE)
			cout << "Blue\t";
		else if (list.at(i).color == WHITE)
			cout << "White\t";
		else if (list.at(i).color == SILVER)
			cout << "Silver\t";
		else if (list.at(i).color == BLACK)
			cout << "Black\t";
		cout << list.at(i).price << "\t" << list.at(i).priceWithTax;
		if (list.at(i).isNew == YES)
			cout << "\tNew\n";
		else
			cout << "\tUsed\n";
	}//end for i loop

	cout << "\n\n";
}
//end printData

void saveData(ofstream& outF, vector<carType> list, int length) {
	
	outF.open("C:/Users/emonnig738/Desktop/CarDealership.OUT");

	for (int i = 0; i < length; i++) {
		outF << " " << list.at(i).make
			<< " " << list.at(i).model
			<< " " << list.at(i).year
			<< " ";
		if (list.at(i).color == RED)
			outF << "RED";
		else if (list.at(i).color == BLUE)
			outF << "BLUE";
		else if (list.at(i).color == WHITE)
			outF << "WHITE";
		else if (list.at(i).color == SILVER)
			outF << "SILVER";
		else if (list.at(i).color == BLACK)
			outF << "BLACK";
		outF << " " << list.at(i).price
			<< " " << list.at(i).priceWithTax
			<< " ";
		if (list.at(i).isNew == YES)
			outF << "New\n";
		else if (list.at(i).isNew == NO)
			outF << "Used\n";
	}//end for i loop
}
//end saveData

int searchData(vector<carType> list, int length, string n) {
	
	for (int i = 0; i < length; i++)
		if (list.at(i).model == n)
			return i;

	return -1;
}
//end searchData

void updateMake(vector<carType>& list, int length, string newMake, int carNum) {
	
	if (0 <= carNum && carNum < length)
		list.at(carNum).make = newMake;
	else
		cout << "Invalid car model.\n";
}
//end updateMake

void updateModel(vector<carType>& list, int length, string newModel, int carNum) {
	
	if (0 <= carNum && carNum < length)
		list.at(carNum).model = newModel;
	else
		cout << "Invalid car model.\n";
}
//end updateModel

void updateYear(vector<carType>& list, int length, int newYear, int carNum) {
	
	if (0 <= carNum && carNum < length)
		list.at(carNum).year = newYear;
	else
		cout << "Invalid car model.\n";
}
//end updateYear

void updateColor(vector<carType>& list, int length, colorType newColor, int carNum) {
	
	if (0 <= carNum && carNum < length)
		list.at(carNum).color = newColor;
	else
		cout << "Invalid car model.\n";
}
//end updateColor

void updatePrice(vector<carType>& list, int length, double newPrice, int carNum) {
	
	if (0 <= carNum && carNum < length)
		list.at(carNum).price = newPrice;
	else
		cout << "Invalid car model.\n";
}
//end updatePrice

void updateIsNew(vector<carType>& list, int length, isNewType newIsNew, int carNum) {
	
	if (0 <= carNum && carNum < length)
		list.at(carNum).isNew = newIsNew;
	else
		cout << "Invalid car model.\n";
}
//end updateIsNew

void addNewCar(vector<carType>& list, int& length) {
	string newMake;
	string newModel;
	int newYear;
	string input;
	colorType newColor;
	double newPrice;
	char choice;
	isNewType newIsNew;

	cout << "What do you want the make of your car? : ";
	cin >> newMake;
	cout << endl;

	cout << "What do you want the model of your car? : ";
	cin >> newModel;
	cout << endl;

	cout << "What do you want the year of your car? : ";
	cin >> newYear;
	cout << endl;

	do {
		cout << "Enter the new color of the car: ";
		cin >> input;
		if (input == "RED" || input == "red" || input == "Red")
			newColor = RED;
		else if (input == "BLUE" || input == "blue" || input == "Blue")
			newColor = BLUE;
		else if (input == "BLACK" || input == "black" || input == "Black")
			newColor = BLACK;
		else if (input == "SILVER" || input == "silver" || input == "Silver")
			newColor = SILVER;
		else if (input == "BLACK" || input == "black" || input == "Black")
			newColor = BLACK;
		else {
			cout << "That is not a valid color. Please choose another.";
			newColor = NA;
		}//end else
	} while (newColor == NA);
	cout << endl;

	cout << "What do you want the price of your car? : ";
	cin >> newPrice;
	cout << endl;

	do {
		cout << "What do you want your car to be new? (Y/y or N/n) : ";
		cin >> choice;
		if (toupper(choice) == 'Y')
			newIsNew = YES;
		else if (toupper(choice) == 'N')
			newIsNew = NO;
		else {
			cout << "That's not a valid input.";
			newIsNew = NONE;
		}//end else
	} while (newIsNew == NONE);
	cout << endl;

	list.resize(length + 1);
	list.at(length).make = newMake;
	list.at(length).model = newModel;
	list.at(length).year = newYear;
	list.at(length).color = newColor;
	list.at(length).price = newPrice;
	list.at(length).isNew = newIsNew;

	list.shrink_to_fit();
	length++;
}
//end addNewCar

void buyCar(vector<carType>& list, int& length, int carNum) {
	cout << "This car will cost you $" << list.at(carNum).price << ".";
	list.erase(list.begin() + carNum);
	length -= 1;
}
//end buyCar
