#include <stdio.h>

int main(){
	int a[100], r, i, n;
	r=0;
	scanf("%d",&n);
	for(i=1;i<=n; i++){
		scanf("%d", &a[i]);
		r=r+!a[i];
	}
	printf("%d\n", r);
}
