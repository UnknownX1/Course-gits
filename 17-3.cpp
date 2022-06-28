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

//ֻ֧���������͵ļ��������
template<class T>
class Cryption
{
private:
	T ptxt[100]; //����
	T ctxt[100]; //����
	T key; //��Կ
	int len; //����
public:
	Cryption(T tk, T tt[], int n); //�������ζ�Ӧ��Կ�����ġ�����
	void encrypt(); //����
	void print() //��ӡ���������
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



//֧���������͵�������
int main()
{
	int i;
	int length; //����
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];
	//��������
	cin >> ik >> length;
	for (i = 0; i < length; i++)
	{
		cin >> itxt[i];
	}
	Cryption<int> ic(ik, itxt, length);
	ic.encrypt();
	ic.print();
	//����������
	cin >> dk >> length;
	for (i = 0; i < length; i++)
	{
		cin >> dtxt[i];
	}
	Cryption<double> dc(dk, dtxt, length);
	dc.encrypt();
	dc.print();
	//�ַ�����
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