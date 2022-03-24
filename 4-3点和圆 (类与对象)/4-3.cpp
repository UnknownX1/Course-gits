#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//-----�ඨ��------
class Point
{
private:
	float x, y;
public:
	// д�ඨ�����
	void setPoint(float xx, float yy);
	float getX();
	float getY();
};

//----��ʵ��------
void Point::setPoint(float xx, float yy)
{
	x = xx;
	y = yy;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

//-----�ඨ��------
class Circle
{
private:
	float x, y, r;
public:
	// д�ඨ�����
	void setCenter(float xx, float yy);
	void setRadius(float rr);
	void getArea();
	void getLength();
	int contain(Point& dian0);
};

//----��ʵ��------
void Circle::setCenter(float xx, float yy)
{
	x = xx;
	y = yy;
}

void Circle::setRadius(float rr)
{
	r = rr;
}

void Circle::getArea()
{
	cout << fixed << setprecision(2) << 3.14 * r * r << " ";
}

void Circle::getLength()
{
	cout << fixed << setprecision(2) << 2 * 3.14 * r << endl;
}

int Circle::contain(Point &dian0)
{
	double dis;
	dis = sqrt(pow((dian0.getX() - x), 2) + pow((dian0.getY() - y), 2));
	if (dis > r)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//-----������-----
int main()
{
	//�Զ���һЩ����
	float x, y, r;
	float x1, y1;
	//����һ��Բ�����һ�������
	Circle yuan;
	Point dian;
	//����Բ����͵�����������ֵ��������ʼ��
	cin >> x >> y >> r >> x1 >> y1;
	yuan.setCenter(x, y);
	yuan.setRadius(r);
	dian.setPoint(x1, y1);
	//���Բ�������Բ���ܳ�
	yuan.getArea();
	yuan.getLength();
	//���Բ�Ƿ�����㣬���������yes���������no
	if (yuan.contain(dian))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	return 0;
}