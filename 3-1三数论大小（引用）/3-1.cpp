#include <iostream>
using namespace std;

void sort(int& a, int& b, int& c) {
	int temp;
	for (int i = 0; i < 2; i++) {
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (b < c) {
			temp = b;
			b = c;
			c = temp;
		}
	}
	cout << a << ' ' << b << ' ' << c << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		sort(a, b, c);
	}
	return 0;
}