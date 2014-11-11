/* float: a - знак
	  b - экспонента
	  c - мантисса
	Kuzmina Elizaveta  */

#include <stdio.h>

int main()
{
	int* p;
	float val, val1, val2;
	scanf("%e", &val1);
	scanf("%e", &val2);
	val = val1 / val2;
	int ival, a, b, c;
	ival = *((int *)((void *) &val));
	a = ival;
	a = a & 0x10000000;
	b = ival;
	b = b & 0x7F800000;
	b >>= 23;
	c = ival;
	c = c & 0x7FFFFF;
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("result: ");
	if (a == 0 & b == 0 & c == 0)
	{
		printf("0\n");
	}
	else
	{
		if (b == 255 & c == 0)
		{
			printf("беск.\n");
		}
		else if (b == 255 & c != 0)
		{
			printf("Not a Number\n");
		}
		else 
		{
			b = b - 127;
			if ( a == 1 ) printf("-");
			printf("1.%d",c);
			printf("* 2^%d\n",b);
		}
	}
}
