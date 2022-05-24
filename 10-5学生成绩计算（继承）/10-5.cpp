#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	void display();
	Person(string name_, int age_) {
		name = name_;
		age = age_;
	}
};
void Person::display() {
	cout << name << " " << age << " ";
}

class unfree :public Person {
private:
	int psscore, ksscore;
	double zpsocre;
public:
	void display();
	unfree(string name_, int age_, int ps, int ks);
};
unfree::unfree(string name_, int age_, int ps, int ks) :Person(name_, age_) {
	psscore = ps;
	ksscore = ks;
	zpsocre = psscore * 0.4 + ksscore * 0.6;
}
void unfree::display() {
	Person::display();
	if (zpsocre >= 85) {
		cout << "A" << endl;
	}
	else if (zpsocre >= 75) {
		cout << "B" << endl;
	}
	else if (zpsocre >= 65) {
		cout << "C" << endl;
	}
	else if (zpsocre >= 60) {
		cout << "D" << endl;
	}
	else {
		cout << "F" << endl;
	}
}

class free1 :public Person {
private:
	int ksscore, zpsocre;
public:
	void display();
	free1(string name_, int age_, int ks);
};
free1::free1(string name_, int age_, int ks) :Person(name_, age_) {
	ksscore = ks;
	zpsocre = ksscore;
}
void free1::display() {
	Person::display();
	if (zpsocre >= 85) {
		cout << "A" << endl;
	}
	else if (zpsocre >= 75) {
		cout << "B" << endl;
	}
	else if (zpsocre >= 65) {
		cout << "C" << endl;
	}
	else if (zpsocre >= 60) {
		cout << "D" << endl;
	}
	else {
		cout << "F" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char op;
		cin >> op;
		if (op == 'R') {
			int age, ps, ks;
			string name;
			cin >> name >> age >> ps >> ks;
			unfree p(name, age, ps, ks);
			p.display();
		}
		else {
			int  age, ks;
			string name;
			cin >> name >> age >> ks;
			free1 p(name, age, ks);
			p.display();
		}
	}
	return 0;
}