/*
Name:			Eli Monnig and Jacob Winslow
Date:			08.21.18
Description:	Plays multiple iterations of the Prisoner's Dilemma with multiple differnt stratagies vs a 
				human player or two bots against eachother.*/

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>


using namespace std;

int main()
{
	//variables
	bool player1Betray = true;
	bool player2Betray = true;
	bool humanPlayer;
	int player1Total = 0;
	int player2Total = 0;
	int player1Type = 0;
	int player2Type = 0;
	char tempChar = ' ';
	int tempInt = 0;
	int i = 0;
	int hold;
	
	//explaination
	cout << "The Prisoner's Dilemma" << endl << "Two members of a criminal gang are arrested and imprisoned. ";
	cout << "Each prisoner is in solitary confinement with no means of " << endl << "communicating with the other. ";
	cout << "The prosecutors lack sufficient evidence to convict the pair on the principal charge, " << endl; 
	cout << "but they have enough to convict both on a lesser charge. Simultaneously, the prosecutors offer each ";
	cout << "prisoner a bargain. Each prisoner is given the opportunity either to betray the other by testifying ";
	cout << "that the other committed the crime," << endl << " or to cooperate with the other by remaining silent. ";
	cout << "The offer is : "<< endl << "If A and B each betray the other, each of them serves two years in prison";
	cout << endl << "If A betrays B but B remains silent, A will be set free and B will serve three years in prison ";
	cout << "(and vice versa)" << endl << "If A and B both remain silent, both of them will only serve one year in ";
	cout << "prison(on the lesser charge)." << endl ;

	//choose human player
	cout << "Do you want to play? Y for yes, N for no. ";
	cin >> tempChar;
	if (tempChar == 'y' || tempChar == 'Y')
		humanPlayer = true;
	else
		humanPlayer = false;
	cout << endl;

	//choose computer playstyle(s)
	if (humanPlayer == false)
	{
		while (player1Type < 1)
		{
			cout << "Which stratagy do you want player 1 to play with? T for 'tit for tat', D for 'always defect', ";
			cout << "C for 'always cooperate', or R for 'random'. " << endl;
			cin >> tempChar;
			if (tempChar == 't' || tempChar == 'T')
				player1Type = 1;
			else if (tempChar == 'd' || tempChar == 'D')
				player1Type = 2;
			else if (tempChar == 'c' || tempChar == 'C')
				player1Type = 3;
			else if (tempChar == 'r' || tempChar == 'R')
			{
				srand(time_t(NULL));
				player1Type = rand() % 3 + 1;
			}
			else
			{
				cout << "Please enter an option given." << endl;
				tempChar = ' ';
			}
		}
	}
	while (player2Type < 1)
		{
			cout << "Which stratagy would you want to play against? T for 'tit for tat', D for 'always defect', ";
			cout << "C for 'always cooperate', or R for 'random'. " << endl;
			cin >> tempChar;
			if (tempChar == 't' || tempChar == 'T')
				player2Type = 1;
			else if (tempChar == 'd' || tempChar == 'D')
				player2Type = 2;
			else if (tempChar == 'c' || tempChar == 'C')
				player2Type = 3;
			else if (tempChar == 'r' || tempChar == 'R')
			{
				srand(time_t(NULL));
				player2Type = rand() % 3 + 1;
			}
			else
			{
				cout << "Please enter an option given." << endl;
				tempChar = ' ';
			}
		}

		//interaction
		while (i <= 10)
		{
			if (player2Type == 1) //tit for tat
				if (i == 0)
					player2Betray = false;
				else
					if (player1Betray == true)
						player2Betray = true;
					else
						player2Betray = false;
			else if (player2Type == 2) //always defect
				player2Betray = true;
			else if (player2Type == 3) //always cooperate
				player2Betray = false;

			//user input
			if (humanPlayer == true)
			{
				cout << endl << "Player 1: Do you want to betray player 2? Y for yes, N for no. ";
				cin >> tempChar;
				if (tempChar == 'y' || tempChar == 'Y')
					player1Betray = true;
				else
					player1Betray = false;
			}
			else
			{
				if (player1Type == 1) //tit for tat
					if (i == 0)
						player1Betray = false;
					else
						if (player2Betray == true)
							player1Betray = false;
						else
							player1Betray = true;
				else if (player1Type == 2) //always defect
					player1Betray = false;
				else if (player1Type == 3) //always cooperate
					player1Betray = true;
			}

			system("cls");

			//results
			cout << "Results:" << endl;
			if (player1Betray == true)
				if (player2Betray == true)
				{
					cout << "Both players get two years in prison.";
					player1Total += 2;
					player2Total += 2;
				}
				else
				{
					cout << "Player 1 gets out scott free, while Player 2 is stuck in prison for three years.";
					player2Total += 3;
				}
			else
				if (player2Betray == true)
				{
					cout << "Player 2 gets out scott free, while Player 1 is stuck in prison for three years.";
					player1Total += 3;
				}
				else
				{
					cout << "Both players get one year in prison.";
					player1Total += 1;
					player2Total += 1;
				}
			cout << endl << "Totals:" << endl << "Player1: " << player1Total << endl << "Player2: " << player2Total;
			cout << endl;
			i++;
			Sleep(50);
		}

		//final results
		if (player1Total < player2Total)
		{
			cout << "Player1 wins!";
		}
		else if (player1Total > player2Total)
		{
			cout << "Player1 wins!";
		}
		else
		{
			cout << "It's a tie!";
		}

		cin >> hold;
		return 0;
	}
