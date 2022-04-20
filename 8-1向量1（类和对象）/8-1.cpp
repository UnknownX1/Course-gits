#include <iostream>
#include <cstring>
using namespace std;

class CVector {
private:
	int* data;
	int n;
public:
	CVector();
	CVector(int n1, int a[]);
	void Print();
	~CVector();
};

CVector::CVector() {
	n = 5;
	data = new int[5]{ 0,1,2,3,4 };
}
CVector::CVector(int n1, int a[]) {
	n = n1;
	data = new int[n1];
	memcpy(data, a, n1 * sizeof(int));
}
void CVector::Print() {
	for (int i = 0; i < n; i++) {
		cout << data[i];
		if (i != n - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
}
CVector::~CVector() {
	delete[] data;
}

int main() {
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	CVector vector1;
	CVector vector2(n, data);
	vector1.Print();
	vector2.Print();
	return 0;
}