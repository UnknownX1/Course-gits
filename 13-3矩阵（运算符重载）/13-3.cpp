#include <iostream>
using namespace std;

// ���������
class CMatrix
{
private:
	int n, m; // n-�У�m-��
	int** data; // �洢��������
public:
	CMatrix();
	CMatrix(int n1, int m1);
	~CMatrix();
	int* operator [](int i);
	int operator ()(int i, int j)const;
	CMatrix& operator= (CMatrix& a);
};
CMatrix& CMatrix::operator= (CMatrix& a) {
	n = a.n;
	m = a.m;
	// ����n��m�еĶ�ά����ռ�
	data = new int* [n];
	for (int i = 0; i < n; i++)
	{
		data[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			data[i][j] = a.data[i][j];
		}
	}
	return *this;
}

int* CMatrix::operator [](int i) {
	return data[i];
}
int CMatrix::operator() (int i, int j) const {
	return data[i][j];
}
CMatrix::CMatrix()
{
}

CMatrix::CMatrix(int n1, int m1)
{
	n = n1;
	m = m1;
	// ����n��m�еĶ�ά����ռ�
	data = new int* [n];
	for (int i = 0; i < n; i++)
	{
		data[i] = new int[m];
	}
}

CMatrix::~CMatrix()
{
	// �ͷſռ�
	for (int i = 0; i < n; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

int main()
{
	int t, n, m, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		// ����������matrixA
		CMatrix matrixA(n, m);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				// �����i�е�j�е�����
				cin >> matrixA[i][j];
			}
		}
		// ���matrixA�е�����
		cout << "matrixA:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << matrixA(i, j) << " ";
			}
			cout << endl;
		}
		// ����������matrixB
		CMatrix matrixB;
		matrixB = matrixA;
		// ���marixB�е�����
		cout << "matrixB:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << matrixB[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}