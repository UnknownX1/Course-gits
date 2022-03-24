#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//-----类定义------
class Point
{
private:
	float x, y;
public:
	// 写类定义代码
	void setPoint(float xx, float yy);
	float getX();
	float getY();
};

//----类实现------
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

//-----类定义------
class Circle
{
private:
	float x, y, r;
public:
	// 写类定义代码
	void setCenter(float xx, float yy);
	void setRadius(float rr);
	void getArea();
	void getLength();
	int contain(Point& dian0);
};

//----类实现------
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

//-----主函数-----
int main()
{
	//自定义一些变量
	float x, y, r;
	float x1, y1;
	//创建一个圆对象和一个点对象
	Circle yuan;
	Point dian;
	//输入圆对象和点对象的属性数值，并做初始化
	cin >> x >> y >> r >> x1 >> y1;
	yuan.setCenter(x, y);
	yuan.setRadius(r);
	dian.setPoint(x1, y1);
	//输出圆的面积和圆的周长
	yuan.getArea();
	yuan.getLength();
	//输出圆是否包含点，包含则输出yes，否则输出no
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