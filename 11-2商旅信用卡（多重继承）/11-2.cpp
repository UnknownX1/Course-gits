#include <iostream>
#include <string>
using namespace std;

class CHYCard {
protected:
	int num;
	int score;
public:
	CHYCard(int num);
};
CHYCard::CHYCard(int num_) {
	num = num_;
	score = 0;
}

class CXYCard {
protected:
	int cardnum;
	string name;
	int max; //额度
	float jiner; //账单金额
	int jifen; //信用卡积分
public:
	void xiaofei(float m);
	void tuikuan(float m);
	CXYCard(int cardnum_, string name_, int max);
};
void CXYCard::xiaofei(float m) {
	if (m <= max) {
		jiner += m;
		max -= m;
		jifen += m;
	}
}
void CXYCard::tuikuan(float m) {
	jiner -= m;
	jifen -= (int)m;
}
CXYCard::CXYCard(int cardnum_, string name_, int max_) {
	cardnum = cardnum_;
	name = name_;
	max = max_;
	jiner = 0;
	jifen = 0;
}

class CXYHYCard :public CHYCard, public CXYCard {
public:
	CXYHYCard(int cardnum_, string name_, int max_, int num_);
	void xiadan(float m);
	void duihuan(float m);
	void print();
};
void CXYHYCard::print() {
	cout << cardnum << " " << score << endl;
	cout << num << " " << name << " " << jiner << " " << jifen << endl;
}
void CXYHYCard::xiadan(float m) {
	jifen += m;
	score += m;
	jiner += m;
}
void CXYHYCard::duihuan(float m) {
	jifen -= m;
	score += m / 2;
}
CXYHYCard::CXYHYCard(int cardnum_, string name_, int max_, int num_) :CXYCard(cardnum_, name_, max_), CHYCard(num_) {

}

int main() {
	int xynum, hynum, erdu;
	string name;
	cin >> xynum >> hynum >> name >> erdu;
	CXYHYCard card(xynum, name, erdu, hynum);
	int t;
	cin >> t;
	while (t--) {
		char op;
		float m;
		cin >> op >> m;
		switch (op) {
		case 'o':
			card.xiadan(m);
			break;
		case 'c':
			card.xiaofei(m);
			break;
		case 'q':
			card.tuikuan(m);
			break;
		case 't':
			card.duihuan(m);
			break;
		}

	}
	card.print();
	return 0;
}