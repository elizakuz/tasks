#include <stdio.h>

int main(){
	int n,i,r,r1,r2;
	scanf("%d",&n);
	r=2;
	r1=1;
	if (n==1) r=1;
	if (n>2){
		for(i=3; i<=n; i++){
			r2=r;
			r=r+r1;
			r1=r2;
		}
	}
	printf("%d\n",r);
}
