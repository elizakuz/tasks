/* float: a - знак
	  b - экспонента
	  c - мантисса
	Kuzmina Elizaveta  */

#include <stdio.h>

int main(){
	unsigned int a, b, c;
	float fval1;
	float fval2;
	struct{
		int type;
		union {
			int ival;
			float fval;
		} val;
	} data;
	scanf("%f", &fval1);
	scanf("%f", &fval2);
	data.val.fval = fval1 / fval2;
	a = data.val.ival;
	a = a & 0x80000000;
	a = !!a;
	b = data.val.ival;
	b = b & 0x7F800000;
	b >>= 23;
	c = data.val.ival;
	c = c & 0x7fffff;
	printf("Знак: %d\n",a);
	printf("Экспонента: %d\n",b);
	float st = 1, r = 0, ch;
	for (int i = 1; i <= 23; i++){
		st = st / 2;
		ch = ((c >> 22) & 1) * st; 
		r = r + ch;
		c = (c & 0x3FFFFF) << 1;
	}
	printf("Мантисса: %f\n",r);
	printf("Результат: ");
	if (a == 0 & b == 0 & c == 0)
	{
		printf("0\n");
	}
	else
	{
		if (b == 255 & r == 0)
		{
			if ( a == 0) printf("+бесконечность\n");
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
			printf("%f", r + 1);
			printf("* 2^%d\n",b);
		}
	}
}
