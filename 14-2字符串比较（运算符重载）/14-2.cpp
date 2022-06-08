#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Str
{
private:
	char* p;
public:
	Str() { p = NULL; };
	Str(char* s);
	friend bool operator >(Str& s1, Str& s2);
	friend bool operator <(Str&, Str&);
	friend bool operator ==(Str&, Str&);
	void show()
	{
		cout << p << endl;
	}
};
Str::Str(char* s) {
	p = new char[strlen(s) + 1];
	strcpy(p, s);
}

int cmp(char *p1,char *p2) {
	int len = strlen(p1) < strlen(p2) ? strlen(p1) : strlen(p2);
	for (int i = 0; i < len; i++) {
		if (p1[i] != p2[i]) {
			return p1[i] - p2[i];
		}
	}
	return 0;
}


bool operator >(Str& s1, Str& s2) {
	return cmp(s1.p, s2.p) > 0;
}
bool operator <(Str& s1, Str& s2) {
	return cmp(s1.p, s2.p) < 0;
}
bool operator ==(Str& s1, Str& s2) {
	return cmp(s1.p, s2.p) == 0;
}

int main() {
	char a1[50];
	char a2[50];
	char a3[50];
	cin.getline(a1, sizeof(a1));
	cin.getline(a2, sizeof(a2));
	cin.getline(a3, sizeof(a3));

	Str s1(a1);
	Str s2(a2);
	Str s3(a3);

	if (s1 > s2) {
		s1.show();
	}
	else {
		s2.show();
	}

	if (s1 < s3) {
		s1.show();
	}
	else {
		s3.show();
	}

	if (s2 == s3) {
		s2.show();
	}
	else {
		s3.show();
	}
	return 0;
}