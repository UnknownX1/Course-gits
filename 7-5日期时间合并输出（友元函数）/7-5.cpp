#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

class Time;
class Date {
private:
	int yyyy, mm, dd;
public:
	Date(int y, int m, int d) {
		yyyy = y;
		mm = m;
		dd = d;
	}
	friend void display(const Date& d, const Time& t);
};

class Time {
private:
	int hh, mm, ss;
public:
	Time(int h, int m, int s) {
		hh = h;
		mm = m;
		ss = s;
	}
	friend void display(const Date& d, const Time& t);
};

void display(const Date& d, const Time& t) {
	//2017-03-03 19:05:18
	cout << setw(4) << setfill('0') << d.yyyy << "-" << setw(2) << setfill('0') << d.mm << "-" << setw(2) << setfill('0') << d.dd << " " << setw(2) << setfill('0') << t.hh << ":" << setw(2) << setfill('0') << t.mm << ":" << setw(2) << setfill('0') << t.ss << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int y, m, d, h, mi, s;
		cin >> y >> m >> d >> h >> mi >> s;
		Date date(y, m, d);
		Time time(h, mi, s);
		display(date, time);
	}
	return 0;
}