#include "calculator.h"

typedef struct stack{
	long_num a;
	struct stack * next;
} stack;
stack *hd = NULL, *p, *q, *r;
void push(long_num n){
	stack *p = (stack *) malloc(sizeof (stack));
	p->a = n;
	p->next = hd;
	hd = p;		
}
long_num pop(){
	long_num top;
	top = hd->a;
	p = hd;
	hd = hd->next;	
	free(p);
	return top;
}
void stack_clean(){
	while(hd != NULL){
		p = hd;
		hd = hd->next;
		free(p);
	}
}	
		

	
