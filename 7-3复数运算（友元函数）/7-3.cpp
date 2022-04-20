#include <iostream>
#include <string>
using namespace std;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
public:
	Complex();
	Complex(double r, double i);
	// 友元函数，复数c1 + c2(二参数对象相加)
	friend Complex addCom(const Complex& c1, const Complex& c2);
	friend Complex minusCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c);
};
Complex::Complex() {
	real = 0;
	imag = 0;
}
Complex::Complex(double r, double i) {
	real = r;
	imag = i;
}

// 友元函数
Complex addCom(const Complex& c1, const Complex& c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex minusCom(const Complex& c1, const Complex& c2) {
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
void outCom(const Complex& c) {
	cout << "(" << c.real << "," << c.imag << ")\n";
}

int main() {
	int a, b;
	cin >> a >> b;
	Complex p1(a, b);
	int t;
	cin >> t;
	while (t--) {
		char op;
		int a2, b2;
		cin >> op >> a2 >> b2;
		if (op == '+') {
			p1 = addCom(p1, Complex(a2, b2));
		}
		else {
			p1 = minusCom(p1, Complex(a2, b2));
		}
		outCom(p1);
	}
	return 0;
}

