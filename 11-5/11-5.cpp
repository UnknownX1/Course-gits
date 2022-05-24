#include <iostream>
#include <iomanip>
using namespace std;

class BaseAccount {
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(string name_,string account_,int bal);
	virtual void deposit(int m);
	virtual void withdraw(int m);
	virtual void display();
};
BaseAccount::BaseAccount(string name_, string account_, int bal) {
	name = name_;
	account = account_;
	balance = bal;
}
void BaseAccount::deposit(int m) {
	balance += m;
}
void BaseAccount::withdraw(int m) {
	if (balance < m) {
		cout << "insufficient" << endl;
	}
	else {
		balance -= m;
	}

}
void BaseAccount::display() {
	cout << name << " " << account << " Balance:" << balance << endl;
}

class BasePlus :public BaseAccount {
private:
	int limit;
	int limitsum;
public:
	void withdraw(int m);
	void display();
	BasePlus(string name_, string account_, int bal);
};
BasePlus::BasePlus(string name_, string account_, int bal):BaseAccount(name_,account_,bal) {
	limit = 5000;
	limitsum = 0;
}
void BasePlus::withdraw(int m) {
	if ((balance + limit) < m) {
		cout << "insufficient" << endl;
	}
	else if (balance >= m) {
		balance -= m;
	}
	else {

		limitsum += m - balance;
		limit -= m - balance;
		balance = 0;
	}
}
void BasePlus::display() {
	cout << name << " " << account << " Balance:" << balance << " limit:" << limit << endl;
}

int main() {
	int t;
	cin >> t;
	BaseAccount* p;
	while (t--) {
		string name, zhanghao;
		int bal;
		cin >> name >> zhanghao >> bal;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (zhanghao[1] == 'A') {
			p = new BaseAccount(name,zhanghao,bal);
			p->deposit(a);
			p->withdraw(b);
			p->deposit(c);
			p->withdraw(d);
			p->display();
		}
		else {
			p = new BasePlus(name, zhanghao, bal);
			p->deposit(a);
			p->withdraw(b);
			p->deposit(c);
			p->withdraw(d);
			p->display();
		}
	}
	return 0;
}

