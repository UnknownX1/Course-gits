#include <iostream>
using namespace std;

class Complex
{
private:
	float real, image;
public:
	Complex(float x = 0, float y = 0);
	friend Complex operator+(Complex& a, Complex& b);
	friend Complex operator-(Complex& a, Complex& b);
	friend Complex operator*(Complex& a, Complex& b);
	void show();
};

Complex::Complex(float x, float y) {
	real = x;
	image = y;
}

Complex operator+(Complex& a, Complex& b) {
	return Complex(a.real + b.real, a.image + b.image);
}

Complex operator-(Complex& a, Complex& b) {
	return Complex(a.real - b.real, a.image - b.image);
}

Complex operator*(Complex& a, Complex& b) {
	return Complex(a.real * b.real - a.image * b.image, a.image * b.real + a.real * b.image);
}

void Complex::show() {
	cout << "Real=" << real << " Image=" << image << endl;
}

int main() {
	float i1, r1, i2, r2;
	cin >> r1 >> i1 >> r2 >> i2;
	Complex a(r1, i1);
	Complex b(r2, i2);

	(a + b).show();
	(a - b).show();
	(a * b).show();
	return 0;
}