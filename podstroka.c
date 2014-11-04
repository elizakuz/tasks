#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	char p[100];
	gets (s);
	gets (p);
	int n1 = strlen(s);
	int n2 = strlen(p);
	int i;
	int j;
	int r = 0;
	for (i = 0; i <= n1; i++)
	{
		s[i] = tolower (s[i]);
	}
	for (j = 0; j <= (n1 - n2); j++)
	{
		int k = 0;
		for (i = 0; i < n2; i++)
		{
			if (s[j + i] != p[i])
			{
				k = 1;
			}
		}
		if (k == 0)
		{
			r++;
		}
	}
	printf("%d\n", r);
}
