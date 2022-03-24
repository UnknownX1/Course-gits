#include<iostream>
using namespace std;
void swap(int* x, int* y);
int main01(void)
{
	int a = 10, b = 20;
	swap(&a, &b);
	cout << a << " " << b << endl;
	system("pause");
	return 0;
}

void swap(int* x, int* y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;

}