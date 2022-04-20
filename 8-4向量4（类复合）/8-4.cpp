#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class CVector {
private:
	int* data;
	int n;
public:
	CVector();
	CVector(int n1, int a[]);
	CVector(const CVector& v);
	void Print();
	~CVector();
	float Average();
};

CVector::CVector() {
	n = 5;
	data = new int[5]{ 0,1,2,3,4 };
}
CVector::CVector(int n1, int a[]) {
	n = n1;
	data = new int[n1];
	memcpy(data, a, n1 * sizeof(int));
}
CVector::CVector(const CVector& v) {
	n = v.n;
	data = new int[v.n];
	memcpy(data, v.data, v.n * sizeof(int));
}
void CVector::Print() {
	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
}
float CVector::Average() {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += data[i];
	}
	return sum / n;
}
CVector::~CVector() {
	delete[] data;
}

class CStudent {
private:
	string name;  // ÐÕÃû
	CVector score;  // n¸ö³É¼¨
public:
	CStudent(string name1, int n1, int a1[]);
	void Print();
};
CStudent::CStudent(string name1, int n1, int a1[]) :score(n1, a1) {
	name = name1;
}
void CStudent::Print() {
	cout << name << " ";
	score.Print();
	cout << fixed << setprecision(2) << score.Average() << endl;
}

int main() {
	string name;
	while (cin >> name) {
		
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		CStudent stu(name, n, a);
		stu.Print();
		delete[] a;
	}
	return 0;
}