#include <iostream>
#include <cstring>
using namespace std;

class Vector
{
private:
	int vec[5];
public:
	Vector(int v[]);
	Vector();
	Vector(const Vector& obj);
	Vector operator +(const Vector& obj);
	Vector operator -(const Vector& obj);
	void print();
};
Vector::Vector() {
	for (int i = 0; i < 5; i++) {
		vec[i] = 0;
	}
}
Vector::Vector(int v[]) {
	for (int i = 0; i < 5; i++) {
		vec[i] = v[i];
	}
}
Vector::Vector(const Vector& obj) {
	for (int i = 0; i < 5; i++) {
		vec[i] = obj.vec[i];
	}
}
Vector Vector::operator +(const Vector& obj) {
	int tmp[5]{};
	for (int i = 0; i < 5; i++) {
		tmp[i] = vec[i] + obj.vec[i];
	}
	return Vector(tmp);
}
Vector Vector::operator -(const Vector& obj) {
	int tmp[5]{};
	for (int i = 0; i < 5; i++) {
		tmp[i] = vec[i] - obj.vec[i];
	}
	return Vector(tmp);
}
void Vector::print() {
	for (int i = 0; i < 5; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main() {
	int v[5]{};

	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	Vector v1(v);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	Vector v2(v);

	(v1 + v2).print();
	(v1 - v2).print();
	return 0;
}