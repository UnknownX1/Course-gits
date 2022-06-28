#include <iostream>
#include <string>
using namespace std;

class Product {
private:
	int type;
	string name;
	int price, state;
public:
	Product(int type_, string name_, int price_, int state_) {
		type = type_;
		name = name_;
		price = price_;
		state = state_;
	}
	void print();
	int fee(int day);
};
void Product::print() {
	switch (type) {
	case 1:
		cout << "�ڽ�Ƭ";
		break;
	case 2:
		cout << "CD";
		break;
	case 3:
		cout << "VCD";
		break;
	case 4:
		cout << "DVD";
		break;
	}
	cout << "[" << name << "]";
	if (state == 0) {
		cout << "δ����\n";
	}
	else {
		cout << "�ѳ���\n";
	}
}
int Product::fee(int day) {
	print();
	if (state == 0) {
		return 0;
	}
	return price * day;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int type, price, state;
		string name;
		cin >> type >> name >> price >> state;
		Product pro(type, name, price, state);
		int op;
		cin >> op;
		if (op != 0) {
			int fee = pro.fee(op);
			if (fee) {
				cout << "��ǰ���Ϊ" << fee << endl;
			}
			else {
				cout << "δ�������\n";
			}
		}
		else {

			pro.print();
		}
	}
	return 0;
}