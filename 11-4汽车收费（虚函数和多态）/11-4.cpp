#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
	string no; //编号
public:
	virtual void display() = 0; //应收费用
	Vehicle(string no_);
};
Vehicle::Vehicle(string no_) {
	no = no_;
}

class Car :public Vehicle {
private:
	int pass, weight;
public:
	void display();
	Car(int pass_, int weight_, string no_);
};
void Car::display() {
	cout << no << " " << pass * 8 + weight * 2 << endl;
}
Car::Car(int pass_, int weight_, string no_) :Vehicle(no_) {
	pass = pass_;
	weight = weight_;
}


class Truck :public Vehicle {
private:
	int weight;
public:
	void display();
	Truck(int weight_, string no_);
};
void Truck::display() {
	cout << no << " " << weight * 5 << endl;
}
Truck::Truck(int weight_, string no_) :Vehicle(no_) {
	weight = weight_;
}

class Bus :public Vehicle {
private:
	int weight;
public:
	void display();
	Bus(int weight_, string no_);
};
void Bus::display() {
	cout << no << " " << weight * 30 << endl;
}
Bus::Bus(int weight_, string no_) :Vehicle(no_) {
	weight = weight_;
}

int main() {
	int t;
	cin >> t;
	Vehicle* pv=NULL;
	while (t--) {
		int type, a, b;
		string no;
		cin >> type >> no >> a;
		switch (type)
		{
		case 1:
			cin >> b;
			pv = new Car(a, b, no);
			pv->display();
			break;
		case 2:
			pv = new Truck(a, no);
			pv->display();
			break;
		case 3:
			pv = new Bus(a, no);
			pv->display();
			break;
		}
	}
	return 0;
}