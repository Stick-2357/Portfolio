#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int oldScore = 0;
	int newScore = 0;
	int newTotal = 0;
	int input = 0;
	int oldTotal = 0;
	int hold;

	cout << "What was your previous score?" << endl;
	cin >> oldTotal;

	do
	{
		cout << "What is the new score? " << endl;
		cin >> input;

		if (input == 0)
			break;

		
		newScore += input;
		cout << "Current Push Ups: " << newScore << endl;
		newTotal += newScore;
		oldScore += newScore;
		cout << "Game push-up total: " << oldScore << endl;
		

	} while (newScore != 0);
	newTotal += oldTotal;
	cout << "New total: " << newTotal;
	
	cin >> hold;
	return 0;
}