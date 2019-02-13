/*
Name:		 Eli Monnig
Date:		 10.10.2018
Description: Reserve a ticket for airplane
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <windows.h>

enum seat {open, taken, NA};

seat firstArray[5][3];
seat bussinessArray[15][6];
seat premiumArray[6][7];
seat economyArray[38][10];

void makeFirst(int startingPos, int numOfRows);
void makeBussiness(int startingPos, int numOfRows);
void makePremium(int startingPos, int numOfRows);
void makeEconomy(int startingPos, int numOfRows);
void makeReceipt(bool& complete, std::vector<std::string>& total);

int main() {
	//variables
	bool done = false;
	bool valid = true;
	int input = 0;
	int row = 0;
	int temp1 = 0;
	int temp2 = 0;
	char column = ' ';
	std::string strInput = "";
	std::string strTemp = "";
	std::vector<std::string> receipt;

	//preseting all of arrays to open
	for (int x = 0; x <= 37; x++)
		for (int y = 0; y <= 9; y++) {
			firstArray[x][y] = open;
			bussinessArray[x][y] = open;
			premiumArray[x][y] = open;
			economyArray[x][y] = open;
		}//end for y

	//setting NAs
	firstArray[4][1] = NA;

	bussinessArray[3][0] = NA;
	bussinessArray[3][1] = NA;
	bussinessArray[3][2] = NA;
	bussinessArray[3][3] = NA;
	bussinessArray[3][4] = NA;
	bussinessArray[3][5] = NA;
	bussinessArray[4][0] = NA;
	bussinessArray[4][1] = NA;
	bussinessArray[4][2] = NA;
	bussinessArray[4][3] = NA;
	bussinessArray[4][4] = NA;
	bussinessArray[4][5] = NA;
	bussinessArray[12][0] = NA;
	bussinessArray[12][1] = NA;
	bussinessArray[12][2] = NA;
	bussinessArray[12][3] = NA;
	bussinessArray[12][4] = NA;
	bussinessArray[12][5] = NA;

	premiumArray[3][0] = NA;
	premiumArray[3][1] = NA;
	premiumArray[3][5] = NA;
	premiumArray[3][6] = NA;
	premiumArray[4][0] = NA;
	premiumArray[4][1] = NA;
	premiumArray[4][5] = NA;
	premiumArray[4][6] = NA;
	premiumArray[5][0] = NA;
	premiumArray[5][1] = NA;

	for (int y = 0; y <= 9; y++) {
		economyArray[15][y] = NA;
		economyArray[28][y] = NA;
		switch (y) {
			case 0: {
				economyArray[29][y] = NA;
				economyArray[37][y] = NA;
				economyArray[38][y] = NA;
				break;
			}//end case 0
			case 1: {
				economyArray[37][y] = NA;
				economyArray[38][y] = NA;
				break;
			}//end case 1
			case 2: {
				economyArray[37][y] = NA;
				economyArray[38][y] = NA;
				break;
			}//end case 2
			case 3: {
				economyArray[0][y] = NA;
				economyArray[1][y] = NA;
				economyArray[20][y] = NA;
				economyArray[29][y] = NA;
				economyArray[30][y] = NA;
				break;
			}//end case 3
			case 4: {
				economyArray[0][y] = NA;
				economyArray[1][y] = NA;
				economyArray[29][y] = NA;
				economyArray[30][y] = NA;
				break;
			}//end case 4
			case 5: {
				economyArray[0][y] = NA;
				economyArray[1][y] = NA;
				economyArray[29][y] = NA;
				economyArray[30][y] = NA;
				break;
			}//end case 5
			case 6: {
				economyArray[0][y] = NA;
				economyArray[1][y] = NA;
				economyArray[29][y] = NA;
				economyArray[30][y] = NA;
				break;
			}//end case 6
			case 7: {
				economyArray[0][y] = NA;
				economyArray[37][y] = NA;
				economyArray[38][y] = NA;
				break;
			}//end case 7
			case 8: {
				economyArray[0][y] = NA;
				economyArray[37][y] = NA;
				economyArray[38][y] = NA;
				break;
			}//end case 8
			case 9: {
				economyArray[0][y] = NA;
				economyArray[29][y] = NA;
				economyArray[37][y] = NA;
				economyArray[38][y] = NA;
				break;
			}//end case 9
		}//end swtich
	}//end for loop

	//user interaction
	do {
		system("CLS");

		std::cout << "Welcome to the Airbus A380. Which type of seating would you like?" << std::endl
			<< "\t1) First Class" << std::endl
			<< "\t2) Bussiness Class" << std::endl
			<< "\t3) Premium Economy" << std::endl
			<< "\t4) Economy Class" << std::endl
			<< "\t0) Receipt" << std::endl;
		std::cin >> input;
		valid = true;
		strTemp = "";

		switch (input) {
			case 1: {
				do {
					makeFirst(0, 5);
					std::cout << "Which row do you want? : ";
					std::cin >> row;
					temp2 = row - 1;
					if (temp2 >= 4)
						valid = false;
					std::cout << "Which column do you want? : ";
					std::cin >> column;
					if (valid == true)
						if (column == 'A' || column == 'a')
							temp1 = 0;
						else if (column == 'F' || column == 'f')
							temp1 = 1;
						else if (column == 'K' || column == 'k')
							temp1 = 2;
						else {
							valid = false;
							std::cout << "That's not a valid option!";
						}//end else
					else {
						valid = false;
						std::cout << "That's not a valid option!";
					}//end else
					system("CLS");
				} while (!valid);
				if (firstArray[temp2][temp1] == open) {
					firstArray[temp2][temp1] = taken;
					strTemp.append(std::to_string(temp2 +1));
					strTemp.push_back(toupper(column));
					strTemp.append("\t: First Class");
					receipt.resize(receipt.size() + 1);
					receipt.push_back(strTemp);
				}//end if
				else
					std::cout << "That seat either taken or unavailable. Please choose a different seat.";
				break;
			}//end case 1
			case 2: {
				std::cout << "Which set of seats would you like to view?" << std::endl
					<< "\t1) 11-13" << std::endl
					<< "\t2) 16-25" << std::endl
					<< "0\t0) Back" << std::endl;
				std::cin >> input;

				switch (input) {
					case 1: {
						makeBussiness(0, 3);
						break;
					}//end case 1
					case 2: {
						makeBussiness(5, 10);
						break;
					}//end case 2
				}//end switch;
				do {
					std::cout << "Which row do you want? : ";
					std::cin >> row;
					temp2 = row - 11;
					if (temp2 >= 7)
						valid = false;
					std::cout << "Which column do you want? : ";
					std::cin >> column;
					if (toupper(column) == 'A')
						temp1 = 0;
					else if (toupper(column) == 'B')
						temp1 = 1;
					else if (toupper(column) == 'E')
						temp1 = 2;
					else if (toupper(column) == 'F')
						temp1 = 3;
					else if (toupper(column) == 'J')
						temp1 = 4;
					else if (toupper(column) == 'K')
						temp1 = 5;
					else {
						valid = false;
						std::cout << "That's not a valid option!";
					}
					std::cout << std::endl;
				} while (!valid);
				if (bussinessArray[temp2][temp1] == open) {
					bussinessArray[temp2][temp1] = taken;
					strTemp.append(std::to_string(temp2 + 1));
					strTemp.push_back(toupper(column));
					strTemp.append("\t: Bussiness Class");
					receipt.resize(receipt.size() + 1);
					receipt.push_back(strTemp);
				}//end if
				else
					std::cout << "That seat either taken or unavailable. Please choose a different seat.";
				Sleep(20);
				break;
			}//end case 2
			case 3: {
				makePremium(0, 6);
				do {
					std::cout << "Which row do you want? : ";
					std::cin >> row;
					temp2 = row - 34;
					if (temp2 >= 8)
						valid = false;
					std::cout << "Which column do you want? : ";
					std::cin >> column;
					std::cout << std::endl;
				} while (!valid);
				if (premiumArray[temp2][temp1] == open) {
					premiumArray[temp2][temp1] = taken;
					strTemp.append(std::to_string(temp2 + 1));
					strTemp.push_back(toupper(column));
					strTemp.append("\t: Premium Class");
					receipt.resize(receipt.size() + 1);
					receipt.push_back(strTemp);
				}//end if
				else
					std::cout << "That seat either taken or unavailable. Please choose a different seat.";
				break;
			}//end case 3
			case 4: {
				std::cout << "Which set of seats would you like to view?" << std::endl
					<< "\t1) 50-64" << std::endl
					<< "\t2) 66-77" << std::endl
					<< "\t3) 79-88" << std::endl
					<< "\t0) Back" << std::endl;
				std::cin >> input;

				switch (input) {
					case 1: {
						makeEconomy(0, 14);
						break;
					}//end case 1
					case 2: {
						makeEconomy(16, 11);
						break;
					}//end case 2
					case 3: {
						makeEconomy(29, 9);
						break;
					}//end case 3
				}//end switch
				do {
					std::cout << "Which row do you want? : ";
					std::cin >> row;
					temp2 = row - 50;
					if (temp2 >= 11)
						valid = false;
					std::cout << "Which column do you want? : ";
					std::cin >> column;
					std::cout << std::endl;
					switch (toupper(column)) {
					case 'A':
						temp1 = 0;
					case 'B':
						temp1 = 1;
					case 'C':
						temp1 = 2;
					case 'D':
						temp1 = 3;
					case 'E':
						temp1 = 4;
					case 'F':
						temp1 = 5;
					case 'G':
						temp1 = 6;
					case 'H':
						temp1 = 7;
					case 'J':
						temp1 = 8;
					case 'K':
						temp1 = 9;
					}//end switch
					std::cout << std::endl;
				} while (!valid);
				if (economyArray[temp2][temp1] == open) {
					economyArray[temp2][temp1] = taken;
					strTemp.append(std::to_string(temp2 + 1));
					strTemp.push_back(toupper(column));
					strTemp.append("\t: Economy Class");
					receipt.resize(receipt.size() + 1);
					receipt.push_back(strTemp);
				}//end if
				else
					std::cout << "That seat either taken or unavailable. Please choose a different seat.";
				break;
			}//end case 4
			default:
				makeReceipt(done, receipt);
		}//end switch
	} while (!done);
	return 0;
}
//end main

//functions
void makeFirst(int startingPos, int numOfRows) {
	std::cout << "\t A\t F\t K" << std::endl;
	for (int x = 0; x < numOfRows; x++) 
		for (int y = 0; y <= 2; y++) {
			y == 0 ? std::cout << "Row " << (x + startingPos + 1) << "\t" : std::cout << "";
			std::cout << "{";
			if (firstArray[x + startingPos][y] == open)
				std::cout << "*";
			else if (firstArray[x + startingPos][y] == taken)
				std::cout << "x";
			else
				std::cout << "?";
			std::cout << "}";
			y == 2 ? std::cout << std::endl : std::cout << "\t";
		}//end for y
}
//end makeFirst

void makeBussiness(int startingPos, int numOfRows) {
	std::cout << "\t A B\t E F\t J K" << std::endl;
	for (int x = 0; x < numOfRows; x++)
		for (int y = 0; y <= 5; y++) {
			y == 0 ? std::cout << "Row " << (x + startingPos + 11) << "\t" : std::cout << "";
			y % 2 == 0 ? (std::cout << "{") : (std::cout << "|");
			if (bussinessArray[x + startingPos][y] == open)
				std::cout << "*";
			else if (bussinessArray[x + startingPos][y] == taken)
				std::cout << "x";
			else
				std::cout << "?";
			y % 2 == 1 ? (std::cout << "}\t") : (std::cout << "");
			y == 5 ? (std::cout << std::endl) : std::cout << "";
		}//end for y
}
//end makeBussiness

void makePremium(int startingPos, int numOfRows) {
	std::cout << "\t A B      D E F      J K" << std::endl;
	for (int x = 0; x < numOfRows; x++) 
		for (int y = 0; y <= 6; y++) {
			y == 0 ? std::cout << "Row " << (x + startingPos + 34) << "\t" : std::cout << "";
			if (y == 0 || y == 2 || y == 5)
				std::cout << "|";
			if (premiumArray[x + startingPos][y] == open)
				std::cout << "*";
			else if (premiumArray[x + startingPos][y] == taken)
				std::cout << "x";
			else
				std::cout << "?";
			std::cout << "|";
			(y == 1 || y == 4) ? std::cout << "    " : std::cout << "";
			y == 6 ? (std::cout << std::endl) : std::cout << "";
		}//end for y
}
//end makePremium

void makeEconomy(int startingPos, int numOfRows) {
	std::cout << "\t A B C     D E F G     H J K" << std::endl;
	for (int x = 0; x < numOfRows; x++) 
		for (int y = 0; y <= 9; ++y) {
			y == 0 ? std::cout << "Row " << (x + startingPos + 50) << "\t" : std::cout << "";
			if (y == 0 || y == 3 || y == 7)
				std::cout << "|";
			if (economyArray[x + startingPos][y] == open)
				std::cout << "*";
			else if (economyArray[x + startingPos][y] == taken)
				std::cout << "x";
			else
				std::cout << "?";
			std::cout << "|";
			(y == 2 || y == 6) ? std::cout << "   " : std::cout << "";
			y == 9 ? std::cout << std::endl : std::cout << "";
		}//end for y
}
//end makeEconomy

void makeReceipt(bool& complete, std::vector<std::string>& total) {
	//variables
	std::string input = " ";
	int row = 0;
	int size = 0;
	std::string temp1 = " ";
	char column = ' ';

	total.shrink_to_fit();
	size = total.size();
	for (int x = 0; x <= size - 1; ++x) 
		if (total.at(x) == "")
			total.at(x).erase();
	total.shrink_to_fit();
	size = total.size();
	for (int x = 0; x <= size - 1; ++x)
		std::cout << total.at(x) << std::endl;
	std::cout << "Do you wish to remove one of you tickets? If so, enter it's RowColumn (1A), if not, enter 0 to exit: ";
	std::cin >> input;
	for (int x = 0; x <= size - 1; x++) 
		if (input.substr(0, 1) == total.at(x).substr(0, 1)) 
			for (int y = 0; y <= size; y++)
				if (toupper(stoi(input.substr(1, 1))) == stoi(total.at(y).substr(1, 1)))
					total.at(y).erase();
	complete = true;
}
//end receipt
