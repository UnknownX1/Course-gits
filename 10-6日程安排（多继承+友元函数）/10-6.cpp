#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Date {
protected:
	int year, month, day;
};

class Time {
protected:
	int hour, minute, second;
};

class Schedule : public Date, public Time {
protected:
	int ID;
public:
	friend bool before(const Schedule& s1, const Schedule& s2);
	Schedule(int n, int yy, int mm, int dd, int h, int m, int s);
	void print();
};
Schedule::Schedule(int n,int yy, int mm, int dd, int h, int m, int s) {
	ID = n;
	year = yy;
	month = mm;
	day = dd;
	hour = h;
	minute = m;
	second = s;
}
void Schedule::print() {
	//The urgent schedule is No.1: 2019/06/27 08:00:01
	printf("The urgent schedule is No.%d: %04d/%02d/%02d %02d:%02d:%02d", ID, year, month, day, hour, minute, second);
}

bool before(const Schedule& s1, const Schedule& s2) {
	int date1 = s1.year * 10000 + s1.month + s1.day;
	int date2 = s2.year * 10000 + s2.month + s2.day;
	if (date1 < date2) {
		return true;
	}
	else if (date1 > date2) {
		return false;
	}
	else {
		int time1 = s1.hour * 10000 + s1.minute + s1.second;
		int time2 = s2.hour * 10000 + s2.minute + s2.second;
		if (time1 < time2) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	Schedule min(9999,9999,99,99,99,99,99);
	while (n != 0) {
		int yy, mm, dd, h, m, s;
		cin >> yy >> mm >> dd >> h >> m >> s;
		Schedule sche(n, yy, mm, dd, h, m, s);
		if (before(sche, min)) {
			min = sche;
		}
		cin >> n;
	} 
	min.print();
	return 0;
}