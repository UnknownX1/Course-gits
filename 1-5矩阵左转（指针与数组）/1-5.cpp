#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a[2][3];
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		int *pa=a[0];
		cout<<*(pa+2)<<' '<<*(pa+5)<<' '<<endl;
		cout<<*(pa+1)<<' '<<*(pa+4)<<' '<<endl;
		cout<<*(pa+0)<<' '<<*(pa+3)<<' '<<endl;
	
	}
	return 0;
}
