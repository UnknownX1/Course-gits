#include <iostream>
#include <string.h>
using namespace std;

int comp(char* s, char* t) {
	char* ps = s, * pt = t;
	int res0 = 0;
	int lens = strlen(s), lent = strlen(t);
	if (lens != lent) {
		return lens > lent ? 1 : -1;
	}
	else {
		while (lens--) {
			if (*ps > *pt) {
				res0 += 1;
			}
			else if (*ps < *pt) {
				res0 -= 1;
			}
			ps++;
			pt++;
		}
		if (res0 > 0) {
			return 1;
		}
		else if (res0 < 0) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	int n,res;
	cin >> n;
	while (n--) {
		char a[25], b[25];
		cin >> a >> b;
		res=comp(a, b);
		cout << res<<endl;
	}
	return 0;
}