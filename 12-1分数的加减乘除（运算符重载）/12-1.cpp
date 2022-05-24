#include <iostream>
using namespace std;

// 定义Fraction类
class Fraction
{
private:
	int fz, fm;
	int commonDivisor() {}; // 计算最大公约数
	void contracted() {}; // 分数化简
public:
	Fraction(int fz_ = 0, int fm_ = 1);
	Fraction(const Fraction& a);
	friend Fraction operator+(Fraction& a, Fraction& b);
	friend Fraction operator-(Fraction& a, Fraction& b);
	friend Fraction operator*(Fraction& a, Fraction& b);
	friend Fraction operator/(Fraction& a, Fraction& b);
	void set(int = 0, int = 1) {};
	void display();
};

Fraction::Fraction(int fz_, int fm_) {
	fz = fz_;
	fm = fm_;
}

Fraction::Fraction(const Fraction& a) {
	fz = a.fz;
	fm = a.fm;
}

Fraction operator+(Fraction& a, Fraction& b) {
	return Fraction(a.fz * b.fm + b.fz * a.fm, a.fm * b.fm);
}

Fraction operator-(Fraction& a, Fraction& b) {
	return Fraction(a.fz * b.fm - b.fz * a.fm, a.fm * b.fm);
}

Fraction operator*(Fraction& a, Fraction& b) {
	return Fraction(a.fz * b.fz, a.fm * b.fm);
}

Fraction operator/(Fraction& a, Fraction& b) {
	return Fraction(a.fz * b.fm, a.fm * b.fz);
}
void Fraction::display() {
	cout << "fraction=" << fz << "/" << fm << endl;
}

int main() {
	int fz1, fm1, fz2, fm2;
	cin >> fz1 >> fm1 >> fz2 >> fm2;
	Fraction a(fz1, fm1);
	Fraction b(fz2, fm2);
	Fraction tmp = a + b;
	tmp.display();
	tmp = a - b;
	tmp.display();
	tmp = a * b;
	tmp.display();
	tmp = a / b;
	tmp.display();
	return 0;
}