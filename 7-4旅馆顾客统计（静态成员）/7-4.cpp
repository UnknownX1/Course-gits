#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int id = 0;

class Hotel
{
private:
	static int totalCustNum; // �˿�������
	static float totalEarning; // �õ�������
	static float rent; // ÿ���˿͵ķ���
	char* customerName; // �˿�����
	int customerId; // �˿ͱ��
public:
	// totalCustNum++��customerId����totalCustNum����
	Hotel(char* customer);
	~Hotel(); //�ǵ�delete customerName
	void Display(); //��Ӧ����˿��������˿ͱ�š���������������
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
	//���� 20150001 1 150\n
	cout << customerName << " 2015" << setw(4) << setfill('0') << customerId << " " << Hotel::totalCustNum << " " << Hotel::totalEarning << endl;
}
void Hotel::Setrent(float x) {
	rent = x;
}

int Hotel::totalCustNum = 0; // �˿�������
float Hotel::totalEarning = 0; // �õ�������
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