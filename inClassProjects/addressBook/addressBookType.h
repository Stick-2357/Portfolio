#ifndef H_addressBookType
#define H_addressBookType

#include <string>
#include <fstream>
#include "extPersonType.h"

using namespace std;

class addressBookType {
	public:
		void print() const;

		void printNameInTheMonth(int month);
		void printInfoOf(string lName);
		void printNamesWithStatus(string status);
		void printAt(int i);

		void printNamesBetweenLastNames(string last1, string last2);

		void insertAt(const extPersonType& eP, int i);

		void insertLast(const extPersonType& eP);

		int search(string lName);

		void sort();

		void saveData(ofstream&);

		addressBookType();
		//constructor
	private:
		extPersonType list[500];

		int length;
};
#endif