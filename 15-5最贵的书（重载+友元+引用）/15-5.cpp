#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CBook {
	string name, person, publisher;
	double price;
public:
	friend void find(CBook* book, int n, int& max1index, int& max2index);
	friend istream& operator>>(istream& ii, CBook& c);
	friend ostream& operator<<(ostream& oo, CBook& c);
	bool operator >(CBook& c) {
		if (price > c.price) {
			return true;
		}
		return false;
	}
	bool operator >=(CBook& c) {
		if (price >= c.price) {
			return true;
		}
		return false;
	}
};
void find(CBook* book, int n, int& max1index, int& max2index) {
	for (int i = 0; i < n; i++) {
		if (book[i] > book[max1index]) {
			max1index = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != max1index && book[i] >= book[max2index]) {
			max2index = i;
		}
	}

}
istream& operator>>(istream& ii, CBook& c) {
	string tmp;
	getline(ii, c.name, ',');
	getline(ii, c.person, ',');
	getline(ii, tmp, ',');
	c.price = stod(tmp);

	getline(ii, c.publisher, '\n');
	return ii;
}
ostream& operator<<(ostream& oo, CBook& c) {
	oo << c.name << endl << c.person << endl << fixed << setprecision(2) << c.price << endl << c.publisher << endl;
	return oo;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int max1index = 0, max2index = 0;
		int n;
		cin >> n;
		cin.get();
		CBook* book = new CBook[n];
		for (int i = 0; i < n; i++) {
			cin >> book[i];
		}
		find(book, n, max1index, max2index);
		cout << book[max1index] << endl << book[max2index] << endl;
	}
	return 0;
}