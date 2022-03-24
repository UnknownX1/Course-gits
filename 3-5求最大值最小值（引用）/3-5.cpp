#include <iostream>
using namespace std;

void find(int* num, int n, int& minIndex, int& maxIndex) {
	for (int i = 1; i < n; i++) {
		if (num[i] > num[maxIndex]) {
			maxIndex = i;
		}
		if (num[i] < num[minIndex]) {
			minIndex = i;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* p = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int minindex=0, maxindex=0;
		find(p,n,minindex,maxindex);
		cout << "min=" << p[minindex] << " minindex=" << minindex << endl;
		cout << "max=" << p[maxindex] << " maxindex=" << maxindex << endl;
		cout << endl;
		delete[]p;
	}
	return 0;
}