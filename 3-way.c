/* float: a - знак
	  b - экспонента
	  c - мантисса
	Kuzmina Elizaveta  */

#include <stdio.h>

int main(){
	float fval1;
	float fval2;
	union{
		float fval;
		struct {
			unsigned int c:23;
			unsigned int b:8;
			unsigned int a:1;
		} data;			
	} val;
	scanf("%f", &fval1);
	scanf("%f", &fval2);
	val.fval = fval1 / fval2;
	printf("Знак: %d\n", val.data.a);
	printf("Экспонента: %d\n", val.data.b);
	float st = 1, r = 0, ch;
	for (int i = 1; i <= 23; i++){
		st = st / 2;
		ch = ((val.data.c >> 22) & 1) * st; 
		r = r + ch;
		val.data.c = (val.data.c & 0x3FFFFF) << 1;
	}
	//printf("%d\n", val.data.c);
	printf("Мантисса: %f\n", r); 
	printf("Результат: ");
	if (val.data.a == 0 & val.data.b == 0 & r == 0)
	{
		printf("0\n");
	}
	else
	{
		if (val.data.b == 255 & r == 0)
		{
			if (val.data.a == 0) printf("+бесконечность\n");
			else printf("-бесконечность\n");
		}
		else if (val.data.b == 255 & r != 0)
		{
			printf("Not a Number\n");
		}
		else 
		{
			if ( val.data.a == 1 ) printf("-");
			printf("%f",r + 1);
			printf("* 2^(%d - 127)\n", val.data.b);
		}
	}
}
