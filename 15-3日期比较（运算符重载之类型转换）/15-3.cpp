#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class CDate {
	int day,year,month;
public:
	CDate(int date=0) {
		year = date/10000;
		month = (date-year*10000)/100;
		day = date%100;
	}
	operator int() {
		return year*10000+month*100+day;
	}
	void print();
};
void CDate::print() {

	cout << year << "��" << setw(2) << setfill('0') << month << "��" << setw(2) << setfill('0') << day<< "��\n";
}

int main()
{
	int t, t1, t2;
	CDate c1, c2;
	cin >> t;
	while (t--)
	{
		cin >> t1 >> t2;
		c1 = t1;
		c2 = t2;
		((c1 > c2) ? c1 : c2).print(); //���ڴ��������ڴ���c1 > c2�У����Զ���c1��c2ת��Ϊ�������бȽ�
	}
	return 0;
}

