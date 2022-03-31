#include <iostream>
#include <stack>
using namespace std;
int main() {
	int t;
	cin >> t;
	stack<int> zhan;
	while (t--) {
		int n;
		cin >> n;
		cout << "Constructor." << endl;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			zhan.push(x);
		}
		for (int i = 0; i < n; i++) {
			cout << zhan.top();
			if (i != n - 1) {
				cout << " ";
			}
			zhan.pop();
		}
		cout << endl;
		cout << "Destructor." << endl;
	}
	return 0;
}