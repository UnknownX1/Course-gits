#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point();
	Point(double xx, double yy);
	double getX();
	double getY();
	void setX(double x_vaule);
	void setY(double y_vaule);
	double distanceToAnotherPoint(Point p);
};

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xx, double yy) {
	x = xx;
	y = yy;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

void Point::setX(double x_vaule) {
	x = x_vaule;
}

void Point::setY(double y_vaule) {
	y = y_vaule;
}

double Point::distanceToAnotherPoint(Point p) {
	return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1), p2(x2, y2);
		cout << fixed << setprecision(2) << "Distance of Point(" << p1.getX() << "," << p1.getY();
		cout << fixed << setprecision(2) << ") to Point(" << p2.getX() << "," << p2.getY();
		cout << fixed << setprecision(2) << ") is " << p1.distanceToAnotherPoint(p2) << endl;
	}
	return 0;
}