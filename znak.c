/* Знак целого числа (-1, 0, 1). Без логических операций.
	Kuzmina Elizaveta */

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	n = (n >> 31) | !(!n);
	printf("%d\n", n);
}
