#include <stdio.h>
#include <math.h>

int main(){
	int n;
	int i;
	int r;
	int t = 0;
	int j;
	double k;
	scanf("%d", &n);
	r = 1;
	if (n != 2)
	{
		for (i = 3; i <= n; i++)
		{
			k = sqrt(i);
			for (j = 2; j <= round(k); j++)
			{
				if(i % j == 0)
				{
					t = 1;
				}
			}
			if (t == 0)
			{
				r = r + 1;
			}
			t = 0;
		}
	}
	printf("%d\n", r);
}
