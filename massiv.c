#include <stdio.h>
#include <string.h>

int main(){
	int a[100];
	int r = 0;
	int i;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		r = r + !a[i];
	}
	printf("%d\n", r);
}
