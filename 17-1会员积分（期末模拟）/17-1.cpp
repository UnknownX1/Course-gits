#include<iostream>

using namespace std;


// 普通会员类
class Member
{
	// ....代码自行编写
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
	cout << "普通会员" << id << "--" << name << "--" << score << endl;
}

// 贵宾会员类
class VIP : public Member
{
	// ....代码自行编写
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
	cout << "贵宾会员" << id << "--" << name << "--" << score << endl;
}



int main()
{
	// 创建一个基类对象指针
	Member* pm;
	// ....其他变量自行编写
	int id, score, money, addRate, exchangeRate;
	string name;
	// 输入数据，创建普通会员对象mm
	cin >> id >> name >> score;
	Member mm(id, name, score);
	// 使用指针pm执行以下操作：
	// 1、pm指向普通会员对象mm
	pm = &mm;
	// 2、输入数据，通过pm执行积分累加和积分兑换
	cin >> money;
	pm->add(money);
	cin >> money;
	pm->exchange(money);
	// 3、通过pm调用打印方法输出
	pm->print();

	// 输入数据，创建贵宾会员对象vv
	cin >> id >> name >> score >> addRate >> exchangeRate;
	VIP vv(id, name, score,addRate,exchangeRate);
	// 使用指针pm执行以下操作：
	// 1、pm指向贵宾会员对象vv
	pm = &vv;
	// 2、输入数据，通过pm执行积分累加和积分兑换
	cin >> money;
	pm->add(money);
	cin >> money;
	pm->exchange(money);
	// 3、通过pm调用打印方法输出
	pm->print();

	return 0;
}