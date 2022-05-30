#include <iostream>
using namespace std;

class Clock {
	int hour, minute, second;
public:
	Clock(int hour_, int minute_, int second_) {
		hour = hour_;
		minute = minute_;
		second = second_;
	}
	friend Clock operator ++(Clock& a);
	friend Clock operator --(Clock& a, int);
	void show() {
		cout << hour << ":" << minute << ":" << second << endl;
	}
};
Clock operator ++(Clock& a) {
	a.second++;
	if (a.second > 59) {
		a.second -= 60;
		a.minute++;
	}
	if (a.minute > 59) {
		a.minute -= 60;
		a.hour++;
	}
	if (a.hour > 11) {
		a.hour -= 12;
	}
	return a;
}
Clock operator --(Clock& a, int) {
	Clock tmp(a.hour, a.minute, a.second);
	a.second--;
	if (a.second < 0) {
		a.second += 60;
		a.minute--;
	}
	if (a.minute < 0) {
		a.minute += 60;
		a.hour--;
	}
	if (a.hour < 0) {
		a.hour += 12;
	}
	return tmp;
}


int main() {
	int h, m, s;
	cin >> h >> m >> s;
	Clock c(h, m, s);
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x > 0) {
			while (x--) {
				++c;
			}
		}
		else {
			x = -x;
			while (x--) {
				c--;
			}
		}
		c.show();

	}

	return 0;
}