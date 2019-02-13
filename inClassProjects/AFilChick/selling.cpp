/*
Name: Joe Mittone & Eli Monnig
Date: 09/20/18
Desc: Selling based on the Chick-Fil-A menu
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <windows.h>

using namespace std;

//variables
vector<string> orders;
const string BREAKFASTpRICES[] = { "2.75", "3.49", "3.95", 
"3.09", "3.09", "1.09", "2.05", "1.19", "3.25", "3.15", 
"3.95", "3.89", "3.89", "3.29", "3.29", "2.65" };
const string ENTREEpRICES[] = { "3.69", "4.29", "3.99",
"4.59", "5.15", "6.55", "3.75", "4.09", "5.99", "4.49" };
const string SALADpRICES[] = { "8.19", "8.19", "8.19" };
const string SIDEpRICES[] = { "1.89", "3.15", "2.99", 
"2.99", "3.25", "3.15", "1.95", "1.85" };
const string KIDSmEALpRICES[] = { "4.99", "4.99", "5.65" };
const string TREATSpRICES[] = { "3.29", "3.29", "3.29", 
"3.29", "3.29", "1.39", "1.29", "3.29" };
const string DRINKSpRICES[] = { "1.75", "1.99", "1.75", 
"1.75", "1.75", "1.35", "2.49", "1.35", "1.35", "1.75", "2.69" };

//function protoypes
void menu();
string breakfast(double& total, string& priceOf);
string entrees(double& total, string& priceOf);
string salads(double& total, string& priceOf);
string sides(double& total, string& priceOf);
string kidsMeals(double& total, string& priceOf);
string treats(double& total, string& priceOf);
string drinks(double& total, string& priceOf);
bool subtotal(double& total);

int main()
{
	menu();
	return 0;
}

void menu()
{
	//variables
	int input = 0;
	double cost = 0.0;
	string price = " ";
	bool done = false;

	cout << fixed << showpoint << setprecision(2);

	do
	{
		system("CLS");
		cout << "Welcome to A-Fil-Chick! What would you like to do?" << endl;
		cout << "1.\t Order Breakfast" << endl;
		cout << "2.\t Order Entrees" << endl;
		cout << "3.\t Order Salads" << endl;
		cout << "4.\t Order Sides" << endl;
		cout << "5.\t Order Kid's Meals" << endl;
		cout << "6.\t Order Treats" << endl;
		cout << "7.\t Order Drinks" << endl;
		cout << "8.\t View Subtotal" << endl;
		cout << "0.\t Exit" << endl;
		cin >> input;

		switch (input)
		{
			case 1:
			{
				system("CLS");
				orders.emplace_back("1: $" + breakfast(cost, price)); //breakfast function call, returning the order info
				break;
			}//end case 1
			case 2:
			{
				system("CLS");
				orders.emplace_back("2: $" + entrees(cost, price));//entrees function call, returning the order info
				break;
			}//end case 2
			case 3:
			{
				system("CLS");
				orders.emplace_back("3: $" + salads(cost, price));//salad function call, returning the order info
				break;
			}//end case 3
			case 4:
			{
				system("CLS");
				orders.emplace_back("4: $" + sides(cost, price));//sides function call, returning the order info
				break;
			}//end case 4
			case 5:
			{
				system("CLS");
				orders.emplace_back("5: $" + kidsMeals(cost, price));//kidsMeals function call, returning the order info
				break;
			}//end case 5
			case 6:
			{
				system("CLS");
				orders.emplace_back("6: $" + treats(cost, price));//treats function call, returning the order info
				break;
			}//end case 6
			case 7:
			{
				system("CLS");
				orders.emplace_back("7: $" + drinks(cost, price));//drinks function call, returning the order info
				break;
			}//end case 7
			case 8:
			{
				do
					done = subtotal(cost);//subtotal funciton call, returning if the program should be finished
				while (!done);
				break;
			}//end case 8
			default:
				done = true;
		}//end switch
	} while (!done);
}//end menu

string breakfast(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which breakfast item would you like?" << endl;
	cout << "1.\t Order a Spicy Chicken Biscuit" << endl;
	cout << "2.\t Order 4 Chick-n-Smalls" << endl;
	cout << "3.\t Order an Egg White Grill" << endl;
	cout << "4.\t Order a Bacon, Egg & Cheese Biscuit" << endl;
	cout << "5.\t Order a Sausage, Egg & Cheese Biscuit" << endl;
	cout << "6.\t Order a Buttered Biscuit" << endl;
	cout << "7.\t Order a Sunflower Multigrain Bagel" << endl;
	cout << "8.\t Order Hash Brown" << endl;
	cout << "9.\t Order a Greek Yogurt Parfait" << endl;
	cout << "10.\t Order a Fruit Cup" << endl;
	cout << "11.\t Order Chicken, Egg & Cheese Bagel" << endl;
	cout << "12.\t Order a Hash Brown Scramble Burrito" << endl;
	cout << "13.\t Order a Hash Brown Scramble Bowl" << endl;
	cout << "14.\t Order a Bacon, Egg & Cheese Muffin" << endl;
	cout << "15.\t Order a Sausage, Egg & Cheese Muffin" << endl;
	cout << "16.\t Order a Chicken Biscuit" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;

	if (input != 0 && input <= 16)
	{
		priceOf = BREAKFASTpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Spicy Chicken Biscuit";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " 4 Chick-n-Smalls";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Egg White Grill";
			break;
		}//end case 3
		case 4:
		{
			return priceOf + " Bacon, Egg & Cheese Biscuit";
			break;
		}//end case 4
		case 5:
		{
			return priceOf + " Sausage, Egg & Cheese Biscuit";
			break;
		}//end case 5
		case 6:
		{
			return priceOf + " Buttered Biscuit";
			break;
		}//end case 6
		case 7:
		{
			return priceOf + " Sunflower Multigrain Bagel";
			break;
		}//end case 7
		case 8:
		{
			return priceOf + " Hash Browns";
			break;
		}//end case 8
		case 9:
		{
			return priceOf + " Greek Yogurt Parfait";
			break;
		}//end case 9
		case 10:
		{
			return priceOf + " Fruit Cup";
			break;
		}//end case 10
		case 11:
		{
			return priceOf + " Chicken, Egg & Cheese Bagel";
			break;
		}//end case 11
		case 12:
		{
			return priceOf + " Hash Brown Scramble Burrito";
			break;
		}//end case 12
		case 13:
		{
			return priceOf + " Hash Brown Scramble Bowl";
			break;
		}//end case 13
		case 14:
		{
			return priceOf + " Bacon, Egg & Cheese Muffin";
			break;
		}//end case 14
		case 15:
		{
			return priceOf + " Sausage, Egg & Cheese Muffin";
			break;
		}//end case 15
		case 16:
		{
			return priceOf + " Chicken Biscuit";
			break;
		}//end case 16
		default:
			return "|";
	}//end switch
}//end breakfast
string entrees(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which entree would you like?" << endl;
	cout << "1.\t Order a Chicken Sandwich" << endl;
	cout << "2.\t Order a Deluxe Chicken Sandwich" << endl;
	cout << "3.\t Order a Spicy Chicken Sandwich" << endl;
	cout << "4.\t Order a Spicy Deluxe Sandwich" << endl;
	cout << "5.\t Order a Grilled Chicken Sandwich" << endl;
	cout << "6.\t Order a Grilled Chicken Club Sandwich" << endl;
	cout << "7.\t Order 8 Chicken Nuggets" << endl;
	cout << "8.\t Order 4 Chicken Strips" << endl;
	cout << "9.\t Order a Grilled Chicken Cool Wrap" << endl;
	cout << "10.\t Order 8 Grilled Nuggets" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;

	if (input != 0 && input <= 10)
	{
		priceOf = ENTREEpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Chicken Sandwich";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " Chicken Deluxe Sandwich";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Spicy Chicken Sandwich";
			break;
		}//end case 3
		case 4:
		{
			return priceOf + " Spicy Deluxe Sandwich";
			break;
		}//end case 4
		case 5:
		{
			return priceOf + " Grilled Chicken Sandwich";
			break;
		}//end case 5
		case 6:
		{
			return priceOf + " Grilled Chicken Club Sandwich";
			break;
		}//end case 6
		case 7:
		{
			return priceOf + " Chicken Nuggets";
			break;
		}//end case 7
		case 8:
		{
			return priceOf + " Chicken Strips";
			break;
		}//end case 8
		case 9:
		{
			return priceOf + " Grilled Chicken Cool Wrap";
			break;
		}//end case 9
		case 10:
		{
			return priceOf + " Grilled Nuggets";
			break;
		}//end case 10
		default:
			return "|";
	}//end switch
}//end entrees

string salads(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which salad would you like?" << endl;
	cout << "1.\t Order a Spicy Southwest Salad" << endl;
	cout << "2.\t Order a Cobb Salad" << endl;
	cout << "3.\t Order a Market Salad" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;
	
	if (input != 0 && input <= 3)
	{
		priceOf = SALADpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Spicy Southwest Salad";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " Cobb Salad";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Market Salad";
			break;
		}//end case 3
		default:
			return "|";
	}//end switch
}//end salads

string sides(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which side would you like?" << endl;
	cout << "1.\t Order Waffle Potato Fries" << endl;
	cout << "2.\t Order a Side Salad" << endl;
	cout << "3.\t Order Chicken Noodle Soup" << endl;
	cout << "4.\t Order a Superfood Side" << endl;
	cout << "5.\t Order a Greek Yogurt Parfait" << endl;
	cout << "6.\t Order a Fruit Cup" << endl;
	cout << "7.\t Order an Applesauce Pouch " << endl;
	cout << "8.\t Order Waffle Potato Chips" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;

	if (input != 0 && input <= 8)
	{
		priceOf = SIDEpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Waffle Potato Fries";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " Side Salad";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Chicken Noodle Soup";
			break;
		}//end case 3
		case 4:
		{
			return priceOf + " Superfood Side";
			break;
		}//end case 4
		case 5:
		{
			return priceOf + " Greek Yogurt Parfait";
			break;
		}//end case 5
		case 6:
		{
			return priceOf + " Fruit Cup";
			break;
		}//end case 6
		case 7:
		{
			return priceOf + " Applesauce Pouch";
			break;
		}//end case 7
		case 8:
		{
			return priceOf + " Waffle Potato Chips";
			break;
		}//end case 8
		default:
			return "|";
	}//end switch
}//end sides

string kidsMeals(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which kid's meal would you like?" << endl;
	cout << "1.\t Order a Nuggets Kid's Meal" << endl;
	cout << "2.\t Order a Chicken Strips Kid's Meal" << endl;
	cout << "3.\t Order a Grilled Nuggets Kid's Meal" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;

	if (input != 0 && input <= 3)
	{
		priceOf = KIDSmEALpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Nuggets Kid's Meal";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " Chicken Strips Kid's Meal";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Grilled Nuggets Kid's Meal";
			break;
		}//end case 3
		default:
			return "|";
	}//end switch
}//end kids meals

string treats(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which side would you like?" << endl;
	cout << "1.\t Order a Frosted Lemonade" << endl;
	cout << "2.\t Order a Chocolate Milkshake" << endl;
	cout << "3.\t Order a Cookies & Cream Milkshake" << endl;
	cout << "4.\t Order a Vanilla Milkshake" << endl;
	cout << "5.\t Order a Strawberry Milkshake" << endl;
	cout << "6.\t Order an Icecream Cone" << endl;
	cout << "7.\t Order a Chocolate Chunk Cookie " << endl;
	cout << "8.\t Order a Frosted Coffee" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;

	if (input != 0 && input <= 8)
	{
		priceOf = TREATSpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Frosted Lemonade";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " Chocolate Milkshake";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Cookies & Cream Milkshake";
			break;
		}//end case 3
		case 4:
		{
			return priceOf + " Vanilla Milkshake";
			break;
		}//end case 4
		case 5:
		{
			return priceOf + " Strawberry Milkshake";
			break;
		}//end case 5
		case 6:
		{
			return priceOf + " Icecream Cone";
			break;
		}//end case 6
		case 7:
		{
			return priceOf + " Chocolate Chunk Cookie";
			break;
		}//end case 7
		case 8:
		{
			return priceOf + " Frosted Coffee";
			break;
		}//end case 8
		default:
			return "|";
	}//end switch
}//end treats

string drinks(double& total, string& priceOf)
{
	int input = 0;

	system("CLS");
	cout << "Which drink would you like?" << endl;
	cout << "1.\t Order a Freshly-Brewed Sweetened Iced Tea" << endl;
	cout << "2.\t Order a Lemonade" << endl;
	cout << "3.\t Order a Coca-Cola" << endl;
	cout << "4.\t Order a Dr Pepper" << endl;
	cout << "5.\t Order a Bottled Water" << endl;
	cout << "6.\t Order an Apple Juice" << endl;
	cout << "7.\t Order an Orange Juice " << endl;
	cout << "8.\t Order a 1% Chocolate Milk" << endl;
	cout << "9.\t Order a 1% White Milk" << endl;
	cout << "10.\t Order a Coffee" << endl;
	cout << "11.\t Order an Iced Coffee" << endl;
	cout << "0.\t Back" << endl;
	cin >> input;

	if (input != 0 && input <= 11)
	{
		priceOf = DRINKSpRICES[input - 1];
		total += stod(priceOf);
	}//end if

	switch (input)
	{
		case 1:
		{
			return priceOf + " Freshly-Brewed Iced Tea Sweetened";
			break;
		}//end case 1
		case 2:
		{
			return priceOf + " Lemonade";
			break;
		}//end case 2
		case 3:
		{
			return priceOf + " Coca-Cola";
			break;
		}//end case 3
		case 4:
		{
			return priceOf + " Dr. Pepper";
			break;
		}//end case 4
		case 5:
		{
			return priceOf + " Bottled Water";
			break;
		}//end case 5
		case 6:
		{
			return priceOf + " Apple Juice";
			break;
		}//end case 6
		case 7:
		{
			return priceOf + " Orange Juice";
			break;
		}//end case 7
		case 8:
		{
			return priceOf + " 1% Chocolate Milk";
			break;
		}//end case 8
		case 9:
		{
			return priceOf + " 1% White Milk";
			break;
		}//end case 9
		case 10:
		{
			return priceOf + " Coffee";
			break;
		}//end case 10
		case 11:
		{
			return priceOf + " Iced Coffee";
			break;
		}//end case 11
		default:
			return "|";
	}//end switch
}//end drinks

bool subtotal(double& total)
{
	int input = 0;
	int catagory = 0;
	double tip = 0.0;
	string priceOf = " ";
	char hasCoupon = ' ';

	system("CLS");

	for (int counter = 0; counter < (int)(orders.size()); counter += 1)
		if (orders.at(counter).find("|") != string::npos)
			orders.erase(orders.begin() + counter);

	for (int counter = 0; counter < (int)(orders.size()); counter += 1)
		cout << "#" << counter + 1 << "\t" << orders.at(counter) << endl;

		cout << "Do you wish to remove any items from your order? Select it's number to remove it, or enter 0 to confirm." << endl;
		cin >> input;

		switch (input)
		{
			case 0:
			{
				system("CLS");
				for (int counter = 0; counter < (int)(orders.size()); counter += 1)
					cout << counter + 1 << "\t" << orders.at(counter) << endl;
				cout << "Your subtotal is : $" << total << endl;
				cout << "How much do you want to tip? We recommend somewhere around $" << total * .1 << ". ";
				cin >> tip;
				total += total * .0775;
				cout << "Do you have any coupons? (y/n) ";
				cin >> hasCoupon;
				if (hasCoupon == 'y' || hasCoupon == 'Y')
				{
					system("CLS");
					cout << "Which catagory does you coupon fall under?" << endl;
					cout << "1.\t Breakfast" << endl;
					cout << "2.\t Entrees" << endl;
					cout << "3.\t Salads" << endl;
					cout << "4.\t Sides" << endl;
					cout << "5.\t Kid's Meals" << endl;
					cout << "6.\t Treats" << endl;
					cout << "7.\t Drinks" << endl;
					cout << "8.\t Whole Order" << endl;
					cout << "0.\t Exit" << endl;
					cin >> catagory;

					system("CLS");
					switch (catagory)
					{
						case 1:
						{
							cout << "Which breakfast item do you have a coupon for?" << endl;
							cout << "1.\t Spicy Chicken Biscuit" << endl;
							cout << "2.\t 4 Chick-n-Smalls" << endl;
							cout << "3.\t Egg White Grill" << endl;
							cout << "4.\t Bacon, Egg & Cheese Biscuit" << endl;
							cout << "5.\t Sausage, Egg & Cheese Biscuit" << endl;
							cout << "6.\t Buttered Biscuit" << endl;
							cout << "7.\t Sunflower Multigrain Bagel" << endl;
							cout << "8.\t Hash Browns" << endl;
							cout << "9.\t Greek Yogurt Parfait" << endl;
							cout << "10.\t Fruit Cup" << endl;
							cout << "11.\t Chicken, Egg & Cheese Bagel" << endl;
							cout << "12.\t Hash Brown Scramble Burrito" << endl;
							cout << "13.\t Hash Brown Scramble Bowl" << endl;
							cout << "14.\t Bacon, Egg & Cheese Muffin" << endl;
							cout << "15.\t Sausage, Egg & Cheese Muffin" << endl;
							cout << "16.\t Chicken Biscuit" << endl;
							cout << "0.\t Back";
							break;
						}//end case 1
						case 2:
						{
							cout << "Which entree do you have a coupon for?" << endl;
							cout << "1.\t Chicken Sandwich" << endl;
							cout << "2.\t Deluxe Chicken Sandwich" << endl;
							cout << "3.\t Spicy Chicken Sandwich" << endl;
							cout << "4.\t Spicy Deluxe Sandwich" << endl;
							cout << "5.\t Grilled Chicken Sandwich" << endl;
							cout << "6.\t Grilled Chicken Club Sandwich" << endl;
							cout << "7.\t 8 Chicken Nuggets" << endl;
							cout << "8.\t 4 Chicken Strips" << endl;
							cout << "9.\t Grilled Chicken Cool Wrap" << endl;
							cout << "10.\t 8 Grilled Nuggets" << endl;
							cout << "0.\t Back" << endl;
							break;
						}//end case 2
						case 3:
						{
							cout << "Which salad do you have a coupon for?" << endl;
							cout << "1.\t Spicy Southwest Salad" << endl;
							cout << "2.\t Cobb Salad" << endl;
							cout << "3.\t Market Salad" << endl;
							cout << "0.\t Back" << endl;
							break;
						}//end case 3
						case 4:
						{
							cout << "Which side do you have a coupon for?" << endl;
							cout << "1.\t Waffle Potato Fries" << endl;
							cout << "2.\t Side Salad" << endl;
							cout << "3.\t Chicken Noodle Soup" << endl;
							cout << "4.\t Superfood Side" << endl;
							cout << "5.\t Greek Yogurt Parfait" << endl;
							cout << "6.\t Fruit Cup" << endl;
							cout << "7.\t Applesauce Pouch " << endl;
							cout << "8.\t Waffle Potato Chips" << endl;
							cout << "0.\t Back" << endl;
							break;
						}//end case 4
						case 5:
						{
							cout << "Which kid's meal do you have a coupon for?" << endl;
							cout << "1.\t Nuggets Kid's Meal" << endl;
							cout << "2.\t Chicken Strips Kid's Meal" << endl;
							cout << "3.\t Grilled Nuggets Kid's Meal" << endl;
							cout << "0.\t Back" << endl;
							break;
						}//end case 5
						case 6:
						{
							cout << "Which side do you have a coupon for?" << endl;
							cout << "1.\t Frosted Lemonade" << endl;
							cout << "2.\t Chocolate Milkshake" << endl;
							cout << "3.\t Cookies & Cream Milkshake" << endl;
							cout << "4.\t Vanilla Milkshake" << endl;
							cout << "5.\t Strawberry Milkshake" << endl;
							cout << "6.\t Icecream Cone" << endl;
							cout << "7.\t Chocolate Chunk Cookie " << endl;
							cout << "8.\t Frosted Coffee" << endl;
							cout << "0.\t Back" << endl;
							break;
						}//end case 6
						case 7:
						{
							cout << "Which drink do you have a coupon for?" << endl;
							cout << "1.\t Freshly-Brewed Sweetened Iced Tea" << endl;
							cout << "2.\t Lemonade" << endl;
							cout << "3.\t Coca-Cola" << endl;
							cout << "4.\t Dr Pepper" << endl;
							cout << "5.\t Bottled Water" << endl;
							cout << "6.\t Apple Juice" << endl;
							cout << "7.\t Orange Juice " << endl;
							cout << "8.\t 1% Chocolate Milk" << endl;
							cout << "9.\t 1% White Milk" << endl;
							cout << "10.\t Coffee" << endl;
							cout << "11.\t Iced Coffee" << endl;
							cout << "0.\t Back" << endl;
							break;
						}//end case 7
						case 8:
							break;
						default:
						{
							cout << "Why did you say you had one then?";
							return false;
						}//end default
					}//end switch
					if (catagory != 8)
						cin >> input;

					system("CLS");
					cout << "Your subtotal was $" << total << "." << endl;
					cout << "You tipped $" << tip << "." << endl;
					if (catagory == 1 && input < 17)
					{
						total -= stod(BREAKFASTpRICES[input]);
						total += stod(BREAKFASTpRICES[input]) * .15;
					}//end if
					else if (catagory == 2 && input < 11)
					{
						total -= stod(ENTREEpRICES[input]);
						total += stod(ENTREEpRICES[input]) * .15;
					}//end else if
					else if (catagory == 3 && input < 4)
					{
						total -= stod(SALADpRICES[input]);
						total += stod(SALADpRICES[input]) * .15;
					}//end else if
					else if (catagory == 4 && input < 9)
					{
						total -= stod(SIDEpRICES[input]);
						total += stod(SIDEpRICES[input]) * .15;
					}//end else if
					else if (catagory == 5 && input < 4)
					{
						total -= stod(KIDSmEALpRICES[input]);
						total += stod(KIDSmEALpRICES[input]) * .15;
					}//end else if
					else if (catagory == 6 && input < 9)
					{
						total -= stod(TREATSpRICES[input]);
						total += stod(TREATSpRICES[input]) * .15;
					}//end else if
					else if (catagory == 7 && input < 12)
					{
						total -= stod(DRINKSpRICES[input]);
						total += stod(DRINKSpRICES[input]) * .15;
					}//end else if
					else
						total -= total * .15;
					cout << "Your subtotal after coupons is $" << total << "." << endl;
				}//end if
				cout << "Your tax is : 7.75%" << endl;
				cout << "Your total is : $" << total + tip << ".";
				Sleep(5000);
				return true;
			}//end case 0
			default:
			{
				if (input <= (int)(orders.size()) && input > 0)
				{
					priceOf = orders.at(input - 1).substr(4, 4);
					total -= stod(priceOf);
					orders.erase(orders.begin() + input - 1);
				}//end if
				else
					cout << "Your input didn't fit what we were expecting. Please try again.";
				Sleep(1000);
				return false;
			}//end default
		}//end switch
}//end subtotal