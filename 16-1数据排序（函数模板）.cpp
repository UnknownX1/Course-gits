#include<iostream>
#include<string>
using namespace std;

template<class T>
void input(T *t,int n){
	for(int i=0;i<n;i++){
		cin >> t[i];
	}
}
template<class T>
void output(T *t,int n){
	for(int i=0;i<n;i++){
		cout << t[i] << " ";
	}
	cout << endl;
}
template<class T>
void swap(T *t1,T *t2){
	T tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}
template<class T>
void sort(T *t,int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(t[j]>t[j+1]){
				swap(t[j],t[j+1]);
			}
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		char op;
		int n;
		cin >> op >> n;
		switch(op){
			case'I':{
				int *p = new int[n];
				input(p,n);
				sort(p,n);
				output(p,n);
				delete[]p;
				break;
			}
			case'C':{
				char *p = new char[n];
				input(p,n);
				sort(p,n);
				output(p,n);
				delete[]p;
				break;
			}
			case'S':{
				string *p = new string[n];
				input(p,n);
				sort(p,n);
				output(p,n);
				delete[]p;
				break;
			}
			case'D':{
				double *p = new double[n];
				input(p,n);
				sort(p,n);
				output(p,n);
				delete[]p;
				break;
			}

		}
		
	}
	return 0;
}
