#include <iostream>
#include <string.h>
using namespace std;

struct students {
	char sjmc[30];
	char zdh[30];
	char czy[30];
	char fkf[30];
	char yxq[30];
	char kh[30];
	char jysj[30];
	char xfje[30];
};

int main() {
	int t;
	cin >> t;
	struct students* stu = new struct students[t];
	for (int i = 0; i < t; i++) {
		cin >> stu[i].sjmc >> stu[i].zdh >> stu[i].czy >> stu[i].fkf >> stu[i].yxq >> stu[i].kh >> stu[i].jysj>> stu[i].xfje;
	}
	for (int i = 0; i < t; i++) {
		for (int j = 4; j < strlen(stu[i].kh)-4; j++) {
			stu[i].kh[j] = '*';
		}
		cout << "Name: " << stu[i].sjmc << endl;
		cout << "Terminal: " << stu[i].zdh <<" operator: "<< stu[i].czy << endl;
		cout << "Card Issuers: " << stu[i].fkf << " Validity: " << stu[i].yxq << endl;
		cout << "CardNumber: " << stu[i].kh << endl;
		cout << "Traded: " << stu[i].jysj << endl;
		cout << "Costs: $" << stu[i].xfje << endl;
		cout << endl;
	}
	return 0;
}