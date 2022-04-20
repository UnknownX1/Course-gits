#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class cls {
private:
	int x;
public:
	cls();
	cls(int xx);
	cls(const cls &p);

};

cls::cls() {
	x = 0;
	cout << "Constructed by default, value = " << x << endl;
}

cls::cls(int xx) {
	x = xx;
	cout << "Constructed using one argument constructor, value = " << x << endl;
}

cls::cls(const cls& p) {
	x = p.x;
	cout << "Constructed using copy constructor, value = " << x << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 0) {
			cls cls0;
		}
		else if (n == 1) {
			int x;
			cin >> x;
			cls cls1(x);
		}
		else {
			int x;
			cin >> x;
			cls cls2(x);
			cls cls3(cls2);
		}
	}
	return 0;
}
