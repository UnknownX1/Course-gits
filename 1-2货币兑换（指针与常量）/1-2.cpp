#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char ch;
		double x,a,*hl=&a;
		getchar();
		scanf("%c %lf",&ch,&x);
		
		switch(ch){
			case 'D':*hl=6.2619;break;
			case 'E':*hl=6.6744;break;
			case 'Y':*hl=0.0516;break;
			case 'H':*hl=0.8065;break;
		}
		printf("%.4f\n",x*(*hl));
	}
	return 0;
} 
