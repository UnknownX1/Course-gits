#include <iostream>
using namespace std;

class CMoney
{
public:
	CMoney(int y, int j, int f);
	friend CMoney operator+(CMoney& a, const CMoney& b);
	friend CMoney operator-(CMoney& a, const CMoney& b);
	void show() {
		cout << yuan << "Ôª" << jiao << "½Ç" << fen << "·Ö\n";
	}
private:
	int yuan, jiao, fen;
};

CMoney::CMoney(int y, int j, int f)
{
	yuan = y;
	jiao = j;
	fen = f;
}
CMoney operator+(CMoney& a, const CMoney& b) {
	a.fen += b.fen;
	if (a.fen >= 10) {
		a.fen -= 10;
		a.jiao++;
	}
	a.jiao += b.jiao;
	if (a.jiao >= 10) {
		a.jiao -= 10;
		a.yuan++;
	}
	a.yuan += b.yuan;
	return a;
}
CMoney operator-(CMoney& a, const CMoney& b) {


	a.fen -= b.fen;
	if (a.fen < 0) {
		a.fen += 10;
		a.jiao--;
	}
	a.jiao -= b.jiao;
	if (a.jiao < 0) {
		a.jiao += 10;
		a.yuan--;
	}
	a.yuan -= b.yuan;
	return a;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int y, j, f;
		cin >> y >> j >> f;
		CMoney money(y, j, f);
		while (1) {
			string op;
			cin >> op;
			if (op == "add") {
				cin >> y >> j >> f;
				money = money + CMoney(y, j, f);
			}
			else if (op == "minus") {
				cin >> y >> j >> f;
				money = money - CMoney(y, j, f);
			}
			else {
				money.show();
				break;
			}
		}
	}
	return 0;
}