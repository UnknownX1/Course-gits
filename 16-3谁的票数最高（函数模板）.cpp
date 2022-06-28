#include<iostream>
#include<string>
using namespace std;


template<class T>
void Construct(int n){
	
	struct Cnt{
		public:
			T name;
			int count;
	};
	Cnt *cnt = new Cnt[n];
	int len = 0;
	
	for(int i=0;i<n;i++){
		T x;
		bool has=false;
		cin >> x;
		for(int j=0;j<len;j++){
			if(cnt[j].name==x){
				cnt[j].count++;
				has = true;
				break;
			}
		}
		if(!has){
			cnt[len].name = x;
			cnt[len].count = 1;
			len++;
		}
	}
	int max = 0,maxindex=0;
	for(int i=0;i<len;i++){
		if(cnt[i].count > max){
			max = cnt[i].count;
			maxindex = i;
		}
	}
	
	cout << cnt[maxindex].name << " "<< max << endl;
	delete[] cnt;
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
				Construct<int>(n);
				break;
			}
			case'C':{
				Construct<char>(n);
				break;
			}
			case'S':{
				Construct<string>(n);
				break;
			}
			case'D':{
				Construct<double>(n);
				break;
			}

		}

	} 
	return 0;
}
