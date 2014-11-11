/* Может ли целое число быть представлено на машине с k-разрядным словом и дополнительным кодом. Без логических операций.
1 - может 
0 - нет
	Kuzmina Elizaveta */

#include <stdio.h>

int main(){
	int n, n_p, n_m;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);	
        n_p = n & ~(n >> 31);
	n_m = ~(n - 1) & (n >> 31);
	n = (n_p | n_m) >> (k - 1);
	printf("%d\n", !n);
}
