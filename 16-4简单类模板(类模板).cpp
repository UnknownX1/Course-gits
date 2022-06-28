#include<iostream>
#include<string>
using namespace std;

template<class T>
class Clist{
	private:
		T *p;
		int len;
	public:
		Clist();
		Clist(T *t,int len);
		void insert(T t, int index);
		void del(int index);
		void print();
		~Clist(){
			delete[]p;
		}
};

template<class T>
Clist<T>::Clist(){
	p = new T[100];
	len = -1;
} 

template<class T>
Clist<T>::Clist(T *t,int n){
	p = new T[100];
	len = -1;
	for(int i=0;i<n;i++){
		p[++len]=t[i];
	}
}

template<class T>
void Clist<T>::insert(T t, int index){
	for(int i=len;i>=index;i--){
		p[i+1]=p[i];
	}
	p[index]=t;
	len++;
}

template<class T>
void Clist<T>::del(int index){
	for(int i=index;i<len;i++){
		p[i]=p[i+1];
	}
	len--;
}

template<class T>
void Clist<T>::print(){
	for(int i=0;i<=len;i++){
		cout << p[i];
		if(i!=len){
			cout << " ";
		}else{
			cout << endl;
		}
	}
}

template<class T>
void op(){
	int n;
	cin >> n;
	T *p = new T[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
	} 
	Clist<T> lst1(p,n);
	
	int index;
	T num;
	cin >> index >> num;
	lst1.insert(num,index);
	
	cin >> index;
	lst1.del(index);
	
	lst1.print();
}

int main(){
	op<int>();
	op<double>();
	
	return 0;
}
