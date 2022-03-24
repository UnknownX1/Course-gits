#include <iostream>
using namespace std;

int main() {
	const char* p[12] = { "January","February","March","April","May","June","July","Aguest","September","October","November","December" };
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x > 12 || x < 1) {
			cout << "error" << endl;
		}
		else {
			cout << *(p + x - 1) << endl;
		}
	}
	return 0;
}