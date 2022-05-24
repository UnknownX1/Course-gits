#include <iostream>
#include <cstring>
using namespace std;

class MyMatrix {
private:
	int n;
	int** p;
public:
	MyMatrix(int n, int** pp);
	~MyMatrix();
	MyMatrix(const MyMatrix& p);
	friend MyMatrix operator* (const MyMatrix& a, MyMatrix& b);
	MyMatrix& operator= (const MyMatrix& a);
	void show();
};

MyMatrix::MyMatrix(int n_, int** p_) {
	n = n_;
	p = new int* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = p_[i][j];
		}
	}
}
MyMatrix::~MyMatrix() {
	for (int i = 0; i < n; i++) {
		delete[] p[i];
	}
	delete[]p;
}

MyMatrix operator* (const MyMatrix& a, MyMatrix& b) {
	int** tmp = new int* [a.n]{ 0 };
	for (int i = 0; i < a.n; i++) {
		tmp[i] = new int[a.n]{ 0 };
	}

	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			for (int k = 0; k < a.n; k++) {
				tmp[i][j] += a.p[i][k] * b.p[k][j];
			}
		}
	}
	MyMatrix aaa(a.n, tmp);

	for (int i = 0; i < a.n; i++) {
		delete[] tmp[i];
	}
	delete[]tmp;
	return aaa;
}

MyMatrix& MyMatrix::operator= (const MyMatrix& pp) {
	n = pp.n;
	p = new int* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = pp.p[i][j];
		}
	}
	return *this;
}

MyMatrix::MyMatrix(const MyMatrix& pp) {
	n = pp.n;
	p = new int* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = pp.p[i][j];
		}
	}
}
void MyMatrix::show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << p[i][j];
			if (j == n - 1) {
				cout << endl;
			}
			else {
				cout << " ";
			}
		}
	}
}

int main() {
	int t, n;
	cin >> t >> n;
	int** mat = new int* [n] {};
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n] {};
	}
	//³õÊ¼»¯
	for (int j = 0; j < n; j++) {
		mat[j][j] = 1;
	}

	MyMatrix res(n, mat);
	//ÊäÈë
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> mat[j][k];
			}
		}
		MyMatrix mat0(n, mat);
		res = (res * mat0);

	}

	res.show();

	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[]mat;

	return 0;
}
