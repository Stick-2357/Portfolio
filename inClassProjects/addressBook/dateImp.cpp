#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year) {
	dMonth = month;
	dDay = day;
	dYear = year;
}
//end dateType::setDate()

int dateType::getDay() const {
	return dDay;
}
//end dateType::getDay()

int dateType::getMonth() const {
	return dMonth;
}
//end dateType::getMonth()

int dateType::getYear() const {
	return dYear;
}
//end dateType::getYear()

void dateType::printDate() const {
	cout << dMonth << "-" << dDay << "-" << dYear;
}
//end dateType::printDate()

//constructor with parameter
dateType::dateType(int month, int day, int year) {
	dMonth = month;
	dDay = day;
	dYear = year;
}
//end constructor