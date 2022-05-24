#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	//余额、利率、号码、类型
	float money;
	float rate;
	int num;
	char type;
public:
	Account(float mo, float ra, int nu, char ty);
	Account(const Account& p);
	void Jixi();
	void Chaxun();
};

Account::Account(float mo, float ra, int nu, char ty) {
	money = mo;
	rate = ra;
	num = nu;
	type = ty;
}
Account::Account(const Account& p) {
	money = p.money;
	rate = 0.015;
	num = p.num + 50000000;
	type = p.type;
}
void Account::Jixi() {
	//Account=12345678--sum=10050\n
	money += rate * money;
	cout << "Account=" << num << "--sum=" << money << endl;
}
void Account::Chaxun() {
	//Account=62345678--Person--sum=10000--rate=0.015\n
	cout << "Account=" << num << "--";
	if (type == 'P') {
		cout << "Person--sum=";
	}
	else {
		cout << "Enterprise--sum=";
	}
	cout << money << "--rate=" << rate << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		float money;
		int num;
		char type;
		cin >> num >> type >> money;
		Account act1(money, 0.005, num, type);
		Account act2(act1);
		char op;
		cin >> op;
		if (op == 'C') {
			act1.Jixi();
		}
		else {
			act1.Chaxun();
		}
		cin >> op;
		if (op == 'C') {
			act2.Jixi();
		}
		else {
			act2.Chaxun();
		}
	}
	return 0;
}