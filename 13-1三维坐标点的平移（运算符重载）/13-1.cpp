#include <iostream>
using namespace std;

class point {
	int x;
	int y;
	int z;
public:
	point(int X = 0, int Y = 0, int Z = 0) { x = X; y = Y; z = Z; }
	friend point operator ++(point& a);
	friend point operator ++(point& a, int);
	friend point operator --(point& a);
	friend point operator --(point& a, int);
	void show();
};
point operator ++(point& a, int) {
	point tmp(a.x, a.y, a.z);
	a.x++;
	a.y++;
	a.z++;
	return tmp;
}
point operator ++(point& a) {
	a.x++;
	a.y++;
	a.z++;
	return a;
}
point operator --(point& a, int) {
	point tmp(a.x, a.y, a.z);
	a.x--;
	a.y--;
	a.z--;
	return tmp;
}
point operator --(point& a) {
	a.x--;
	a.y--;
	a.z--;
	return a;
}
void point::show() {
	cout << "x=" << x << " y=" << y << " z=" << z << endl;
}

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	point p1(x, y, z), p2;
	p2 = p1++;
	p1.show();
	p2.show();

	p1 = point(x, y, z);
	p2 = ++p1;
	p1.show();
	p2.show();

	p1 = point(x, y, z);
	p2 = p1--;
	p1.show();
	p2.show();

	p1 = point(x, y, z);
	p2 = --p1;
	p1.show();
	p2.show();

	return 0;
}