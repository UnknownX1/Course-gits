#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student {
	char name[40];
public:
	Student(const char* pName = "no name") {  //无参或一参构造函数
		cout << "Constructing new student " << pName << endl;
		strcpy(name, pName);
	}
	Student(const Student& s) {       //拷贝构造函数
		cout << "Constructing copy of " << s.name << endl;
		strcpy(name, "copy of ");
		strcat(name, s.name);
	}
	~Student()
	{
		cout << "Destructing " << name << endl;
	}
};
class Tutor { //未定义拷贝构造函数,则系统默认一个(浅拷贝)，并调用成员的拷贝构造
	Student student;
public:
	Tutor(Student& s) :student(s)
	{
		cout << "Constructing tutor\n";
	}
};
void fn(Tutor t) { cout << "In function fn()\n"; }
int main() {
	Student randy("Randy");  //调用Student构造函数
	Tutor tutor(randy);  //打印后，name加copy of
	cout << "Calling fn()\n";
	fn(tutor);               //调用Tutor拷贝构造函数，结束后析构t
	cout << "Returned from fn()\n";
	return 0;
}//先析构tutor，再析构randy

