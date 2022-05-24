#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class CCount {
protected:
	int value;
public:
	void increment();
	CCount(int x);
};
void CCount::increment() {
	value ++;
}
CCount::CCount(int x) {
	value = x;
}

class CCaculate :public CCount{
protected:
	int minValue;
	int maxValue;
public:
	int increment();
	CCaculate(int x, int min, int max);
	int GetValue();
};
int CCaculate::increment() {
	CCount::increment();
	if (value > maxValue) {
		value = minValue;
		return 1;
	}
	return 0;
}
CCaculate::CCaculate(int x ,int min ,int max):CCount(x) {
	minValue = min;
	maxValue = max;
}
int CCaculate::GetValue() {
	return value;
}

class Clock {
private:
	CCaculate hour;
	CCaculate minute;
	CCaculate second;
public:
	void time_(int s);
	Clock(int h, int m, int s);
	void print();
};
void Clock::time_(int s) {
	while (s--) {
		if (second.increment()) {
			if (minute.increment()) {
				hour.increment();
			}
		}
	}
}
void Clock::print() {
	cout << hour.GetValue() << ":" << minute.GetValue() << ":" << second.GetValue() << endl;
}
Clock::Clock(int h, int m, int s) :hour(h, 0, 23), minute(m, 0, 59), second(s, 0, 59) {

}

int main() {
	int n;
	cin >> n;
	while (n--)
	{
		int h, m, s, ss;
		cin >> h >> m >> s >> ss;
		Clock cl(h, m, s);
		cl.time_(ss);
		cl.print();
	}
	return 0;
}