#include <iostream>
#include <cstring>
using namespace std;



class CVector {
private:
	int* data;
	int n;
	static int sum;
public:
	CVector();
	CVector(int n1, int a[]);
	void Print();
	static void PrintSum();
	static void ResetSum();
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
	for (int i = 0; i < n; i++) {
		sum += data[i];
	}
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
void CVector::PrintSum() {
	cout << sum << endl;
}
void CVector::ResetSum() {
	sum = 0;
}

int CVector::sum;
int main() {
	int t;
	cin >> t;
	while (t--) {
		CVector::ResetSum();
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int n;
			cin >> n;
			int* a = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> a[j];
			}
			CVector vec(n, a);
			vec.Print();
			delete[] a;
		}
		CVector::PrintSum();
	}
	return 0;
}