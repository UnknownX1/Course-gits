#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class C2D {
protected:
	int x,y;
public:
	C2D(int xx, int yy);
	float getDistance();
};
float C2D::getDistance() {
	return sqrt(x * x + y * y);
}
C2D::C2D(int xx,int yy) {
	x = xx;
	y = yy;
}

class C3D :public C2D {
protected:
	int z;
public:
	float getDistance();
	C3D(int xx, int yy, int zz);
};
float C3D::getDistance() {
	return sqrt(x * x + y * y+z*z);
}
C3D::C3D(int xx, int yy, int zz):C2D(xx,yy) {
	z = zz;
}

int main() {
	int x, y, z;
	cin >> x >> y ;
	C2D p1(x, y);
	cout << p1.getDistance() << endl;
	cin >> x >> y >> z;
	C3D p2(x, y,z);
	cout << p2.getDistance() << endl;
	cin >> x >> y >> z;
	C3D p3(x, y, z);
	cout << p3.getDistance() << endl;
	cout << p3.C2D::getDistance() << endl;
	return 0;

}