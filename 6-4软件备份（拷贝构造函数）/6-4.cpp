#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class CDate {
private:
	int year, month, day;
public:
	CDate(int y, int m, int d);
	bool isLeapYear();
	int getYear();
	int getMonth();
	int getDay();
	int getDayofYear();
};

CDate::CDate(int y, int m, int d) {
	year = y, month = m, day = d;
}

bool CDate::isLeapYear() {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int CDate::getYear() {
	return year;
}

int CDate::getMonth() {
	return month;
}

int CDate::getDay() {
	return day;
}

int CDate::getDayofYear() {
	int i, sum = day;
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		a[2]++;
	}
	// 求日期的天数
	for (i = 0; i < month; i++) {
		sum += a[i];
	}
	return sum;
}

class Software {
private:
	string name;
	string type;
	string media;
	CDate date;
public:
	Software(string _name, char a, char b, int yy, int mm, int dd);
	Software(const Software& p);
	void Print();
};

Software::Software(string _name, char a, char b, int yy, int mm, int dd) :date(yy, mm, dd) {
	name = _name;
	switch (a)
	{
	case 'O':
		type = "original";
		break;
	case 'T':
		type = "trial"; 
		break;
	case 'B':
		type = "backup";
		break;
	}
	switch (b)
	{
	case 'D':
		media = "optical disk";
		break;
	case 'H':
		media = "hard disk";
		break;
	case 'U':
		media = "USB disk";
		break;
	}
}

Software::Software(const Software& p):date(p.date) {
	name = p.name;
	type = "backup";
	media = "hard disk";
}

void Software::Print() {
	cout << "name:" << name << endl;
	cout << "type:" << type << endl;
	cout << "media:" << media << endl;
	if (date.getDay() == 0 && date.getMonth() == 0 && date.getYear() == 0) {
		cout << "this software has unlimited use" << endl;
	}
	else if (date.getYear() < 2015 || date.getYear() == 2015 && date.getMonth() < 4 || date.getYear() == 2015 && date.getMonth() == 4 && date.getDay() < 7) {
		cout << "this software has expired" << endl;
	}
	else if(date.getYear() == 2015) {
		int cnt = date.getDayofYear() - 97;
		cout << "this software is going to be expired in " << cnt << " days" << endl;
	}
	else {
		int cnt = 268;
		for (int i = 2016; i < date.getYear(); i++) {
			if (date.isLeapYear()) {
				cnt += 366;
			}
			else {
				cnt += 365;
			}
		}
		cnt += date.getDayofYear();
		cout << "this software is going to be expired in " << cnt << " days" << endl;
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string name;
		char a, b;
		int yy, mm, dd;
		cin >> name >> a >> b >> yy >> mm >> dd;
		Software soft(name, a, b, yy, mm, dd);
		Software softbackup(soft);
		soft.Print();
		softbackup.Print();
	}
}