#include <iostream>
#include <cstring>
using namespace std;
class CMatrix;
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
	friend class CMatrix;
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
CVector::CVector(const CVector& v) {
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

class CMatrix {
private:
	int n;
	int** data;
public:
	CMatrix(int n, int** a);
	bool check(const CVector& v1);
	CVector multi(const CVector& v1);
	~CMatrix();

};
CMatrix::CMatrix(int n1, int** a) {
	n = n1;
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j] = a[i][j];
		}
	}
}
CMatrix::~CMatrix() {
	for (int i = 0; i < n; i++) {
		delete[] data[i];
	}
	delete[] data;
}
bool CMatrix::check(const CVector& v1) {
	if (n == v1.n) {
		return true;
	}
	else {
		return false;
	}
}
CVector CMatrix::multi(const CVector& v1) {
	int* data0 = new int[n] {0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data0[i] += v1.data[j] * data[i][j];
		}
	}
	return CVector(n, data0);
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int** data = new int* [n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> data[i][j];
			}
		}

		CMatrix mat(n, data);

		int m;
		cin >> m;
		int* data2 = new int[m];
		for (int i = 0; i < m; i++) {
			cin >> data2[i];
		}

		CVector vec(m, data2);

		if (mat.check(vec)) {
			mat.multi(vec).Print();
		}
		else {
			cout << "error" << endl;
		}

		for (int i = 0; i < n; i++) {
			delete[] data[i];
		}
		delete[] data;
		delete[] data2;
	}
	return 0;
}