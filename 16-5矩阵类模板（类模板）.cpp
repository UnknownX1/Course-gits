#include<iostream>
#include<string>
using namespace std;

template<class T>
class Matrix{
	private: 
		T **p;
		int m,n;
	public:
		Matrix(int m_,int n_);
		~Matrix();
		void input();
		void transport();
		void print();
};

template<class T>
Matrix<T>::Matrix(int m_,int n_){
	m = m_;
	n = n_;
	
	p = new T*[m];
	for(int i=0;i<m;i++){
		p[i] = new T[n];
	} 
}
template<class T>
Matrix<T>::~Matrix(){
	for(int i=0;i<m;i++){
		delete p[i];
	} 
	delete[]p;
}
template<class T>
void Matrix<T>::input(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> p[i][j];
		}
	}
}	
template<class T>
void Matrix<T>::transport(){
	
	T **tmp =p;
	int temp = m;
	m = n;
	n = temp;
	
	p = new T*[m];
	for(int i=0;i<m;i++){
		p[i] = new T[n];
	} 
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			p[i][j]=tmp[j][i];
		}
	}
	
	for(int i=0;i<n;i++){
		delete tmp[i];
	} 
	delete[]tmp;
	
}
template<class T>	
void Matrix<T>::print(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << p[i][j];
			if(j!=n-1){
				cout << " ";
			}else{
				cout << endl;
			}
		}
	}
}

template<class T>
void Construct(int m,int n){
	Matrix<T> mat(m,n);
	mat.input();
	mat.transport();
	mat.print(); 
}


int main(){
	int t;
	cin >> t;
	while(t--){
		char op;
		int m,n;
		cin >> op >> m >> n;
		switch(op){
			case'I':{
				Construct<int>(m,n);
				break;
			}
			case'C':{
				Construct<char>(m,n);
				break;
			}
			case'D':{
				Construct<double>(m,n);
				break;
			}
		}
	}
	return 0;
}
