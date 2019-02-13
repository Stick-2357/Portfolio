/*
Name:			Eli and Dylan
Date:			09.10.2018
Description:	Selling with random tax
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//variables
	bool restart = true;
	int hold;
	int counter = 1;
	int orders = 0;
	int choice = 0;
	int drink = 0;
	double tax = 0.0;
	double pricePer = 9.99;
	double priceTotal = 0.0;
	char ice = ' ';
	char correct = ' ';
	string side = " ";
	string pasta = " ";
	string sause = " ";
	string topping = " ";
	string beverage = " ";

	cout << "Welcome to All-Of Gardens' new Create Your Own Pasta Take-Out maker." << endl;
	cout << "How many orders are you going to take? ";
	cin >> orders;
	while (counter <= orders) 
	{
		while (restart = true)
		{
			cout << "This is your " << counter << " order." << endl;
			cout << "First, what would you like for your complemetary side?" << endl;
			cout << "***************************************************" << endl;
			cout << "**  1.		House Salad			 **" << endl;
			cout << "**  2.		Chicken & Gnocchi		 **" << endl;
			cout << "**  3.		Pasta e Fagioli			 **" << endl;
			cout << "**  4.		Minestrone Soup			 **" << endl;
			cout << "**  5.		Zuppa Tascana			 **" << endl;
			cout << "**  0.		None				 **" << endl;
			cout << "***************************************************" << endl;
			cin >> choice;
			switch (choice)
			{
				case 1:
				{
					side = "House Salad";
					break;
				}//end of case 1
				case 2:
				{
					side = "Chicken & Gnocchi";
					break;
				}//end of case 2
				case 3:
				{
					side = "Pasta e Fagioli";
					break;
				}//end of case 3
				case 4:
				{
					side = "Minestrone Soup";
					break;
				}//end of case 4
				case 5:
				{
					side = "Zuppa Toscana";
					break;
				}//end of case 5 
				default:
				{
					side = "None";
					break;
				}//end of default
			}//end switch

			cout << "What kind of pasta would you like?" << endl;
			cout << "***************************************************" << endl;
			cout << "**  1.		Rigatoni			 **" << endl;
			cout << "**  2.		Cavatappi			 **" << endl;
			cout << "**  3.		Spaghetti			 **" << endl;
			cout << "**  4.		Angel Hair			 **" << endl;
			cout << "**  5.		Whole Grain Linguine		 **" << endl;
			cout << "**  6.		Gluteen-Free Rotini		 **" << endl;
			cout << "***************************************************" << endl;
			do
			{
				cin >> choice;
				switch (choice)
					{
					case 1:
					{
						pasta = "Rigatoni";
						break;
					}//end of case 1
					case 2:
					{
						pasta = "Cavatappi";
						break;
					}//end of case 2
					case 3:
					{
						pasta = "Spaghetti";
						break;
					}//end of case 3
					case 4:
					{
						pasta = "Angel Hair";
						break;
					}//end of case 4
					case 5:
					{
						pasta = "Whole Grain Linguine";
						break;
					}//end of case 5 
					case 6:
					{
						pasta = "Gluten-Free Rotini";
						break;
					}//end of case 6 
					default:
					{
						pasta = " ";
						cout << "Please choose an available option.";
						break;
					}//end of default
				}//end switch
			} while (pasta == " ");

			cout << "What kind of sause would you like?" << endl;
			cout << "***************************************************" << endl;
			cout << "**  1.		Traditional Marinara		 **" << endl;
			cout << "**  2.		Five Cheese Marinara		 **" << endl;
			cout << "**  3.		Traditional Meat Sause 		 **" << endl;
			cout << "**  4.		Creamy Pesto			 **" << endl;
			cout << "**  5.		Creamy Mushroom			 **" << endl;
			cout << "***************************************************" << endl;
			do
			{
				cin >> choice;
				switch (choice)
				{
					case 1:
					{
						sause = "Traditional Marinara";
						break;
					}//end of case 1
					case 2:
					{
						sause = "Five Cheese Marinara";
						break;
					}//end of case 2
					case 3:
					{
						sause = "Traditional Meat Sause";
						break;
					}//end of case 3
					case 4:
					{
						sause = "Creamy Pesto";
						break;
					}//end of case 4
					case 5:
					{
						sause = "Creamy Mushroom";
						break;
					}//end of case 5 
					default:
					{
						sause = " ";
						cout << "Please choose an available option.";
						break;
					}//end of default
				}//end switch
			} while (sause == " ");

			cout << "What topping would you like?" << endl;
			cout << "***************************************************" << endl;
			cout << "**  1.		Meatballs 			 **" << endl;
			cout << "**  2.		Italian Sausage			 **" << endl;
			cout << "**  3.		Grilled Chicken			 **" << endl;
			cout << "**  4.		Crispy Chicken Fritta		 **" << endl;
			cout << "**  5.		Sauteed Shrimp			 **" << endl;
			cout << "**  6.		Garden Veggies			 **" << endl;
			cout << "**  0.		None				 **" << endl;
			cout << "***************************************************" << endl;
			cin >> choice;
			switch (choice)
			{
				case 1:
				{
					topping = "Meatballs";
					pricePer += 2.79;
					break;
				}//end of case 1
				case 2:
				{
					topping = "Italian Sausage";
					pricePer += 2.79;
					break;
				}//end of case 2
				case 3:
				{
					topping = "Grilled Chicken";
					pricePer += 3.29;
					break;
				}//end of case 3
				case 4:
				{
					topping = "Crispy Chicken Fritta";
					pricePer += 2.99;
					break;
				}//end of case 4
				case 5:
				{
					topping = "Sauteed Shrimp";
					pricePer += 3.99;
					break;
				}//end of case 5 
				case 6:
				{
					topping = "Garden Veggies";
					pricePer += 0.99;
					break;
				}//end of case 6 
				default:
				{
					topping = "None";
					break;
				}//end of default
			}//end switch

			cout << "What would you like to drink?" << endl;
			cout << "***************************************************" << endl;
			cout << "**  1.		Soft Drink 			 **" << endl;
			cout << "**  2.		Tea				 **" << endl;
			cout << "**  3.		Ice Coffee			 **" << endl;
			cout << "**  4.		Limonata		 	 **" << endl;
			cout << "**  5.		Mixed Berry Sparkling Water	 **" << endl;
			cout << "**  0.		None				 **" << endl;
			cout << "***************************************************" << endl;
			do
			{
				cin >> choice;
				switch (choice)
				{
					case 1:
					{
						pricePer += 2.79;
						cout << "What kind of soft drink would you like?" << endl;
						cout << "***************************************************" << endl;
						cout << "**  1.		Coke 				 **" << endl;
						cout << "**  2.		Diet Coke			 **" << endl;
						cout << "**  3.		Coke Zero Sugar			 **" << endl;
						cout << "**  4.		Sprite				 **" << endl;
						cout << "**  5.		Dr. Pepper			 **" << endl;
						cout << "**  0.		Back				 **" << endl;
						cout << "***************************************************" << endl;
						cin >> drink;
						switch (drink)
						{
							case 1:
							{
								beverage = "Coke";
								break;
							}
							case 2:
							{
								beverage = "Diet Coke";
								break;
							}
							case 3:
							{
								beverage = "Coke Zero Sugar";
								break;
							}
							case 4:
							{
								beverage = "Sprite";
								break;
							}
							case 5:
							{
								beverage = "Dr. Pepper";
								break;
							}
							default:
							{
								beverage = " ";
								pricePer -= 2.79;
								break;
							}
						}
						if (beverage != " ")
						{
							cout << "Would you like ice in your drink? (y/n) ";
							cin >> ice;
						}
					}//end of case 1
					case 2:
					{
						cout << "What kind of tea would you like?" << endl;
						cout << "***************************************************" << endl;
						cout << "**  1.		Fresh Brewed Iced Tea 		 **" << endl;
						cout << "**  2.		Bellini Peach-Raspberry Iced Tea **" << endl;
						cout << "**  3.		Blackberry-Pineapple Tea	 **" << endl;
						cout << "**  0.		Back				 **" << endl;
						cout << "***************************************************" << endl;
						cin >> drink;
						switch (drink)
						{
							case 1:
							{
								beverage = "Fresh Brewed Iced Tea";
								pricePer += 2.79;
								break;
							}
							case 2:
							{
								beverage = "Bellini Peach-Raspberry Iced Tea";
								pricePer += 2.99;
								break;
							}
							case 3:
							{
								beverage = "Blackberry-Pineapple Tea";
								pricePer += 2.99;
								break;
							}
							default:
							{
								beverage = " ";
								break;
							}
						}
						break;
					}//end of case 2
					case 3:
					{
						beverage = "Ice Coffee";
						pricePer += 3.0;
						break;
					}//end of case 3
					case 4:
					{
						pricePer += 3.25;
						cout << "What kind of limonata would you like?" << endl;
						cout << "***************************************************" << endl;
						cout << "**  1.		Strawberry-Passion Fruit Limonata**" << endl;
						cout << "**  2.		Blueberry Limonata		 **" << endl;
						cout << "**  3.		Kiwi-Melon Limonata		 **" << endl;
						cout << "**  0.		Back				 **" << endl;
						cout << "***************************************************" << endl;
						cin >> drink;
						switch (drink)
						{
							case 1:
							{
								beverage = "Strawberry-Passion Fruit Limonata";
								break;
							}
							case 2:
							{
								beverage = "Blueberry Limonata";
								break;
							}
							case 3:
							{
								beverage = "Kiwi-Melon Limonata";
								break;
							}
							default:
							{
								beverage = " ";
								pricePer += 3.25;
								break;
							}
						}
						break;
					}//end of case 4
					case 5:
						{
							beverage = "Mixed Berry Sparkling Water";
							pricePer += 3.25;
							break;
						}//end of case 5 
					default:
						{
							beverage = "None";
							break;
						}//end of default
				}//end switch
			} while (beverage == " ");
			cout << "You placed an order of " << pasta << " with " << sause << " and ";
			topping != " " ? cout << topping << ", " : cout << "no toppings, ";
			side != " " ? cout << "a side of " << side << " and" : cout << "with no side and";
			beverage != " " ? cout << " a " << beverage << " to drink." : cout << " nothing to drink.";
			cout << endl << "This will cost $" << fixed << showpoint << setprecision(2) << pricePer << ". Is this correct? (y/n) ";
			cin >> correct;
			if (correct == 'y' || correct == 'Y')
				restart = false;
			else
			{
				pricePer = 9.99;
				restart = true;
			}
		}//end while
		priceTotal += pricePer;
		pricePer = 9.99;
		cout << "Your new total is $" << fixed << showpoint << setprecision(2) << priceTotal;
		counter += 1;
	} 
	cout << "Your subtotal is : " << fixed << showpoint << setprecision(2) << priceTotal << endl;
	srand(time(0));
	tax = rand() % 100 + 1;
	cout << "Your tax is : " << tax << "%";
	cout << "Your total is : " << fixed << showpoint << setprecision(2) << priceTotal - ((tax / 100) * priceTotal);
	cin >> hold;
	return 0;
}
