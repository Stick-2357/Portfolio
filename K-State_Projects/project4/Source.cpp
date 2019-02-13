#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int totalNum;
	int totalDen;
	int newNum;
	int newDen;

	int simpNum;
	int simpDen;

	int whole;
	int remainder;

		cout << endl;

		cout << "Num1: ";
		cin >> totalNum;
		cout << "Den1: ";
		cin >> totalDen;

		while (true) {
			cout << "Num: ";
			cin >> newNum;
			cout << "Den: ";
			cin >> newDen;

			//if (newDen == 0) continue;

			bool br = false;
			for (int i = 1; i <= newDen; i++) {
				for (int j = 1; j < totalDen; j++) {
					 
					if (totalDen * i == newDen * j) {
						simpDen = totalDen * i;
						simpNum = (totalNum * i) + (newNum * j);
						totalDen = simpDen;
						totalNum = simpNum;

						br = true;
						break;
					}
				}
				if (br)
					break;
			}


			whole = simpNum / simpDen;
			remainder = simpNum % simpDen;

			cout << whole << " " << remainder << "/" << simpDen << endl;
		}

	system("pause");
	return 0;
}