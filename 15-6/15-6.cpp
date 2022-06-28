#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class CSet {
	int n;
	int* p;
public:

	CSet(int n_, int* pp);
	CSet(const CSet& c);
	~CSet();
	friend CSet operator+(const CSet& c1, const  CSet& c2);
	friend CSet operator-(const CSet& c1, const  CSet& c2);
	friend CSet operator*(const CSet& c1, const  CSet& c2);
	friend ostream& operator<<(ostream& oo, const CSet& c);


};
CSet::CSet(int n_, int* pp) {
	n = n_;
	p = new int[n];
	memcpy(p, pp, n * sizeof(int));
}

CSet::CSet(const CSet& c) {
	n = c.n;
	p = new int[c.n];
	memcpy(p, c.p, c.n * sizeof(int));
}

CSet::~CSet() {
	delete[]p;
}

CSet operator+(const CSet& c1, const  CSet& c2) {
	int len = 0;
	int* aaa = new int[c1.n + c2.n];
	for (int i = 0; i < c1.n; i++) {
		bool has = false;
		for (int j = 0; j < len; j++) {
			if (c1.p[i] == aaa[j]) {
				has = true;
			}
		}
		if (!has) {
			aaa[len] = c1.p[i];
			len++;
		}
	}
	for (int i = 0; i < c2.n; i++) {
		bool has = false;
		for (int j = 0; j < len; j++) {
			if (c2.p[i] == aaa[j]) {
				has = true;
				break;
			}
		}
		if (!has) {
			aaa[len] = c2.p[i];
			len++;
		}
	}
	CSet tmp(len, aaa);
	delete[]aaa;
	return tmp;
}

CSet operator-(const CSet& c1, const  CSet& c2) {
	int len = 0;
	int* aaa = new int[c1.n + c2.n];
	for (int i = 0; i < c1.n; i++) {
		bool has = false;
		for (int j = 0; j < c2.n; j++) {
			if (c1.p[i] == c2.p[j]) {
				has = true;
				break;
			}
		}
		if (!has) {
			aaa[len] = c1.p[i];
			len++;
		}
	}
	CSet tmp(len, aaa);

	delete[]aaa;
	return tmp;
}

CSet operator*(const CSet& c1, const  CSet& c2) {
	int len = 0;
	int* aaa = new int[c1.n + c2.n];
	for (int i = 0; i < c1.n; i++) {
		bool has = false;
		for (int j = 0; j < c2.n; j++) {
			if (c1.p[i] == c2.p[j]) {
				has = true;
				break;
			}
		}
		if (has) {
			aaa[len] = c1.p[i];
			len++;
		}
	}
	CSet tmp(len, aaa);
	delete[]aaa;
	return tmp;
}

ostream& operator<<(ostream& oo, const CSet& c) {
	for (int i = 0; i < c.n; i++) {
		oo << c.p[i];
		if (i != c.n - 1) {
			oo << " ";
		}
		else {
			oo << endl;
		}
	}
	return oo;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n1, n2;
		cin >> n1;
		int* p1 = new int[n1];
		for (int i = 0; i < n1; i++) {
			cin >> p1[i];
		}
		CSet c1(n1, p1);
		cin >> n2;
		int* p2 = new int[n2];
		for (int i = 0; i < n2; i++) {
			cin >> p2[i];
		}
		CSet c2(n2, p2);

		cout << "A:" << c1;
		cout << "B:" << c2;
		cout << "A+B:" << c1 + c2;
		cout << "A*B:" << c1 * c2;
		cout << "(A-B)+(B-A):" << (c1 - c2) + (c2 - c1);
		cout << endl;
	}
	return 0;
}