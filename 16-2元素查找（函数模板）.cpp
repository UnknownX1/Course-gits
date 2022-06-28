#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template<class T>
void input(T *t,int n){
	for(int i=0;i<n;i++){
		cin >> t[i];
	}
}
template<class T1,class T2>
int find(T1 *t,int n,T2 key){
	for(int i=0;i<n;i++){
		if(t[i]==key){
			return i+1;
		}
	}
	return 0;
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
				int key;
				cin >> key;
				cout << find(p,n,key) << endl;
				delete[]p;
				break;
			}
			case'C':{
				char *p = new char[n];
				input(p,n);
				char key;
				cin >> key;
				
				cout << find(p,n,key) << endl;
				delete[]p;
				break;
			}
			case'S':{
				string *p = new string[n];
				input(p,n);
				string key;
				cin >> key;
				
				cout << find(p,n,key) << endl;
				delete[]p;
				break;
			}
			case'D':{
				double *p = new double[n];
				input(p,n);
				double key;
				cin >> key;
				
				cout << find(p,n,key) << endl;
				delete[]p;
				break;
			}

		}
		
	}
	return 0;
}
