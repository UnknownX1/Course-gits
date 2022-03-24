#include <iostream>
using namespace std;

struct students {
	int year;
	int month;
	int day;
	int date;
};


int main() {
	int t;
	cin >> t;
	struct students *stu=new struct students[t];
	for (int i = 0; i < t; i++) {
		cin >> stu[i].year >> stu[i].month >> stu[i].day;
		stu[i].date = stu[i].year * 10000 + stu[i].month * 100 + stu[i].day;
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < t - i;j++) {
			if (stu[j].date > stu[j + 1].date) {
				struct students temp;
				temp = stu[j + 1];
				stu[j + 1] = stu[j];
				stu[j] = temp;
			}
		}
	}
	cout << stu[1].year << '-' << stu[1].month << '-' << stu[1].day<<endl;
	return 0;
}