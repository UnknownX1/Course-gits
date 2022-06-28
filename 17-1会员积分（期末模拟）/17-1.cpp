#include<iostream>

using namespace std;


// ��ͨ��Ա��
class Member
{
	// ....�������б�д
protected:
	int id;
	string name;
	int score;
public:
	Member(){}
	Member(int id_,string name_,int score_)
	{
		id = id_;
		name = name_;
		score = score_;
	}
	virtual void add(int money);
	virtual int exchange(int money);
	virtual void print();
};
void Member::add(int money) {
	score += money;
}
int Member::exchange(int money) {
	score -= (money / 100)*100;
	return money / 100;
}
void Member::print() {
	cout << "��ͨ��Ա" << id << "--" << name << "--" << score << endl;
}

// �����Ա��
class VIP : public Member
{
	// ....�������б�д
	int addRate, exchangeRate;
public:
	VIP(int id_, string name_, int score_,int addRate_, int exchangeRate_) :Member(id_, name_, score_) {
		addRate = addRate_;
		exchangeRate = exchangeRate_;
	}
	void add(int money);
	int exchange(int money);
	void print();
};
void VIP::add(int money) {
	score += addRate * money;
}
int VIP::exchange(int money) {
	score -= (money / exchangeRate)* exchangeRate;
	return money / exchangeRate;
}
void VIP::print() {
	cout << "�����Ա" << id << "--" << name << "--" << score << endl;
}



int main()
{
	// ����һ���������ָ��
	Member* pm;
	// ....�����������б�д
	int id, score, money, addRate, exchangeRate;
	string name;
	// �������ݣ�������ͨ��Ա����mm
	cin >> id >> name >> score;
	Member mm(id, name, score);
	// ʹ��ָ��pmִ�����²�����
	// 1��pmָ����ͨ��Ա����mm
	pm = &mm;
	// 2���������ݣ�ͨ��pmִ�л����ۼӺͻ��ֶһ�
	cin >> money;
	pm->add(money);
	cin >> money;
	pm->exchange(money);
	// 3��ͨ��pm���ô�ӡ�������
	pm->print();

	// �������ݣ����������Ա����vv
	cin >> id >> name >> score >> addRate >> exchangeRate;
	VIP vv(id, name, score,addRate,exchangeRate);
	// ʹ��ָ��pmִ�����²�����
	// 1��pmָ������Ա����vv
	pm = &vv;
	// 2���������ݣ�ͨ��pmִ�л����ۼӺͻ��ֶһ�
	cin >> money;
	pm->add(money);
	cin >> money;
	pm->exchange(money);
	// 3��ͨ��pm���ô�ӡ�������
	pm->print();

	return 0;
}