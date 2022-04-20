#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    static float count; // 账户总余额
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account();
    ~Account();
    void deposit(float amount); // 存款
    void withdraw(float amount); // 取款
    float getBalance(); // 获取账户余额
    void show(); // 显示账户所以基本信息
    static float getCount(); // 获取账户总余额
    static void setInterestRate(float rate); // 设置利率
    static float getInterestRate(); // 获取利率
    friend void update(Account& a);
    void setAccount(string ac, string na, float ba);
};
Account::Account() {
    accno = "000000";
    accname = "noname";
    balance = 0;
}
void Account::setAccount(string ac, string na, float ba) {
    accno = ac;
    accname = na;
    balance = ba;
    count += ba;
}
Account::~Account() {
    count -= balance;
}
void Account::deposit(float amount) {  // 存款
    balance += amount;
    count += amount;
    cout << getBalance() << " ";
}
void Account::withdraw(float amount) {   // 取款
    balance -= amount;
    count -= amount;
    cout << getBalance() << endl;
}
float Account::getBalance() {
    return balance;
}
void Account::show() {
    cout << accno << " " << accname << " ";
}
float Account::getCount() {
    return count;
}
void Account::setInterestRate(float rate) {
    interestRate = rate;
}
float Account::getInterestRate() {
    return interestRate;
}

void update(Account& a) {
    float add;
    add = a.balance * a.getInterestRate();
    a.balance += add;
    Account::count += add;
    cout << a.balance << " ";
}

float Account::count = 0;
float Account::interestRate = 0;
int main() {
    float x;
    cin >> x;
    Account::setInterestRate(x);
    int t;
    cin >> t;
    Account* acc = new Account[t];
    for (int i = 0; i < t;i++) {
        string accname, accno;
        float balance, in, out;
        cin >> accno >> accname >> balance >> in >> out;
        acc[i].setAccount(accno, accname, balance);
        acc[i].show();
        acc[i].deposit(in);
        update(acc[i]);
        acc[i].withdraw(out);
    }
    cout << Account::getCount();
    delete[] acc;
    return 0;
}