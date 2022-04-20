#include <iostream>
using namespace std;

class Point {   //Point 类的定义
public:
	Point(int xx = 0, int yy = 0)
	{
		x = xx; y = yy;
	} //构造函数，内联
	Point(const Point& p); //拷贝构造函数
	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy; }
	int getX() { return x; } //函数
	int getY() { return y; } //函数
private:
	int x, y; //私有数据
};
//成员函数的实现
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor " << endl;
}
//形参为Point类对象的函数
void fun1(Point p) {//值传递，调拷贝构造函数，引用传递不调用
	cout << p.getX() << endl;
}
//返回值为Point类对象的函数
Point fun2() {
	Point a(1, 2);
	return a;
}
int main04() {
	Point a(4, 5);	//一个对象a
	Point b = a;	//用A初始化B。 等效Point b(a)
	cout << b.getX() << endl;
	fun1(b);	//对象B作为fun1的实参。
	b = fun2();/*函数的返回值是类对象，返回时调用拷贝构造函数*/
	cout << b.getX() << endl;
	return 0;
}


