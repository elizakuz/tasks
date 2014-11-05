#include <stdio.h>

int main(){
	union{
		float fval;
		struct {
			unsigned int c:23;
			unsigned int b:8;
			unsigned int a:1;
		} data;			
	} val;
	scanf("%f", &val.fval);
	printf("%d\n", val.data.a);
	printf("%d\n", val.data.b);
	printf("%d\n", val.data.c); 
	printf("result: ");
	if (val.data.a == 0 & val.data.b == 0 & val.data.c == 0)
	{
		printf("0\n");
	}
	else
	{
		val.data.b = val.data.b - 127;
		if (val.data.b == 255 & val.data.c == 0)
		{
			printf("беск.");
		}
		else if (val.data.b == 255 & val.data.c != 0)
		{
			printf("Not a Number");
		}
		else 
		{
			if ( val.data.a == 1 ) printf("-");
			printf("1.%d",val.data.c);
			printf("* 2^%d\n",val.data.b);
		}
	}
}
