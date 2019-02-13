#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int length;
	int width;
	int smallest;
	int volumn = 0;
	int temp = 0;
	int best = 0;
	cout << "Enter length of the cardboard: ";
	cin >> length;

	cout << "Enter width of the cardboard: ";
	cin >> width;

	for (int h = 1; h <= width/2; h++) {
		temp = h * (length - (2 * h)) * (width - (2 * h));
		if (temp > volumn) {
			volumn = temp;
			best = h;
		}
	}

	length -= best * 2;
	width -= best * 2;

	cout << "length = " << length << endl;
	cout << "width = " << width << endl;
	cout << "height = " << best << endl;
	cout << "volume = " << volumn << endl;
	system("pause");
	return 0;
}