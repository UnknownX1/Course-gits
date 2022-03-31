#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setXY(double x1, double y1) { x = x1; y = y1; }
	void setX(double x_value);
	void setY(double y_va1ue);
	double getDisTo(const Point& p);
	~Point();
};

Point::Point() {
	cout << "Constructor." << endl;
}

Point::Point(double x_value, double y_value) {
	x = x_value;
	y = y_value;
	cout << "Constructor." << endl;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

void Point::setX(double x_value) {
	x = x_value;
}

void Point::setY(double y_value) {
	y = y_value;
}

double Point::getDisTo(const Point& p) {
	double dis;
	dis = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
	return dis;
}

Point::~Point() {
	cout << "Distructor." << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Point* p = new Point[n];

		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			p[i].setXY(x, y);
		}

		int index1 = 0, index2 = 0;
		double max = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double temp = p[i].getDisTo(p[j]);
				if (temp > max) {
					max = temp;
					index1 = i;
					index2 = j;
				}
			}
		}

		cout << "The longeset distance is " << fixed << setprecision(2) << max << ",between p[" << index1 << "] and p[" << index2 << "]." << endl;
		delete[]p;
	}
	return 0;
}