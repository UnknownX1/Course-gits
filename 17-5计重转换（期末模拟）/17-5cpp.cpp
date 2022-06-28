#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class CN; //提前声明
class EN; //提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; //计重类型
	int gram; // 克
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
	// ....类定义自行编写
private:
	int j, l, q;
public:
	void Convert(int tmp);
	void print(ostream& out);
	CN(int j_, int l_, int q_, int g_, const char tk_[]) :Weight(tk_, g_) {
		j = j_;
		l = l_;
		q = q_;
	}
	CN(const CN& c) :Weight(c.kind, c.gram) {
		j = c.j;
		l = c.l;
		q = c.q;
	}
	friend ostream& operator<<(ostream& oo, Weight& c);

};

void CN::Convert(int tmp) {
	gram = tmp;
	j = gram / 500;
	gram -= 500 * j;
	l = gram / 50;
	gram -= 50 * l;
	q = gram / 5;
	gram -= 5 * q;

}
void CN::print(ostream& out) {
	out << "中国计重:" << j << "斤" << l << "两" << q << "钱" << gram << "克\n";
}
ostream& operator<<(ostream& oo, Weight& c) {
	c.print(oo);
	return oo;
}


// 英国计重
class EN : public Weight
{
	// ....类定义自行编写
	int b, g, d;
public:
	EN(int j_, int l_, int q_, int g_, const char tk_[]) :Weight(tk_, g_) {
		b = j_;
		g = l_;
		d = q_;
	}
	void Convert(int tmp);
	void print(ostream& out);
	friend ostream& operator<<(ostream& oo, Weight& c);
	operator CN();
};
EN::operator CN() {
	int cnt = 0;
	cnt += b * 512;
	cnt += g * 32;
	cnt += d * 2;
	cnt += gram;

	CN cn(0, 0, 0, 0, "英国计重");
	cn.Convert(cnt);
	return cn;
}
void EN::Convert(int tmp) {
	gram = tmp;
	b = gram / 512;
	gram -= 512 * b;
	g = gram / 32;
	gram -= 32 * g;
	d = gram / 2;
	gram -= 2 * d;
}
void EN::print(ostream& out) {
	out << "英国计重:" << b << "磅" << g << "盎司" << d << "打兰" << gram << "克\n";
}

// 以全局函数方式重载输出运算符，代码3-5行....自行编写
// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
// 重载函数必须调用参数Weight对象的print方法

// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cout << cn;

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	cout << en;
	cn = en; // 把英国计重转成中国计重
	cout << cn;
	return 0;
}