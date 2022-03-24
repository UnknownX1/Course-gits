#include <iostream>
#include <string>
using namespace std;

class Students
{
private:
	string name;
	string num;
	string xueyuan;
	string phone;
	string sex;
public:
	void SetName(string n);
	void SetNum(string n);
	void SetSex(string n);
	void SetXueyuan(string n);
	void SetPhone(string n);
	void GetName();
};

void Students::SetName(string n)
{
	name = n;
}

void Students::SetNum(string n)
{
	num = n;
}

void Students::SetXueyuan(string n)
{
	xueyuan = n;
}

void Students::SetPhone(string n)
{
	phone = n;
}

void Students::SetSex(string n)
{
	sex = n;
}
void Students::GetName()
{
	cout << name << endl;
}

int main()
{
	int n;
	cin >> n;
	Students* Stu = new Students[n];
	for (int i = 0; i < n; i++)
	{
		string name, num, sex, xueyuan, phone;
		cin >> name >> num >> sex >> xueyuan >> phone;
		Stu[i].SetName(name);
		Stu[i].SetNum(num);
		Stu[i].SetSex(sex);
		Stu[i].SetXueyuan(xueyuan);
		Stu[i].SetPhone(phone);
	}
	for (int i = 0; i < n; i++)
	{
		Stu[i].GetName();
	}
	return 0;
}