#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
private:
	float height, weight, length;
	string name;
public:
	double bmi();
	double tizhi();
	void set(string& na, float& hei, float& wei, float& len);
	string getName();
};

double Person::bmi()
{
	return weight / height / height;
}

double Person::tizhi()
{
	double a = length * 0.74;
	double b = weight * 0.082 + 34.89;
	return (a - b) / weight;
}

void Person::set(string &na, float &hei, float &wei, float &len)
{
	name = na;
	height = hei;
	weight = wei;
	length = len;
}

string Person::getName()
{
	return name;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		float hei, wei, len;
		cin >> name >> hei >> wei >> len;
		Person per;
		per.set(name, hei, wei, len);
		cout << per.getName() << "的BMI指数为" << fixed << setprecision(0) << per.bmi() << "--体脂率为" << fixed << setprecision(2) << per.tizhi() << endl;
	}
	return 0;
}