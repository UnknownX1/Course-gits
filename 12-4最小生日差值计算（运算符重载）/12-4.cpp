#include <iostream>
#include <cstring>
using namespace std;

bool isLeapYear(int y);
class Student
{
public:
	Student(string name_ = "", int y_ = 0, int m_ = 0, int d_ = 0);
	friend int operator-(Student& a, Student& b);
	friend int mindays(Student& a, Student& b);
	int getDayofYear();
	string getName() {
		return name;
	}
private:
	string name;
	int y, m, d;
};

Student::Student(string name_, int y_, int m_, int d_) {
	name = name_;
	y = y_;
	m = m_;
	d = d_;
}

int operator-(Student& a, Student& b) {
	int daya = a.y * 10000 + a.m * 100 + a.d;
	int dayb = b.y * 10000 + b.m * 100 + b.d;
	if (daya < dayb) {
		int days = 0;
		for (int i = a.y; i < b.y; i++) {
			if (isLeapYear(i)) {
				days += 366;
			}
			else {
				days += 365;
			}
		}
		days -= a.getDayofYear();
		days += b.getDayofYear();
		return days;
	}
	else {
		int days = 0;
		for (int i = b.y; i < a.y; i++) {
			if (isLeapYear(i)) {
				days += 366;
			}
			else {
				days += 365;
			}
		}
		days -= b.getDayofYear();
		days += a.getDayofYear();
		return days;
	}
}

int Student::getDayofYear() {
	int i, sum = d;
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(y)) {
		a[2]++;
	}
	// 求日期的天数
	for (i = 0; i < m; i++) {
		sum += a[i];
	}
	return sum;
}


int mindays(Student& a, Student& b) {
	int days = 0;
	for (int i = a.y; i < b.y; i++) {
		if (isLeapYear(i)) {
			days += 366;
		}
		else {
			days += 365;
		}
	}
	days -= a.getDayofYear();
	days += b.getDayofYear();
	return days;
}


bool isLeapYear(int y) {
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main() {
	int t;
	cin >> t;
	Student* s = new Student[t];
	for (int i = 0; i < t; i++) {
		string name;
		int y, m, d;
		cin >> name >> y >> m >> d;
		s[i] = Student(name, y, m, d);
	}
	int mini = 0, minj = 0, min = 0x3f3f3f3f;
	for (int i = 0; i < t - 1; i++) {
		for (int j = i + 1; j < t; j++) {
			int tmp = s[i] - s[j];
			if (tmp < min) {
				min = tmp;
				mini = i;
				minj = j;
			}
		}
	}

	cout << s[mini].getName() << "和" << s[minj].getName() << "年龄相差最小，为" << s[mini]-s[minj] << "天。";
	delete[]s;
	return 0;
}