/* Двоичное представление числа. Использование битовых операций.
	Kuzmina Elizaveta */

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int k;
	for (i = 1; i <= 32; i++)
	{
		k = (n >> (32 - i)) & 1;
		printf("%d", k);
	}
	printf("\n");
}
		 
