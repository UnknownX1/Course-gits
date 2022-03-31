#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void add0neDay();
};

Date::Date() {
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

void Date::setDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

void Date::add0neDay() {
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		arr[2] = 29;
	}
	day += 1;
	if (day > arr[month]) {
		day = 1;
		month += 1;
	}
	if (month > 12) {
		month = 1;
		year += 1;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int y, m, d;
		cin >> y >> m >> d;
		Date date(y, m, d);
		cout << "Today is " << date.getYear() << "/" << setfill('0') << setw(2) << date.getMonth() << "/" << setfill('0') << setw(2) << date.getDay() << endl;
		date.add0neDay();
		cout << "Tomorrow is " << date.getYear() << "/" << setfill('0') << setw(2) << date.getMonth() << "/" << setfill('0') << setw(2) << date.getDay() << endl;
		if (t == 0) {
			break;
		}
		t--;
		cin >> y >> m >> d;
		date.setDate(y, m, d);
		cout << "Today is " << date.getYear() << "/" << setfill('0') << setw(2) << date.getMonth() << "/" << setfill('0') << setw(2) << date.getDay() << endl;
		date.add0neDay();
		cout << "Tomorrow is " << date.getYear() << "/" << setfill('0') << setw(2) << date.getMonth() << "/" << setfill('0') << setw(2) << date.getDay() << endl;
	}
	return 0;
}