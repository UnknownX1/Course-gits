#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		int** p = new int* [m];
		for (int i = 0; i < m; i++) {
			p[i] = new int[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> p[i][j];
			}
		}
		int max=**p, min=**p;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i][j] > max) {
					max = p[i][j];
				}
				if (p[i][j] < min) {
					min = p[i][j];
				}
			}
		}
		cout << min << ' ' << max<<endl;
	}
	return 0;
}