#include <iostream>
#include <cstring>
using namespace std;

class furn {
protected:
	int id;
	int power;
public:
	furn(int id_, int power_)
	{
		id = id_;
		power = power_;
	}
	furn(){}
	virtual void print() = 0;
};

class fengshan :virtual public furn {
protected:
	int fx;
	int fl;
public:
	fengshan(int id_, int power_, int fx_, int fl_) :furn(id_, power_)
	{
		fx = fx_;
		fl = fl_;
	}
	void fxcontrol(int n) {
		fx = n;
	}
	void flcontrol(int n) {
		fl = n;
	}
};

class jaishiqi :virtual public furn {
protected:
	float nowV;
	float maxV;
public:
	jaishiqi(int id_, int power_, float nowV_, float maxV_) :furn(id_, power_)
	{
		nowV = nowV_;
		maxV = maxV_;
	}
	int yujin();
};
int jaishiqi::yujin() {
	if (nowV > 0.5 * maxV) {
		return 1;
	}
	else if (nowV > 0.1 * maxV) {
		return 2;
	}
	else {
		return 3;
	}
}

class jiashifengshan :public fengshan, public jaishiqi {
	int dw;
public:
	jiashifengshan(int id_, int power_, int fx_, int fl_, float nowV_, float maxV_, int dw_) :fengshan(id_, power_, fx_, fl_), jaishiqi(id_, power_, nowV_, maxV_),furn(id_,power_) {
		dw = dw_;
	}
	void changedw(int n);
	void print();
};
void jiashifengshan::changedw(int n) {
	dw = n;
	switch (n)
	{
	case 1: {
		fxcontrol(0);
		flcontrol(1);
		break;
	}
	case 2: {
		fxcontrol(1);
		flcontrol(2);
		break;
	}
	case 3: {
		fxcontrol(1);
		flcontrol(3);
		break;
	}
	}
}
void jiashifengshan::print() {
	cout << "加湿风扇--档位" << dw << endl;
	cout << "编号" << id << "--功率" << power << "W\n";
	if (fx) {
		cout << "旋转";
	}
	else {
		cout << "定向";
	}
	cout << "吹风--风力" << fl << "级\n";
	cout << "实际水容量" << nowV << "升--水量";
	int res = yujin();
	if (res == 1) {
		cout << "正常";
	}
	else if (res == 2) {
		cout << "偏低";
	}
	else {
		cout << "不足";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int id, power, fx, fl, dw;
		float shiji, zuida;
		cin >> id >> power >> fx >> fl >> shiji >> zuida >> dw;
		jiashifengshan fs(id, power, fx, fl, shiji, zuida, dw);
		int x;
		cin >> x;
		fs.changedw(x);
		fs.print();
	}
	return 0;
}