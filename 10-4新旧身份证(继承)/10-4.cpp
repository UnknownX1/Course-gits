#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class CDate{
private:
	int year, month, day;
public:
	CDate(int y, int m, int d);
	bool check(); //检验日期是否合法
	bool isLeap();
	void print();
	int get();
};
CDate::CDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
int CDate::get() {
	return year * 10000 + month * 100 + day;
}
bool CDate::isLeap() {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	return false;
}
bool CDate::check() {
	if ( month == 2 && day == 29) {
		if (!isLeap()) {
			return false;
		}
	}
	return true;
}
void CDate::print() {
	cout << year << "年" << month << "月" << day << "日" ;
}

class COldId{
protected:
	char* pId15, * pName; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldId(char* pIdVal, char* pNameVal, CDate& day);
	bool check(); //验证15位身份证是否合法
	void print();
	~COldId();
};
COldId::COldId(char* pIdVal, char* pNameVal, CDate& day):birthday(day) {
	pId15 = new char[strlen(pIdVal) + 1];
	strncpy(pId15, pIdVal, strlen(pIdVal) + 1);
	pName = new char[strlen(pNameVal) + 1];
	strncpy(pName, pNameVal, strlen(pNameVal) + 1);
}
bool COldId::check() {//验证15位身份证是否合法
	return true;
}
COldId::~COldId() {
	delete[] pId15;
	delete[] pName;
}
void COldId::print() {
	cout << pId15;
}

class CNewId : public COldId {
private:
	char* pId18;
	CDate issueDay;
	int validYear;
public:
	bool check();
	void print();
	CNewId(char* pIdVal, char* pNameVal, CDate& day, char* id18, CDate& day2, int years);
	~CNewId();
};
void CNewId::print() {
	cout << pName << endl;
	if (check()) {
		//440301198802281133 2006年1月20日 20年
		cout << pId18 << " ";
		issueDay.print();
		if (validYear == 100) {
			cout << " 长期\n";
		}
		else {
			cout << " " << validYear << "年\n";
		}

	}
	else {
		cout << "illegal id" << endl;
	}
}
CNewId::CNewId(char* pIdVal, char* pNameVal, CDate& day, char* id18, CDate& day2, int years):COldId(pIdVal,pNameVal,day),issueDay(day2) {
	pId18 = new char[strlen(id18)+1];
	strncpy(pId18, id18, strlen(id18) + 1);
	validYear = years;
}
CNewId::~CNewId() {
	delete[] pId18;
}
bool CNewId::check() {
	if (strlen(pId18) != 18) { //长度
		return false;
	}
	for (int i = 0; i < 6; i++) {  //相同
		if (pId15[i] != pId18[i]) {
			return false;
		}
	}
	for (int i = 6; i < 15; i++) {
		if (pId15[i] != pId18[i+2]) {
			return false;
		}
	}
	int yyyy = 0, mm = 0,dd = 0; //日期
	for (int i = 6; i <= 9; i++) { 
		yyyy *= 10;
		yyyy += int(pId18[i] - '0');
	}
	for (int i = 10; i <= 11; i++) {
		mm *= 10;
		mm += int(pId18[i] - '0');
	}
	for (int i = 12; i <= 13; i++) {
		dd *= 10;
		dd += int(pId18[i] - '0');
	}
	int date = yyyy * 10000 + mm * 100 + dd;
	if (date != birthday.get()) {
		return false;
	}
	if (20211108 > issueDay.get() + 200000) {
		return false;
	}
	if (!birthday.check() || !issueDay.check()) {
		return false;
	}

	int cnt = 0;
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char b[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	for (int i = 0; i < 17; i++) {
		cnt += int(pId18[i]-'0') * a[i];
		if (pId18[i] < '0' || pId18[i] > '9') {
			return false;
		}
	}
	if (pId18[17] != b[cnt % 11]){
		return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char* name = new char[10];
		char* id15 = new char[20];
		char* id18 = new char[20];
		int y1, m1, d1, y2, m2, d2, years;
		cin >> name >> y1 >> m1 >> d1 >> id15 >> id18 >> y2 >> m2 >> d2 >> years;
		CDate date1(y1, m1, d1);
		CDate date2(y2, m2, d2);
		CNewId id(id15, name, date1, id18, date2, years);
		id.print();
		delete[]name;
		delete[]id15;
		delete[]id18;
	}



	return 0;
}