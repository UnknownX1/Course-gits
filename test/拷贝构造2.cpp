#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student {
	char name[40];
	int id;
public:
	Student(const char* pName = "no name", int ssId = 0) :id(ssId) {
		strcpy(name, pName);
		cout << "Constructing new student " << pName << endl;
	}
	Student(const Student& s) :id(s.id) {          //拷贝构造函数
		cout << "Constructing copy of " << s.name << endl;//标识拷贝构造
		strcpy(name, "copy of "); //name加入标识，析构时区别
		strcat(name, s.name);
	}
	~Student() { cout << "Destructing " << name << endl; }
};
void fn(Student s) { cout << "In function fn()\n"; }
int main05() {
	Student randy("Randy", 1234);
	cout << "Calling fn()\n";
	fn(randy); //实参为对象，结束后，形参析构
	cout << "Returned from fn()\n";
	return 0;
}
