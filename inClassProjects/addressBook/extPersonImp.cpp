#include <iostream>
#include <string>
#include "extPersonType.h" 

void extPersonType::printAddress() const {
	personType::print();
	cout << "\n";

	address.print();
}
//end extPersonType::printAddress()

void extPersonType::printInfo() const {
	personType::print();
	cout << "\n";

	cout << "Date of Birth: ";
	DOB.printDate();
	cout << "\n";

	cout << "Phone Number: " << phoneNumber << "\n";
	cout << "Person Type: " << personStatus << "\n";
	address.print();
	cout << "\n";
}
//end extPersonType::printInfo()

void extPersonType::setInfo(string fName, string lName, int month, int day, int year, string street, string c, string s, string z, string phone, 
	string pStatus) {
	personType::setName(fName, lName);
	DOB.setDate(month, day, year);
	address.setAddress(street, c, s, z);
	phoneNumber = phone;
	personStatus = pStatus;
}
//end extPersonType::setInfo()

void extPersonType::setInfo(string fName, string lName, dateType d, addressType ad, string phone, string pStatus) {
	personType::setName(fName, lName);
	DOB = d;
	address = ad;
	phoneNumber = phone;
	personStatus = pStatus;
}
//end extPersonType::setInfo()

bool extPersonType::isLastName(string lName) const {
	return(getLastName() == lName);
}
//end extPersonType::isLastName()

void extPersonType::getAddress(string& sAddress, string& c, string& s, string& z) {
	address.getAddress(sAddress, c, s, z);
}
//end extPersonType::getAddress()

string extPersonType::getPhoneNumber() const {
	return phoneNumber;
}
//end extPersonType::getPhoneNumber()

string extPersonType::getStatus() const {
	return personStatus;
}
//end extPersonType::getStatus()

bool extPersonType::isStatus(string status) {
	return (status == personStatus);
}
//end extPersonType::isStatus()

bool extPersonType::isDOB(int month, int day, int year) {
	return(DOB.getMonth() == month && DOB.getDay() == day && DOB.getYear() == year);
}
//end extPersonType::isDOB()

void extPersonType::getDOB(int& month, int& day, int& year) {
	month = DOB.getMonth();
	day = DOB.getDay();
	year = DOB.getYear();
}
//end extPersonType::getDOB()

bool extPersonType::isMonth(int month)  const {
	return(DOB.getMonth() == month);
}
//end extPersonType::isMonth

extPersonType::extPersonType(string fName, string lName, int month, int day, int year, string street, string c, string s, string z, string phone,
	string pStatus) {
	personType::setName(fName, lName);
	DOB.setDate(month, day, year);
	address.setAddress(street, c, s, z);
	phoneNumber = phone;
	personStatus = pStatus;
}
//end constructor
