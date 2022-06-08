#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

class CXGraph {
	int n;
public:
	CXGraph(int nn) {
		n = nn;
	}
	friend CXGraph& operator ++(CXGraph& c);
	friend CXGraph& operator --(CXGraph& c);
	friend CXGraph operator --(CXGraph& c, int);
	friend CXGraph operator ++(CXGraph& c, int);
	friend ostream& operator << (ostream& oo, const CXGraph& c);
};

CXGraph& operator ++(CXGraph& c) {
	c.n += 2;
	if (c.n > 21) {
		c.n = 21;
	}
	return c;
}
CXGraph operator ++(CXGraph& c, int) {
	CXGraph tmp = c;
	c.n += 2;
	if (c.n > 21) {
		c.n = 21;
	}
	return tmp;
}
CXGraph& operator --(CXGraph& c) {
	c.n -= 2;
	if (c.n < 1) {
		c.n = 1;
	}
	return c;
}
CXGraph operator --(CXGraph& c, int) {
	CXGraph tmp = c;
	c.n -= 2;
	if (c.n < 1) {
		c.n = 1;
	}
	return tmp;
}
ostream& operator << (ostream& oo, const CXGraph& c) {
	for (int k = 0; k < (c.n + 1) / 2; k++) {

		for (int i = 0; i < k; i++) {
			oo << " ";
		}
		for (int i = 0; i < c.n - k * 2; i++) {
			oo << "X";
		}
		oo << endl;
	}

	for (int k = (c.n + 1) / 2; k < c.n; k++) {
		for (int i = 0; i < c.n - k - 1; i++) {
			oo << " ";
		}
		for (int i = 0; i < c.n - 2 * (c.n - k - 1); i++) {
			oo << "X";
		}
		oo << endl;
	}
	return oo;
}

int main()
{
	int t, n;
	string command;
	cin >> n;
	CXGraph xGraph(n);
	cin >> t;
	while (t--)
	{
		cin >> command;
		if (command == "show++")
		{
			cout << xGraph++ << endl;
		}
		else if (command == "++show")
		{
			cout << ++xGraph << endl;
		}
		else if (command == "show--")
		{
			cout << xGraph-- << endl;
		}
		else if (command == "--show")
		{
			cout << --xGraph << endl;
		}
		else if (command == "show")
		{
			cout << xGraph << endl;
		}
	}
	return 0;
}