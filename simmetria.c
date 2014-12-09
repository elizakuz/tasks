#include <stdio.h>

int main() {
	int n;
	int i;
	int t = 0;
	int arr[100];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 1; i <= n/2; i++)
	{
		if (arr[i] != arr[n-i])
		{
			t = 1;
		}
	}
	t = 0;
	printf("симметричный");
}
