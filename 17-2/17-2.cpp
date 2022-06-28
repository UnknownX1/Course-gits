#include <iostream>

using namespace std;

class Medal {
	int yd, weight, v;
public:
	Medal(int yd_,int weight_,int v_)
	{
		yd = yd_;
		weight = weight_;
		v = v_;
	}
	friend Medal operator+(Medal& m1, Medal& m2);
	friend Medal operator*(Medal& m1, int n);
	Medal & operator++(int);
	Medal operator--();
	void print();
};

Medal operator+(Medal& m1, Medal& m2) {
	return Medal(m1.yd + m2.yd, m1.weight + m2.weight, m1.v + m2.v);
}

Medal operator*(Medal& m1, int n) {
	return Medal(m1.yd, m1.weight, m1.v * n);
}

Medal& Medal::operator++(int) {
	weight *= 1.1;
	v *= 1.1;
	yd++;
	return *this;
}

Medal Medal::operator--() {
	Medal tmp = Medal(yd, weight, v);
	weight *= 0.9;
	v *= 0.9;
	yd--;
	return tmp;
}

void Medal::print() {
	cout << "硬度" << yd << "--重量" << weight << "--体积" << v << endl;
}

int main() {
	int yd, weight, v,n;
	cin >> yd >> weight >> v;
	Medal m1(yd, weight, v);
	cin >> yd >> weight >> v;
	Medal m2(yd, weight, v);
	cin >> n;
	(m1 + m2).print();
	(m1 * n).print();
	m1++;
	m1.print();
	--m2;
	m2.print();
	return 0;
}