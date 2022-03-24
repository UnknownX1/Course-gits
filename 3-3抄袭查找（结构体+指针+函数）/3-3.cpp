#include <iostream>
using namespace std;

struct students {
	int num;
	char t1[100];
	char t2[100];
	char t3[100];
};

int tcomp(char *ta,char *tb) {
	int length = 0, same = 0;
	while (ta[length] != '\0' && tb[length] != '\0') {
		if (ta[length] == tb[length]) {
			same++;
		}
		length++;
	}
	if (same >= length * 0.9) {
		return 1;
	}
	return 0;
}

int stucomp(struct students* stua, struct students* stub) {
	if (tcomp(stua->t1, stub->t1)) {
		cout << stua->num << ' ' << stub->num << " 1" << endl;
		return 1;
	}
	else if(tcomp(stua->t2, stub->t2)) {
		cout << stua->num << ' ' << stub->num << " 2" << endl;
		return 1;
	}
	else if (tcomp(stua->t3, stub->t3)) {
		cout << stua->num << ' ' << stub->num << " 3" << endl;
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int t;
	cin >> t;
	struct students* stu = new struct students[t];
	for (int i = 0; i < t; i++) {
		cin >> stu[i].num >> stu[i].t1 >> stu[i].t2 >> stu[i].t3;
	}
	for (int i = 0; i < t-1; i++) {
		for (int j = i+1; j < t; j++) {
			stucomp(&stu[i], &stu[j]);
		}
	}
	delete[]stu;
	return 0;
}