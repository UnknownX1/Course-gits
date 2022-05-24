#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.14;
class CPoint {
protected:
	int x;
	int y;
public:
	CPoint(int xx, int yy);
};
CPoint::CPoint(int xx, int yy) {
	x = xx;
	y = yy; 
}

class CCircle : public CPoint {
protected:
	int r;
public:
	CCircle(int xx, int yy, int rr);
	float GetS();
	void Print();
};
CCircle::CCircle(int xx, int yy, int rr):CPoint(xx, yy){
	r = rr;
}
float CCircle::GetS() {
	return PI * r * r;
}
void CCircle::Print() {
	cout << "Circle:(" << x << "," << y << ")," << r << endl;
	cout << "Area:" <<fixed << setprecision(2) << GetS() << endl;
}

class CCylinder : public CCircle {
protected:
	int h;
public:
	float GetV();
	CCylinder(int xx, int yy, int rr, int hh);
	void Print();
};
CCylinder::CCylinder(int xx, int yy, int rr, int hh) :CCircle(xx,yy,rr) {
	h = hh;
}
float CCylinder::GetV() {
	return GetS() * h;
}
void CCylinder::Print() {
	cout << "Cylinder:(" << x << "," << y << ")," << r << "," << h << endl;
	cout << "Volume:" <<fixed << setprecision(2)<< GetV() << endl;

}

int main() {
	int x, y, r, h;
	cin >> x >> y >> r;
	CCircle circle(x, y, r);
	circle.Print();

	cin >> x >> y >> r >> h;
	CCylinder cylinder(x, y, r, h);
	cylinder.Print();
	return 0;
}