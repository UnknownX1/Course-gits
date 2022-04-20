#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int id = 0;

class Hotel
{
private:
	static int totalCustNum; // 顾客总人数
	static float totalEarning; // 旅店总收入
	static float rent; // 每个顾客的房租
	char* customerName; // 顾客姓名
	int customerId; // 顾客编号
public:
	// totalCustNum++，customerId按照totalCustNum生成
	Hotel(char* customer);
	~Hotel(); //记得delete customerName
	void Display(); //相应输出顾客姓名、顾客编号、总人数、总收入
	static void Setrent(float x);
};

Hotel::Hotel(char* customer) {
	customerName = new char[strlen(customer) + 1];
	strcpy(customerName, customer);
	totalCustNum += 1;
	customerId = ++id;
	totalEarning += rent;
}
Hotel::~Hotel() {
	delete[] customerName;
}
void Hotel::Display() {
	//张三 20150001 1 150\n
	cout << customerName << " 2015" << setw(4) << setfill('0') << customerId << " " << Hotel::totalCustNum << " " << Hotel::totalEarning << endl;
}
void Hotel::Setrent(float x) {
	rent = x;
}

int Hotel::totalCustNum = 0; // 顾客总人数
float Hotel::totalEarning = 0; // 旅店总收入
float Hotel::rent = 0;


int main() {
	float money;
	cin >> money;
	Hotel::Setrent(money);
	char name[20];
	cin >> name;
	while (!(name[0] == '0' && name[1] == '\0')) {
		Hotel h(name);
		h.Display();
		cin >> name;
	}
	return 0;
}