#include <iostream>
using namespace std;

class CStack {
private:
	int* a;
	int size;
	int top;
public:
	CStack();
	CStack(int s);
	CStack(CStack& r_s);
	int get(int index);
	void push(int n);
	int isEmpty();
	int isFull();
	int pop();
	~CStack();
};

CStack::CStack() {
	a = new int[10];
	top = 0;
	size = 10;
	cout << "Constructor." << endl;
}

CStack::CStack(int s) {
	a = new int[s];
	top = 0;
	size = s;
	cout << "Constructor." << endl;
}

CStack::CStack(CStack& r_s) {
	a = new int[r_s.size];
	top = 0;
	size = r_s.size;
	cout << "Constructor." << endl;
}

int CStack::get(int index) {
	return a[index];
}

void CStack::push(int n) {
	a[top] = n;
	top++;
}

int CStack::isEmpty() {
	return top == 0;
}

int CStack::isFull() {
	return top == size;
}

int CStack::pop() {
	top--;
	int temp = a[top];
	return temp;
}

CStack::~CStack() {
	delete[]a;
	cout << "Destructor." << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int len;
		cin >> len;
		CStack stack(len);
		for (int i = 0; i < len; i++) {
			int x;
			cin >> x;
			stack.push(x);
		}
		for (int i = 0; i < len; i++) {
			cout << stack.pop();
			if (i == len - 1) {
				cout << endl;
			}
			else {
				cout << " ";
			}
		}
	}
	return 0;
}