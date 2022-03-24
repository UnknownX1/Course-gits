#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		char a[10],b[10],c[10];
		char* pa = a, * pb = b, * pc = c;
		int x1, x2, x3, x4, x5, x6,len;
		char* p = NULL;
		cin >> a >> b >> c;
		cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
		len = x2 + x4 + x6 - x1 - x3 - x5 + 3;
		char* string = new char[len];
		char* ps = string;
		for (int i = x1; i <= x2; i++) {
			*(ps++) = *(pa + i - 1);
		}
		for (int i = x3; i <= x4; i++) {
			*(ps++) = *(pb + i - 1);
		}
		for (int i = x5; i <= x6; i++) {
			*(ps++) = *(pc + i - 1);
		}
		cout << string<<endl;


	}
	return 0;
}
