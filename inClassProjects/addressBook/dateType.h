#ifndef H_dateType
#define H_dateType

class dateType {
	public:
		void setDate(int month, int day, int year);
		
		int getDay() const;
		int getMonth() const;
		int getYear() const;

		void printDate() const;

		dateType(int month = 1, int day = 1, int year = 1900);
		//constructor
	private:
		int dMonth;
		int dDay;
		int dYear;
};
#endif