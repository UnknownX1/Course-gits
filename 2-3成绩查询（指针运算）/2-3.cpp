#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n,find;
		cin >> n;
		int *a=new int[n];
		for (int* p = a; p < a + n; p++) {
			cin >> *p;
		}
		cin >> find;
		int* mid = a + (n / 2);
		cout << *(mid - 1) << ' ' << *(mid + 1) << endl;
		cout << *(a + find - 1) << endl;
	}
	return 0;
}