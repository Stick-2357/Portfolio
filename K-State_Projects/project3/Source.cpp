#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int numPoints;

	double xVals[10];
	double yVals[10];

	while (true) {
		cout << endl;

		cout << "Enter number of points: ";
		cin >> numPoints;

		for (int i = 0; i < numPoints; i++) {
			cout << "Enter x" << i << ": ";
			cin >> xVals[i];

			cout << "Enter y" << i << ": ";
			cin >> yVals[i];

		}

		double closestDist = 9999999999;
		int closestPair1 = 0;
		int closestPair2 = 0;
		double currentDist;

		for (int i = 0; i < numPoints; i++) {
			for (int j = i+1; j < numPoints; j++) {
				currentDist = ((xVals[i] - xVals[j]) * (xVals[i] - xVals[j])) + ((yVals[i] - yVals[j]) * (yVals[i] - yVals[j]));
				if (currentDist < closestDist) {
					closestDist = currentDist;
					closestPair1 = i;
					closestPair2 = j;
				}
			}
		}

		cout << "(" << xVals[closestPair1] << ", " << yVals[closestPair1] << ") and " << "(" << xVals[closestPair2] << ", " << yVals[closestPair2] << ") are closest." << endl;

		system("pause");
	}

	system("pause");
	return 0;
}