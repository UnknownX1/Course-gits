#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Body
{
public:
	Body(string name_,float h,float w,float l);
	int getBmi() {
		return weight / (height * height)+0.5;
	}
	double getTizhi();
	void show();
private:
	string name;
	float height, weight, length;
};
double Body::getTizhi() {
	double a = length * 0.74;
	double b = weight * 0.082 + 34.89;
	return (a - b) / weight;
}
void Body::show() {
	cout << name<< "的BMI指数为" << getBmi() << "--体脂率为" << fixed << setprecision(2) << getTizhi() << endl;
}
Body::Body(string name_,float h,float w,float l)
{
	name = name_;
	height = h;
	weight = w;
	length = l;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string name;
		float height, weight, length;
		cin >> name >> height >> weight >> length;
		Body b(name, height, weight, length);
		b.show();
	}
	return 0;
}