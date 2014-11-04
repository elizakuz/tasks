#include <stdio.h>


int main(){
	int a,n,r=1;
	scanf("%d",&a);
	scanf("%d",&n);
  	while (n){
		if (n & 1) 
           		r=r*a;
		a =a*a;
		n >>= 1;
     	}
  	printf("%d\n", r);
}

