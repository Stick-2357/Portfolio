#include <iostream>
#include <string>
#include "personType.h" 

using namespace std;

void personType::print() const {
	cout << firstName << " " << lastName;
}
//end personType::print()

void personType::setName(string first, string last) {
	firstName = first;
	lastName = last;
}
//end personType::setName()

string personType::getFirstName() const {
	return firstName;
}
//end personType::getFirstName()

string personType::getLastName() const {
	return lastName;
}
//end personType::getLastName()

//constructor
personType::personType(string first, string last) {
	firstName = first;
	lastName = last;
}
//end constructor