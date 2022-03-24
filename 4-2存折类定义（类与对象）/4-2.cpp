#include <iostream>
using namespace std;

class CAccount
{
private:
	long account;
	char name[10];
	float balance;
public:
	CAccount(long act, char na[10], float ba);
	void deposit(float n);
	void withdraw(float n);
	void check();
};

CAccount::CAccount(long act, char na[10], float ba)
{
	account = act;
	for (int i = 0; i < 10; i++)
	{
		name[i] = na[i];
	}
		balance = ba;
}

void CAccount::deposit(float n)
{
	balance += n;
	cout << "saving ok!" << endl;
}

void CAccount::withdraw(float n)
{
	if (balance >= n)
	{
		balance -= n;
		cout << "withdraw ok!" << endl;
	}
	else
	{
		cout << "sorry! over limit!" << endl;
	}
}

void CAccount::check()
{
	cout << name << "'s balance is " << balance << endl;
}

int main()
{
	for (int i = 0; i < 2; i++)
	{
		long account;
		char name[10];
		float balance;
		cin >> account >> name >> balance;
		CAccount Cac(account,name,balance);
		Cac.check();
		float dep, wit;
		cin >> dep >> wit;
		Cac.deposit(dep);
		Cac.check();
		Cac.withdraw(wit);
		Cac.check();
	}
	return 0;
}