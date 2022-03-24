#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c;
		int *pa=&a,*pb=&b,*pc=&c;
		int temp;
		scanf("%d%d%d",&a,&b,&c);
		for(int j=0;j<2;j++){
			if(a<b){
				temp=*pb;
				*pb=*pa;
				*pa=temp;
			}
			if(b<c){
				temp=*pc;
				*pc=*pb;
				*pb=temp;
			}
		}
		printf("%d %d %d\n",*pa,*pb,*pc);
	}
	return 0;
} 
