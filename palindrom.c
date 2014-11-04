#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	gets(s);
	int n = strlen(s);
		for (int i = 0; i <= n; i++)
		{
			s[i] = tolower (s[i]);
		}
	int pal = 1;
	for (char *p = s, *q = s + n - 1; p < q; ++p, --q)
	{
		if (*p == 0x20)
		{
			++q;
		}
		else if (*q == 0x20)
		{
			--p;
		}
		else if (*p != *q)
		{
			pal = 0;
			break;
		}
	}
	if (pal == 1)
	{
		printf("палиндром\n");
	}
	else
	{
		printf("не палиндром\n");
	}
}
