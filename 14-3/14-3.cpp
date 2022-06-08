#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

class CPoint {
	int x, y;
public:
	CPoint(int xx, int yy) {
		x = xx;
		y = yy;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	friend bool operator > (CPoint& p1, CPoint& p2);
};

class CRectangle {
	CPoint leftPoint;
	CPoint rightPoint;
public:
	CRectangle(int x1, int y1, int x2, int y2) :leftPoint(x1, y1), rightPoint(x2, y2) {}
	friend bool operator > (CRectangle& p1, CRectangle& p2);
	friend bool operator == (CRectangle& p1, CRectangle& p2);
	friend bool operator * (CRectangle& p1, CRectangle& p2);
	operator int();
	friend ostream& operator << (ostream& oo, CRectangle& p);
};

//p1��p2���Ͻ�
bool operator > (CPoint& p1, CPoint& p2) {
	if (p1.x<= p2.x && p1.y>=p2.y) {
		return true;
	}
	return false;
}

bool operator > (CRectangle& p1, CRectangle& p2) {
	if (p1.leftPoint > p2.leftPoint && p2.rightPoint > p1.rightPoint) {
		return true;
	}
	return false;
}

bool operator == (CRectangle& p1, CRectangle& p2) {
	if (p1.leftPoint.getX() == p2.leftPoint.getX() && p1.leftPoint.getY() == p2.leftPoint.getY() && p1.rightPoint.getX() == p2.rightPoint.getX() && p1.rightPoint.getY() == p2.rightPoint.getY()) {
		return true;
	}
	return false;
}
bool operator * (CRectangle& p1, CRectangle& p2) {
	if (p2.leftPoint > p1.leftPoint && p1.leftPoint > p2.rightPoint) {
		return true;
	}
	if (p2.leftPoint > p1.rightPoint && p1.rightPoint > p2.rightPoint) {
		return true;
	}

	if (p1.leftPoint > p2.leftPoint && p2.leftPoint > p1.rightPoint) {
		return true;
	}
	if (p1.leftPoint > p2.rightPoint && p2.rightPoint > p1.rightPoint) {
		return true;
	}

	if (p1.leftPoint > p2.rightPoint && p2.leftPoint > p1.rightPoint) {
		return true;
	}
	if (p2.leftPoint > p1.rightPoint && p1.leftPoint > p2.rightPoint) {
		return true;
	}
	return false;
}

CRectangle::operator int() {
	return abs(rightPoint.getX() - leftPoint.getX()) * abs(leftPoint.getY() - rightPoint.getY());
}

ostream& operator << (ostream& oo, CRectangle& p) {
	return oo << p.leftPoint.getX() << " " << p.leftPoint.getY() << " " << p.rightPoint.getX() << " " << p.rightPoint.getY();
}

int main()
{
	int t, x1, x2, y1, y2;
	cin >> t;
	while (t--)
	{
		// ����1�����Ͻǡ����½�
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect1(x1, y1, x2, y2);
		// ����2�����Ͻǡ����½�
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect2(x1, y1, x2, y2);
		// �������1�����꼰���
		cout << "����1:" << rect1 << " " << (int)rect1 << endl;
		// �������2�����꼰���
		cout << "����2:" << rect2 << " " << (int)rect2 << endl;
		if (rect1 == rect2)
		{
			cout << "����1�;���2���" << endl;
		}
		else if (rect2 > rect1)
		{
			cout << "����2��������1" << endl;
		}
		else if (rect1 > rect2)
		{
			cout << "����1��������2" << endl;
		}
		else if (rect1 * rect2)
		{
			cout << "����1�;���2�ཻ" << endl;
		}
		else
		{
			cout << "����1�;���2���ཻ" << endl;
		}
		cout << endl;
	}
	return 0;
}