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
	b = data.val.ival;
	b = b & 0x7f800000;
	b >>= 23;
	c = data.val.ival;
	c = c & 0x7fffff;
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
