#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		char a[21],b[21],c[21];
		char* p = a, * q = b, * s = c;
		cin >> a >> b;
		while (*p != '\0') {
			if (*q == '\0') {
				q = b;
			}
			int out = 0;
			if (*p <= 'z' && int(*p)+int((*q - '0'))>int('z') || *p <= 'Z' && int(*p) + int((*q - '0')) > int('Z')) {
				out = -26;
			}
			*s = *p + out + (*q - '0');
			p++;
			q++;
			s++;
		}
		*s = '\0';
		cout << c << endl;
	}
	return 0;
}