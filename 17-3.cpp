#include <iostream>
#include <cstring>
using namespace std;

template<class T>
T max(T* t, int n) {
	T m = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] > m) {
			m = t[i];
		}
	}
	return m;
}

//只支持整数类型的加密类界面
template<class T>
class Cryption
{
private:
	T ptxt[100]; //明文
	T ctxt[100]; //密文
	T key; //密钥
	int len; //长度
public:
	Cryption(T tk, T tt[], int n); //参数依次对应密钥、明文、长度
	void encrypt(); //加密
	void print() //打印，无需改造
	{
		int i;
		for (i = 0; i < len - 1; i++)
		{
			cout << ctxt[i] << " ";
		}
		cout << ctxt[i] << endl;
	}
};

template<class T>
Cryption<T>::Cryption(T tk, T tt[], int n) {
	len = n;
	memcpy(ptxt, tt, sizeof(T) * len);
	key = tk;
	memset(ctxt, '\0', sizeof(ctxt));
}

template<class T>
void Cryption<T>::encrypt() {
	T maxValue = max(ptxt, len);
	for (int i = 0; i < len; i++) {
		ctxt[i] = maxValue - ptxt[i];
		ctxt[i] += key;
	}
}



//支持三种类型的主函数
int main()
{
	int i;
	int length; //长度
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];
	//整数加密
	cin >> ik >> length;
	for (i = 0; i < length; i++)
	{
		cin >> itxt[i];
	}
	Cryption<int> ic(ik, itxt, length);
	ic.encrypt();
	ic.print();
	//浮点数加密
	cin >> dk >> length;
	for (i = 0; i < length; i++)
	{
		cin >> dtxt[i];
	}
	Cryption<double> dc(dk, dtxt, length);
	dc.encrypt();
	dc.print();
	//字符加密
	cin >> ck >> length;
	for (i = 0; i < length; i++)
	{
		cin >> ctxt[i];
	}
	Cryption<char> cc(ck, ctxt, length);
	cc.encrypt();
	cc.print();

	return 0;
}