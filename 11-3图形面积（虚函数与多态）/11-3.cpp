#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
	virtual double area()=0;
};

class Circle :public Shape {
private:
	float r;
public:
	Circle(float r_);
	double area();
};
Circle::Circle(float r_) {
	r = r_;
}
double Circle::area() {
	return 3.14 * r * r;
}

class Square :public Shape {
private:
	float r;
public:
	Square(float r_);
	double area();
};
Square::Square(float r_) {
	r = r_;
}
double Square::area() {
	return r * r;
}

class Rectangle :public Shape {
private:
	float a,b;
public:
	Rectangle(float a_,float b_);
	double area();
};
Rectangle::Rectangle(float a_, float b_) {
	a = a_;
	b = b_;
}
double Rectangle::area() {
	return a*b;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		Shape **s = new Shape*[3];
		float r, a, b, c;
		cin >> r >> a >> b >> c;
		s[0] = new Circle(r);
		s[1] = new Square(a);
		s[2] = new Rectangle(b,c);

		for (int i = 0; i < 3; i++) {
			cout <<fixed << setprecision(2) << s[i]->area() << endl;
		}
	}
	return 0;
}