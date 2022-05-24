#include <iostream>
using namespace std;

class Robot {
private:
	string name;
	int blood;
	int hurt;
	int defend;
	char type;
	int level;
public:
	Robot(string na, char ty, int le);
	void setRobot();
	void Print();
	char GetType();
	void SetType(char ty);
};

void Robot::setRobot() {
	blood = hurt = defend = 5 * level;
	if (type == 'A') {
		hurt = 10 * level;
	}
	else if (type == 'D') {
		defend = 10 * level;
	}
	else if (type == 'H') {
		blood = 50 * level;
	}
}

void Robot::Print() {
	//X001--H--5--250--25--25\n
	cout << name << "--" << type << "--" << level << "--" << blood << "--" << hurt << "--" << defend << endl;

}
Robot::Robot(string na, char ty, int le) {
	name = na;
	type = ty;
	level = le;
	setRobot();
}
char Robot::GetType() {
	return type;
}
void Robot::SetType(char ty) {
	type = ty;
}

bool ChangeType(Robot& r, char ty) {
	if (r.GetType() != ty) {
		r.SetType(ty);
		r.setRobot();
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int t;
	cin >> t;
	int cnt = 0;
	while (t--) {
		string name;
		char type1, type2;
		int level;
		cin >> name >> type1 >> level;
		Robot r(name, type1, level);
		cin >> type2;
		if (ChangeType(r, type2)) {
			cnt++;
		}
		r.Print();
	}
	cout << "The number of robot transform is " << cnt << endl;
	return 0;
}