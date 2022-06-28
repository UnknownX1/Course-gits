#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CDate {
	int year, month, day;
public:
	CDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	int dayofyear();
	friend int days(CDate& a, CDate& b);
};
int CDate::dayofyear() {
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int cnt = day;
	for (int i = 1; i < month; i++) {
		cnt += a[i];
	}
	return cnt;
}
bool isLeap(int x) {
	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) {
		return true;
	}
	return false;
}
int days(CDate& a, CDate& b) {
	if (a.year == b.year) {
		return b.dayofyear() - a.dayofyear();
	}
	int cnt = b.dayofyear();
	for (int i = a.year + 1; i < b.year; i++) {
		cnt += isLeap(i) ? 366 : 365;
	}
	cnt += ((isLeap(a.year) ? 366 : 365) - a.dayofyear());
	return cnt;
}

class Pet {
protected:
	string name;//姓名
	float length;//身长
	float weight;//体重
	CDate current;//开始记录时间
public:
	virtual void display(CDate day) = 0;//输出目标日期时宠物的身长和体重
	Pet(string name_, float len, float wei, int y, int m, int d) :current(y, m, d) {
		name = name_;
		length = len;
		weight = wei;
	}

};

class Cat :public Pet {
public:
	void display(CDate day);
	Cat(string name_, float len, float wei, int y, int m, int d) :Pet(name_, len, wei, y, m, d) {
	}
};
void Cat::display(CDate day) {
	int daytime = days(current, day);
	length += 0.1 * daytime;
	weight += 0.2 * daytime;
	cout << name << " after " << daytime << " day: length=" << fixed << setprecision(2) << length << ",weight=" << fixed << setprecision(2) << weight << endl;
}
class Dog :public Pet {
public:
	void display(CDate day);
	Dog(string name_, float len, float wei, int y, int m, int d) :Pet(name_, len, wei, y, m, d) {
	}
};
void Dog::display(CDate day) {
	int daytime = days(current, day);
	length += 0.2 * daytime;
	weight += 0.1 * daytime;
	cout << name << " after " << daytime << " day: length=" << fixed << setprecision(2) << length << ",weight=" << fixed << setprecision(2) << weight << endl;
}

int main() {
	int t;
	cin >> t;
	int y, m, d;
	cin >> y >> m >> d;
	Pet* pt;
	while (t--) {

		int type, y2, m2, d2;
		float length, weight;
		string name;
		cin >> type >> name >> length >> weight >> y2 >> m2 >> d2;
		if (y2 * 10000 + m2 * 100 + d2 < y * 10000 + m * 100 + d) {
			cout << "error\n";
			continue;
		}
		if (type == 1) {
			pt = new Cat(name, length, weight, y, m, d);
			pt->display(CDate(y2, m2, d2));
		}
		else {
			pt = new Dog(name, length, weight, y, m, d);
			pt->display(CDate(y2, m2, d2));
		}

	}
	return 0;
}
