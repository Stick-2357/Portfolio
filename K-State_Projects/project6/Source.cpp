#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

struct cardType{
	int value;
	int pos = 100;
	bool in;
};

int main() {

	int numOfCards;
	int valofcards;
	int amountLeft = 0;
	double numHigher;
	int numLower;
	double probHigh;
	int choice;

	double prob;

	bool taken = false;

	cardType deck[90];

	cout << "Input number of cards: ";
	cin >> numOfCards;

	valofcards = numOfCards - 1;

	srand(time(NULL));

	for (int n = 0; n <= numOfCards; n++) {
		deck[n].value = n;
		taken = false;
		do {
			deck[n].pos = rand() % numOfCards;
			for (int w = 0; w <= numOfCards; w++)
				if (w != n) {
					if (deck[w].pos == deck[n].pos) {
						taken = true;
					}
				}
		} while (taken);
		amountLeft++;
	}
	do {
		cout << "Enter next card: ";
		cin >> choice;
		for (int n = 0; n <= numOfCards; n++) {
			amountLeft--;
			numHigher = amountLeft - choice;
			numHigher /= 100;
			probHigh = static_cast<double>(numHigher) / amountLeft;
			cout << probHigh << endl;
			system("pause");
		}
	} while (true);
	system("pause");
	return 0;
}