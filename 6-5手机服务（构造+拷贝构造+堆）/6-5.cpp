#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class CDate {
private:
	int year, month, day;
public:
	CDate(int y, int m, int d);
	void Print();
	int getYear();
	int getMonth();
	int getDay();
};

int CDate::getYear() {
	return year;
}
int CDate::getMonth() {
	return month;
}
int CDate::getDay() {
	return day;
}


CDate::CDate(int y, int m, int d) {
	year = y, month = m, day = d;
}

void CDate::Print() {

}

class Number {
private:
	char type;
	string num;
	int state;
	CDate *date;
public:
	Number(char t, string n, int s);
	Number(const Number& p);
	void Stop(int yy, int mm, int dd);
	void Print();
	void SetState(int s);
	string GetNum();
	void SetNum(string &n);
};

Number::Number(char t, string n, int s) :date(NULL) {
	type = t;
	num = n;
	state = s;
	cout << "Construct a new phone " << num << endl;
}
Number::Number(const Number& p) :date(NULL) {
	type = 'D';
	num = p.num;
	state = p.state;
	cout << "Construct a copy of phone " << p.num << endl;
}
void Number::Stop(int yy, int mm, int dd) {
	date = new CDate(yy, mm, dd);
	cout << "Stop the phone " << num << endl;
	state = 3;
}
void Number::SetState(int s) {
	state = s;
}
string Number::GetNum() {
	return num;
}
void Number::SetNum(string& n) {
	num = n;
}
void Number::Print() {
	cout << "类型=";
	switch (type) {
	case 'A':
		cout << "机构";
		break;
	case 'B':
		cout << "企业";
		break;
	case 'C':
		cout << "个人";
		break;
	case 'D':
		cout << "备份";
		break;
	}
	cout << "||号码=" << num << "||State=";
	switch (state) {
	case 1:
		cout << "在用" << endl;
		break;
	case 2:
		cout << "未用" << endl;
		break;
	case 3:
		cout << "停用 ||停机日期=" << date->getYear() << "." << date->getMonth() << "." << date->getDay() << endl;
		break;
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		char type;
		string num;
		int state, yy, mm, dd;
		cin >> type >> num >> state >> yy >> mm >> dd;
		Number num1(type, num, state);
		num1.Print();

		Number numbackup(num1);
		string tmp = numbackup.GetNum() + "X";
		numbackup.SetNum(tmp);
		numbackup.Print();

		num1.Stop(yy,mm,dd);
		num1.Print();
		cout << "----\n";
	}
	return 0;
}

