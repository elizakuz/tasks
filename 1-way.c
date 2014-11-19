/* float: a - знак
	  b - экспонента
	  c - мантисса
	Kuzmina Elizaveta  */

#include <stdio.h>

int main()
{
	float val, val1, val2;
	scanf("%e", &val1);
	scanf("%e", &val2);
	val = val1 / val2;
	int ival, a, b, c;
	ival = *((int *)((void *) &val));
	a = ival;
	a = a & 0x80000000;
	a = !!a;
	b = ival;
	b = b & 0x7F800000;
	b >>= 23;
	c = ival;
	c = c & 0x7FFFFF;
	printf("Знак: %d\n",a);
	printf("Экспонента: %d\n",b);
	float st = 1, r = 0, ch;
	for (int i = 1; i <= 23; i++){
		st = st / 2;
		ch = ((c >> 22) & 1) * st; 
		r = r + ch;
		c = (c & 0x3FFFFF) << 1;
	}
	printf("Мантисса: %f\n", r);
	printf("Результат: ");
	if (a == 0 & b == 0 & c == 0)
	{
		printf("0\n");
	}
	else
	{
		if (b == 255 & r == 0)
		{
			if (a == 0) printf("+бесконечность\n");
			else printf("-бесконечность\n");
		}
		else if (b == 255 & r != 0)
		{
			printf("Not a Number\n");
		}
		else 
		{
			b = b - 127;
			if ( a == 1 ) printf("-");
			printf("%f",r + 1);
			printf("* 2^%d\n",b);
			//Привет, Лизок! ;)
		}
	}
}
