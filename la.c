#include <stdio.h>
#include <stdlib.h>
#include "la.h"
 

node_t x, y;
node_t * hd1 = &x;
node_t * hd2 = &y;
node_t * hd;
long_num long_numRead(node_t * hd) {
	int k;
	scanf("%d", &k);
	while (k != 0) {
		add(k, hd);
		printf("%d---@@@@@@@@@@@@\n", k);
		scanf("%d", &k);
	}
}
long_num long_numAdd(node_t x, node_t y){
	while((&x != NULL) && (&y != NULL)){
		int ost = 0;
		int sum = hd1->v + hd2->v;
		if (hd1->v + hd2->v > 10){
			sum = sum - 10;
			ost = 1;
		}
		add(sum + ost, hd);
	} 
	if((hd1 = NULL) && (hd2 != NULL)){
		add(hd2->v, hd);
	} else {
		if((hd2 = NULL) && (hd1 != NULL)){
			add(hd2->v, hd);
		}
	}
}
int main(){ 
	long_numRead(&y);
}

