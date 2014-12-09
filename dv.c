/* Двоичное представление числа. Использование битовых операций.
	Kuzmina Elizaveta */

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int k;
	const b = sizeof(int)*8;
	for (i = 1; i <= b; i++)
	{
		k = (n >> (b - i)) & 1;
		printf("%d", k);
	}
	printf("\n");
}
		 
