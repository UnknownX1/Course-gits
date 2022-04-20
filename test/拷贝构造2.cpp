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
	Student(const Student& s) :id(s.id) {          //�������캯��
		cout << "Constructing copy of " << s.name << endl;//��ʶ��������
		strcpy(name, "copy of "); //name�����ʶ������ʱ����
		strcat(name, s.name);
	}
	~Student() { cout << "Destructing " << name << endl; }
};
void fn(Student s) { cout << "In function fn()\n"; }
int main05() {
	Student randy("Randy", 1234);
	cout << "Calling fn()\n";
	fn(randy); //ʵ��Ϊ���󣬽������β�����
	cout << "Returned from fn()\n";
	return 0;
}
