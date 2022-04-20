#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    static float count; // �˻������
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account();
    ~Account();
    void deposit(float amount); // ���
    void withdraw(float amount); // ȡ��
    float getBalance(); // ��ȡ�˻����
    void show(); // ��ʾ�˻����Ի�����Ϣ
    static float getCount(); // ��ȡ�˻������
    static void setInterestRate(float rate); // ��������
    static float getInterestRate(); // ��ȡ����
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
void Account::deposit(float amount) {  // ���
    balance += amount;
    count += amount;
    cout << getBalance() << " ";
}
void Account::withdraw(float amount) {   // ȡ��
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