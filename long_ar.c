#include <stdio.h>
#include <stdlib.h>
#include "new.h"

long_num long_numCreate() {
	long_num x;
	char c;
	x.digits.head = NULL;
	scanf("%c", &c);
	if (c == '-') { 
		x.sign = -1;
		scanf("%c", &c);
	} else {
		x.sign = 1;
	}
	int_list l;
	l.count = 0;
	l.head = NULL;	
	while (c != '\n') {
		add(c - '0', &l);
		l.count++;
		scanf("%c", &c);
	}
	x.digits = l;
	return x;
}
int_list long_numReverse(int_list x) {
	node_t * r = x.head;
	int i;
	int_list k;
	k.head= NULL;
	for (i = 0; i < x.count; i++) {
		add(r->v, &k);	
		r = r->next;
	}
	x = k;
	return x;
}
long_num long_numAdd(long_num x, long_num y) {
	long_num sum;
	sum.digits.head = NULL;
	int ost = 0;
	int s;
	long_num z;
	if (x.digits.count < y.digits.count) {
		z = x;
		x = y;
		y = z;
	}
	for (y.digits.count; y.digits.count != 0; y.digits.count--, x.digits.count--) {
		s = (x.digits.head->v + y.digits.head->v + ost) % 10;
		ost = (x.digits.head->v + y.digits.head->v + ost) / 10;
		add(s, &sum.digits);
		free(x.digits.head);
		x.digits.head = x.digits.head->next;
		free(y.digits.head);
		y.digits.head = y.digits.head->next;
	}
	for (x.digits.count; x.digits.count != 0; x.digits.count--) {
		s = (x.digits.head->v + ost) % 10;
		add(s, &sum.digits);
		ost = (x.digits.head->v + ost) / 10;
		free(x.digits.head);
		x.digits.head = x.digits.head->next;
	}
	if (ost == 1 ) {
		add(1, &sum.digits);
	}
	sum.sign = x.sign;
	return sum;
}
long_num long_numSub(long_num x, long_num y) {
	long_num sub;
	sub.digits.head = NULL;
	int ost = 0;
	int m;
	long_num z;
	if (x.digits.count < y.digits.count) {
		z = x;
		x = y;
		y = z;
	}
	if (x.digits.count == y.digits.count) {
		int_list x2, y2;
		int i;
		x2 = long_numReverse(x.digits);
		y2 = long_numReverse(y.digits);
		
		for (i = 0; i < x2.count; i++) {
			if (x2.head->v > y2.head->v) {
				break;
			}
			if (x2.head->v < y2.head->v) {
				z = x;
				x = y;
				y = z;
				break;
			}	
			
			free(x2.head);
			x2.head = x2.head->next;
		 	
			free(y2.head);
			y2.head = y2.head->next;
			
		}
	}
	for (y.digits.count; y.digits.count != 0; y.digits.count--, x.digits.count--) {	
		m = x.digits.head->v - y.digits.head->v - ost;
		if (m < 0) {
			ost = 1;
			m += 10;
		} else {
			ost = 0;
		}	
		add(m, &sub.digits);
		free(x.digits.head);
		x.digits.head = x.digits.head->next;
		free(y.digits.head);
		y.digits.head = y.digits.head->next;
	}
	for (x.digits.count; x.digits.count != 0; x.digits.count--) {
		m = x.digits.head->v - ost;
		if (m < 0) {
			ost = 1;
			m += 10;
		} else {
			ost = 0;
		}
		add(m, &sub.digits);
		free(x.digits.head);
		x.digits.head = x.digits.head->next;
	}
	sub.sign = x.sign;
	return sub;	
}
int main(){
	long_num x;
	x = long_numCreate();
	long_num y;
	y = long_numCreate();
	if (x.sign == y.sign) {
		x = long_numAdd(x, y);
	} else {
		x = long_numSub(x, y);
	}
	if (x.sign == -1) {
		printf("-");
	}
	print(x.digits.head);
}	
