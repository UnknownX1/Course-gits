#include <iostream>
#include <string>
using namespace std;

class Number {
private:
	int num;
	char type;
public:
	Number(int nu, char ty);
	int GetNum();
	char GetType();
};
Number::Number(int nu, char ty) {
	num = nu;
	type = ty;
}
int Number::GetNum() {
	return num;
}
char Number::GetType() {
	return type;
}

class Phone {
private:
	Number number;
	int state;
	string name;
public:
	Phone(int nu, char ty, int st, string na);
	void Print();
	int check(int num);
	~Phone();
};

Phone::Phone(int nu, char ty, int st, string na) :number(nu, ty) {
	state = st;
	name = na;
	cout << number.GetNum() << " constructed." << endl;
}
Phone::~Phone() {
	cout << number.GetNum() << " destructed." << endl;
}
void Phone::Print() {
	//Phone=80000003--Type=C--State=use--Owner=mary
	cout << "Phone=" << number.GetNum() << "--Type=" << number.GetType() << "--State=";
	if (state == 1) {
		cout << "use--Owner=" << name << endl;
	}
	else {
		cout << "unuse--Owner=" << name << endl;
	}
}
int Phone::check(int num) {
	if (num == number.GetNum()) {
		return 1;
	}
	return 0;
}


int main() {
	int num, state;
	char type;
	string name;
	cin >> num >> type >> state >> name;
	Phone phone1(num, type, state, name);
	cin >> num >> type >> state >> name;
	Phone phone2(num, type, state, name);
	cin >> num >> type >> state >> name;
	Phone phone3(num, type, state, name);

	int t;
	cin >> t;
	while (t--) {
		cin >> num;
		if (phone1.check(num)) {
			phone1.Print();
		}
		else if (phone2.check(num)) {
			phone2.Print();
		}
		else if (phone3.check(num)) {
			phone3.Print();
		}
		else {
			cout << "wrong number.\n";
		}
	}
	return 0;
}