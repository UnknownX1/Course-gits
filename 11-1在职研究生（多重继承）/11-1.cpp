#include <iostream>
#include <string>
using namespace std;

class CPeople {
protected:
	string name;
	string sex;
	int age;
public:
	CPeople(string name_, string sex_, int age_);
	void print();
};
CPeople::CPeople(string name_, string sex_, int age_) {
	name = name_;
	sex = sex_;
	age = age_;
}
void CPeople::print() {
	cout << "Name: " << name << endl;
	cout << "Sex: " << sex << endl;
	cout << "Age: " << age << endl;
}

class Cstudent :virtual public CPeople {
protected:
	string stuid;
	float score;
public:
	Cstudent(string name_, string sex_, int age_, string stuid_, float score_);
	void print();
};
Cstudent::Cstudent(string name_, string sex_, int age_, string stuid_, float score_) :CPeople(name_, sex_, age_) {
	stuid = stuid_;
	score = score_;
}
void Cstudent::print() {
	cout << "No.: " << stuid << endl;
	cout << "Score: " << score << endl;
}

class CTeacher :virtual public CPeople {
protected:
	string zhiwu;
	string bumen;
public:
	CTeacher(string name_, string sex_, int age_, string zhiwu_, string bumen_);
	void print();
};
CTeacher::CTeacher(string name_, string sex_, int age_, string zhiwu_, string bumen_) :CPeople(name_, sex_, age_) {
	zhiwu = zhiwu_;
	bumen = bumen_;
}
void CTeacher::print() {
	cout << "Position: " << zhiwu << endl;
	cout << "Department: " << bumen << endl;
}

class CGradOnWork :public Cstudent,public CTeacher {
protected:
	string fangxiang;
	string teacher;
public:
	CGradOnWork(string name_, string sex_, int age_, string stuid_, float score_, string zhiwu_, string bumen_, string fangxiang_, string teacher_);
	void print();
};
CGradOnWork::CGradOnWork(string name_, string sex_, int age_, string stuid_, float score_, string zhiwu_, string bumen_, string fangxiang_, string teacher_) :Cstudent(name_, sex_, age_, stuid_, score_), CTeacher(name_, sex_, age_, zhiwu_, bumen_) {
	fangxiang = fangxiang_;
	teacher = teacher_;
}
void CGradOnWork::print() {
	cout << "Direction: " << fangxiang << endl;
	cout << "Tutor: " << teacher << endl;
}

int main() {
	string name, sex, stuid, zhiwu, bumen, fangxiang, daoshi;
	int age;
	float score;

	cin >> name >> sex >> age;
	cin >> stuid >> score;
	cin >> zhiwu >> bumen;
	cin >> fangxiang >> daoshi;

	CPeople peo(name, sex, age);
	cout <<  "People:\n";
	peo.print();
	cout << endl;

	Cstudent stu(name, sex, age, stuid, score);
	cout << "Student:\n";
	stu.CPeople::print();
	stu.print();
	cout << endl;

	CTeacher tea(name, sex, age, zhiwu,bumen);
	cout << "Teacher:\n";
	tea.CPeople::print();
	tea.print();
	cout << endl;

	CGradOnWork gra(name, sex, age, stuid, score, zhiwu, bumen, fangxiang, daoshi);
	cout << "GradOnWork:\n";
	gra.CPeople::print();
	gra.Cstudent::print();
	gra.CTeacher::print();
	gra.print();

	return 0;
}