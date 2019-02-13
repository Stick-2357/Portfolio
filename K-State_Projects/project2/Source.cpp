#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int numRooms;
	int roomSize;
	int sqftLeft = 5000;
	int roomsCleaned = 0;
	

		cout << "How many rooms are there? ";
		cin >> numRooms;

		for (int i = 0; i < numRooms; i++) {
			cout << "Enter the size of room " << (i + 1) << " in square feet: ";
			cin >> roomSize;
			if (roomSize <= sqftLeft) {
				roomsCleaned++;
				sqftLeft -= roomSize;
			}
		}

		cout << "Number of rooms cleaned: " << roomsCleaned << endl;

		system("pause");
	return 0;
}