#include <iostream>
#include <string>
#include "addressType.h"

using namespace std;

void addressType::print() const {
	cout << streetAddress << "\n";
	cout << city << ", " << state << " - " << zip << "\n";
}
//end addressType::print()

void addressType::setAddress(string sAddress, string c, string s, string z) {
	streetAddress = sAddress;
	city = c;
	state = s;
	zip = z;
}
//end addressType::setAddress()

void addressType::getAddress(string& sAddress, string& c, string& s, string& z) {
	sAddress = streetAddress;
	c = city;
	s = state;
	z = zip;
}
//end addressType::getAddress()

addressType::addressType(string sAddress, string c, string s, string z) {
	streetAddress = sAddress;
	city = c;
	state = s;
	zip = z;
}
//end constructor