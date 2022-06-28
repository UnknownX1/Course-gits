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

	cout << year << "年" << setw(2) << setfill('0') << month << "月" << setw(2) << setfill('0') << day<< "日\n";
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
		((c1 > c2) ? c1 : c2).print(); //日期大的输出，在代码c1 > c2中，会自动把c1和c2转换为整数进行比较
	}
	return 0;
}

