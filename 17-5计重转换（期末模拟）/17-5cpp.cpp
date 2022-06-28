#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class CN; //��ǰ����
class EN; //��ǰ����

// ������
class Weight
{
protected:
	char kind[20]; //��������
	int gram; // ��
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // �����ͬ���͵ļ�����Ϣ
};

// �й�����
class CN : public Weight
{
	// ....�ඨ�����б�д
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
	out << "�й�����:" << j << "��" << l << "��" << q << "Ǯ" << gram << "��\n";
}
ostream& operator<<(ostream& oo, Weight& c) {
	c.print(oo);
	return oo;
}


// Ӣ������
class EN : public Weight
{
	// ....�ඨ�����б�д
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

	CN cn(0, 0, 0, 0, "Ӣ������");
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
	out << "Ӣ������:" << b << "��" << g << "��˾" << d << "����" << gram << "��\n";
}

// ��ȫ�ֺ�����ʽ������������������3-5��....���б�д
// ���غ�����������������ostream������Weight����󣬲��������Ƕ�����������
// ���غ���������ò���Weight�����print����

// ������
int main()
{
	int tw;
	// ����һ���й����������cn
	// ���������Ӧ�����Ǯ���ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	CN cn(0, 0, 0, 0, "�й�����");
	cin >> tw;
	cn.Convert(tw); // ������Ŀ���ת���й�����
	cout << cn;

	// ����Ӣ�����������en
	// ���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	EN en(0, 0, 0, 0, "Ӣ������");
	cin >> tw;
	en.Convert(tw); // ������Ŀ���ת��Ӣ������
	cout << en;
	cn = en; // ��Ӣ������ת���й�����
	cout << cn;
	return 0;
}