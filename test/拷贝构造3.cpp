#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student {
	char name[40];
public:
	Student(const char* pName = "no name") {  //�޲λ�һ�ι��캯��
		cout << "Constructing new student " << pName << endl;
		strcpy(name, pName);
	}
	Student(const Student& s) {       //�������캯��
		cout << "Constructing copy of " << s.name << endl;
		strcpy(name, "copy of ");
		strcat(name, s.name);
	}
	~Student()
	{
		cout << "Destructing " << name << endl;
	}
};
class Tutor { //δ���忽�����캯��,��ϵͳĬ��һ��(ǳ����)�������ó�Ա�Ŀ�������
	Student student;
public:
	Tutor(Student& s) :student(s)
	{
		cout << "Constructing tutor\n";
	}
};
void fn(Tutor t) { cout << "In function fn()\n"; }
int main() {
	Student randy("Randy");  //����Student���캯��
	Tutor tutor(randy);  //��ӡ��name��copy of
	cout << "Calling fn()\n";
	fn(tutor);               //����Tutor�������캯��������������t
	cout << "Returned from fn()\n";
	return 0;
}//������tutor��������randy

