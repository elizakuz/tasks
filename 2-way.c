#include <stdio.h>

int main(){
	unsigned int a, b, c;
	struct{
		int type;
		union {
			int ival;
			float fval;
		} val;
	} data;
	scanf("%f", &data.val.fval);
	a = data.val.ival;
	a >>= 31;
	b = data.val.ival;
	b <<= 1;
	b >>= 24;
	c = data.val.ival;
	c <<= 9;
	c >>= 9;
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
		b = b - 127;
		if (b == 255 & c == 0)
		{
			printf("беск.");
		}
		else if (b == 255 & c != 0)
		{
			printf("Not a Number");
		}
		else 
		{
			if ( a == 1 ) printf("-");
			printf("1.%d",c);
			printf("* 2^%d\n",b);
		}
	}
}
