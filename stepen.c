/* возведение в степень
	Kuzmina Elizaveta */
#include <stdio.h>

int main(){
	int a;
	int n;
	int r = 1;
	printf("Введите основание\n");
	scanf("%d",&a);
	printf("Введите показатель\n");
	scanf("%d",&n);
	while (n)
	{
		if (n & 1)
		{
			r = r * a;
		}
		a = a * a;
		n >>= 1;
	}
	printf("Ответ: %d\n", r);
}
