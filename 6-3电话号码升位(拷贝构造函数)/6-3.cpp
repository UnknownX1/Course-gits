#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class CTelNumber {
private:
	char* s;
public:
	CTelNumber(char* p);
	CTelNumber(const CTelNumber& p);
	void Print();
	~CTelNumber();
};

CTelNumber::CTelNumber(char *p) {
	s = new char[strlen(p) + 1];
	strcpy(s, p);
}

CTelNumber::CTelNumber(const CTelNumber &p) {
	s = new char[9];
	if (p.s[0] == '2' || p.s[0] == '3' || p.s[0] == '4') {
		s[0] = '8';
	}
	else {
		s[0] = '2';
	}
	for (int i = 0; i < 8; i++) {
		s[i + 1] = p.s[i];
	}
}

void CTelNumber::Print() {
	cout << s << endl;
}

CTelNumber::~CTelNumber() {
	delete[] s;
}

int islegal(char *p) {
	int len = strlen(p);
	if (len != 7) {
		return 0;
	}
	if (p[0] == '0' || p[0] == '1' || p[0] == '9') {
		return 0;
	}
	for (int i = 0; i < 7; i++) {
		if (p[i] < '0' || p[i] > '9') {
			return 0;
		}
	}
	return 1;
 }

int main() {
	int t;
	cin >> t;
	while (t--) {
		char tel[20];
		cin >> tel;
		if (islegal(tel)) {
			CTelNumber ctel(tel);
			CTelNumber ctel2(ctel);
			ctel2.Print();
		}
		else {
			cout << "Illegal phone number" << endl;
		}
	}
	return 0;
}