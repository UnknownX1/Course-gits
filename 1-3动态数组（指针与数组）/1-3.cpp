#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		char ch;
		int len;
		cin >> ch >> len;
		if (ch == 'I') {
			int *x = new int[len];
			int *p = x, sum = 0;
			for (int i = 0; i < len;i++) {
				cin >> *(p++);
			}
			p = x;
			for (int i = 0; i < len; i++) {
				sum += *p;
				p++;
			}
			cout << (sum / len) << endl;

		}
		else if (ch == 'C') {
			char* x = new char[len];
			char* p = x, * max = x;
			for (int i = 0; i < len; i++) {
				cin >> *(p++);
			}
			p = x;
			for (int i = 0; i < len; i++) {
				if (*max < *p) {
					max = p;
				}
				p++;
			}
			cout << *max << endl;
		}
		else {
			float* x = new float[len];
			float* p = x, * min = x;
			for (int i = 0; i < len; i++) {
				cin >> *(p++);
			}
			p = x;
			for (int i = 0; i < len; i++) {
				if (*min > *p) {
					min = p;
				}
				p++;
			}
			cout << *min<<endl;
		}
	}

	return 0;
}
