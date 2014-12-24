#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
	
int main(){
	char s;
	long_num new;
	long_num el1, el2;
	int x = 1;
	scanf("%c", &s);
	while(x){
		switch(s) {
			case '0'...'9': new = long_numCreate(s);
				new.digits = long_numReverse(new.digits);
				push(new); 
				break;
			case '+':
				if((hd != NULL) & (hd->next != NULL)){
					el1 = pop();
					el2 = pop();
					el1.digits = long_numReverse(el1.digits);
					el2.digits = long_numReverse(el2.digits);
					if (el1.sign == el2.sign){
						new = long_numAdd(el1, el2);
					} else {
						new = long_numDiv(el1, el2);
					}
					push(new);
				} else {
					printf("Not enough arguments\n");
					x = 0;
				}
				break;
			case '-': scanf("%c", &s);
				if (s == '\n'){
					if((hd != NULL) & (hd->next != NULL)){
						el1 = pop();
						el2 = pop();
						el1.digits = long_numReverse(el1.digits);
						el2.digits = long_numReverse(el2.digits);
						if (el1.sign == el2.sign){
							new = long_numSub(el1, el2);
						} else {
							new = long_numAdd(el1, el2);
						}	
						push(new);
					} else {	
						printf("Not enough arguments\n");
						stack_clean();
						x = 0;
					}
				} else {
					new = long_numCreate(s);
					new.sign = -1;
					new.digits = long_numReverse(new.digits);
					push(new); 
				} 
				break;
			case '*':
				if((hd != NULL) & (hd->next != NULL)){
					el1 = pop();
					el2 = pop();
					el1.digits = long_numReverse(el1.digits);
					el2.digits = long_numReverse(el2.digits);
					new = long_numMult(el1, el2);
					push(new);
				} else {
					printf("Not enough arguments\n");
				}
				break;
			case '/':
				if((hd != NULL) & (hd->next != NULL)){
					if(hd->next->a.digits.head->v != 0){
						el1 = pop();
						el2 = pop();
						el1.digits = long_numReverse(el1.digits);
						el2.digits = long_numReverse(el2.digits);
						new = long_numDiv(el1, el2);
						new.digits = long_numReverse(new.digits);
						push(new);
					} else { 
						printf("Division by zero\n");
						stack_clean();
						x = 0;
					}
				} else {
					printf("Not enough arguments");
					stack_clean();
					x = 0;
					break;
				}
				break;
			case '=': if (hd != NULL){
					new = pop();
					if (new. sign == -1) {
						printf("-");
					}
					print(new.digits.head);
				} else {
					printf("Not enough arguments\n");
				}
				stack_clean();
				x = 0;
				break;
			case '\n': break;
			default: x = 0;
				stack_clean();
				printf("Unknown command\n");
				break;
		}
		if (x != 0) {
			scanf("%c", &s);
		}
	}	
}
