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
	CVector(const CVector& v);
	void Print();
	~CVector();
	friend CVector add(const CVector v1, const CVector v2);
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
CVector::CVector(const CVector &v) {
	n = v.n;
	data = new int[v.n];
	memcpy(data, v.data, v.n * sizeof(int));
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

CVector add(const CVector v1, const CVector v2) {
	int* data0 = new int[v1.n];
	for (int i = 0; i < v1.n; i++) {
		data0[i] = v1.data[i] + v2.data[i];
	}
	CVector v0(v1.n, data0);
	delete[] data0;
	return v0;
}

int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int *data1 = new int[n];
		int* data2 = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> data1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> data2[i];
		}
		CVector v1(n, data1);
		CVector v2(n, data2);
		v1.Print();
		v2.Print();
		add(v1, v2).Print();
		delete[] data1;
		delete[] data2;
	}
	return 0;
}