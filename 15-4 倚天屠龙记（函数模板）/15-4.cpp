#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<class T>void cat(int n, T* T1, T* T2) {
	T* c = new T[2 * n];
	for (int i = 0; i < n; i++) {
		c[i] = T2[i];
	}
	for (int i = 0; i < n; i++) {
		c[n + i] = T1[i];
	}
	for (int i = 0; i < 2 * n; i++) {
		cout << c[i];
	}
	cout << endl;
}
template<class T>void input(int n, T& T1, T& T2) {
	for (int i = 0; i < n; i++) {
		cin >> T1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> T2[i];
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char type;
		int n;
		cin >> type >> n;
		if (type == 'I') {
			int* a = new int[n];
			int* b = new int[n];
			input(n, a, b);
			cat(n, a, b);
			delete[]a;
			delete[]b;
		}
		else if (type == 'D') {
			double* a = new double[n];
			double* b = new double[n];
			input(n, a, b);
			cat(n, a, b);
			delete[]a;
			delete[]b;
			break;
		}
		else {
			char* a = new char[n];
			char* b = new char[n];
			input(n, a, b);
			cat(n, a, b);
			delete[]a;
			delete[]b;
			break;
		}

	}
	return 0;
}