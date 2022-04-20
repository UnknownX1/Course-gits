#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> 
#include <cmath> 
using namespace std;

class Equation {
private:
	double a;
	double b;
	double c;
public:
	Equation(double aa = 1, double bb = 1, double cc = 0);
	void setA(double x);
	void setB(double x);
	void setC(double x);
	void getRoot();
};

Equation::Equation(double aa, double bb, double cc) {
	a = aa;
	b = bb;
	c = cc;
}

void Equation::setA(double x) {
	a = x;
}

void Equation::setB(double x) {
	b = x;
}

void Equation::setC(double x) {
	c = x;
}

void Equation::getRoot() {
	double dt;
	dt = b * b - 4 * a * c;
	if (a == 0) {
		double x1 = -c / b;
		cout << "x1=" << x1 << endl;
	}
	else if (b == 0) {
		double x1 = -c / a;
		if (x1 > 0) {
			double x = sqrt(x1);
			cout << fixed << setprecision(2) << "x1=" << x << " x2=" << -x << endl;
		}
		else {
			double x = sqrt(-x1);
			cout << fixed << setprecision(2) << "x1=" << x << "i x2=" << -x << "i" << endl;
		}
	}
	else if (dt > 0) {
		dt = sqrt(dt);
		double x1 = (-b + dt) / (2 * a);
		double x2 = (-b - dt) / (2 * a);
		cout << fixed << setprecision(2) << "x1=" << x1 << " x2=" << x2 << endl;
	}
	else if (dt == 0) {
		double x = (-b) / (2 * a);
		cout << fixed << setprecision(2) << "x1=x2=" << x << endl;
	}
	else {
		dt = sqrt(-dt);
		double x1 = (-b) / (2 * a);
		double x2 = (dt) / (2 * a);
		if (x1 <= 0 && x1 > -0.000001) {
			x1 = 0;
		}
		cout << fixed << setprecision(2) << "x1=" << x1 << "+" << x2 << "i x2=" << x1 << "-" << x2 << "i" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double a, b, c;
		cin >> a >> b >> c;
		Equation equ(a, b, c);
		equ.getRoot();
	}
	return 0;
}