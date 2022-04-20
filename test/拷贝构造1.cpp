#include <iostream>
using namespace std;

class Point {   //Point ��Ķ���
public:
	Point(int xx = 0, int yy = 0)
	{
		x = xx; y = yy;
	} //���캯��������
	Point(const Point& p); //�������캯��
	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy; }
	int getX() { return x; } //����
	int getY() { return y; } //����
private:
	int x, y; //˽������
};
//��Ա������ʵ��
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor " << endl;
}
//�β�ΪPoint�����ĺ���
void fun1(Point p) {//ֵ���ݣ����������캯�������ô��ݲ�����
	cout << p.getX() << endl;
}
//����ֵΪPoint�����ĺ���
Point fun2() {
	Point a(1, 2);
	return a;
}
int main04() {
	Point a(4, 5);	//һ������a
	Point b = a;	//��A��ʼ��B�� ��ЧPoint b(a)
	cout << b.getX() << endl;
	fun1(b);	//����B��Ϊfun1��ʵ�Ρ�
	b = fun2();/*�����ķ���ֵ������󣬷���ʱ���ÿ������캯��*/
	cout << b.getX() << endl;
	return 0;
}


