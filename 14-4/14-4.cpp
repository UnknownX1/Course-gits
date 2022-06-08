#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

class four {
	int a;
public:
	four(int aa) {
		a = aa;
	}
	friend four operator + (const four& f1, four& f2);
	void show() {
		cout << a << endl;
	}
};

four operator + (const four& f1, four& f2) {
	int d1, d2, jinwei = 0, digit = 0, res = 0, weishu = 0;
	int tmp1 = f1.a;
	int tmp2 = f2.a;


	while (true)
	{
		d1 = tmp1 % 10;
		d2 = tmp2 % 10;
		digit = d1 + d2 + jinwei;
		jinwei = 0;
		if (digit == 0) {
			return res;
		}
		if (digit >= 4) {
			jinwei = 1;
			digit -= 4;
		}

		res += digit * pow(10, weishu);
		weishu++;

		tmp1 /= 10;
		tmp2 /= 10;
	}

}

int main() {
	int t;
	cin >> t;
	four res(0);
	while (t--) {
		int a;
		cin >> a;
		res = four(a) + res;

	}
	res.show();
	return 0;
}