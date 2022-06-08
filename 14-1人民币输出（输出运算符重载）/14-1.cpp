#include <iostream>
using namespace std;

class RMB {
private:
	int yuan, jiao, fen;
public:
	RMB(float money);
	friend ostream& operator << (ostream& oo, RMB& r);
};

RMB::RMB(float money) {
	float tmp = money;

	yuan = money;

	money = money - yuan * 1.0;
	money *= 10;
	jiao = money;

	money = tmp * 100;
	money = money - yuan * 100 - jiao * 10;
	fen = money;
}

ostream& operator << (ostream& oo, RMB& r) {
	return oo << "yuan=" << r.yuan << " jiao=" << r.jiao << " fen=" << r.fen << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		float money;
		cin >> money;
		RMB r(money);
		cout << r;
	}
	return 0;
}