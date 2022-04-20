#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	double x, y;
public:
	Point(double xx, double yy); // ¹¹Ôìº¯Êý
	friend double Distance(Point& a, Point& b);
};
Point::Point(double xx, double yy) {
	x = xx;
	y = yy;
}
double Distance(Point& a, Point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1);
		Point p2(x2, y2);
		int res = Distance(p1, p2);
		cout << res << endl;
	}
	return 0;
}