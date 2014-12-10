/* simple calculator
	Kuzmina Elizaveta */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
	int v;
	struct node_t *next;
}node_t;
node_t *hd = NULL, *p, *q, *r;
void add(int n){
	node_t *p = (node_t *) malloc(sizeof (node_t));
	p->v = n;
	p->next = hd;
	hd = p;	
}
void del(int n){
	node_t * q;
	for(p = hd; p && (p->v != n);q = p, p = p->next){}
		if(p == NULL){
			printf("no such simbol\n");
		} else {
			if (p == hd) {
				hd = hd->next;
			} else {
				q->next = p->next;
			}
		}	
	free(p);
}
void print(){
	p = hd;
     	for(;p != NULL; p = p->next){
		if(p->next != NULL){
			printf("%d, ", p->v);
		}else {
			printf("%d\n", p->v);
			break;
		}
	}		
}		
void clear(){
	while(hd != NULL){
		del(hd->v);
	}
}	
int main(){
	char s;
	int n;
	int x = 0;
	scanf("%c", &s);
	while(s != 'q'){
		switch(s) {
			case '0'...'9': n = s - '0';
				add(n); 
				break;
			case '+':
				if((hd != NULL) & (hd->next != NULL)){
					hd->v = hd->v + (hd->next)->v;
					del( (hd->next)->v);
				} else {
					printf("wrong expression\n");
				}
				break;
			case '-':
				if((hd != NULL) & (hd->next != NULL)){
					hd->v = (hd->next)->v - hd->v;
					del( (hd->next)->v);
				} else {
					printf("wrong expression\n");
				}
				break;
			case '*':
				if((hd != NULL) & (hd->next != NULL)){
					hd->v = hd->v * (hd->next)->v;
					del( (hd->next)->v);
				} else {
					printf("wrong expression\n");
				}
				break;
			case '/':
				if((hd != NULL) & (hd->next != NULL)){
					if(hd->v != 0){
						hd->v = (hd->next)->v / hd->v;
						del( (hd->next)->v);
					} else { 
						printf("division by zero");
					}
				} else {
					printf("wrong expression\n");
				}
				break;
			case '=': if(x){
					printf("no such command");
				} else {
					printf("Answer: "); 
					print();
					clear();
				}
				break;
			case 'q': break;
			case '\n': break;
			case ' ': break;
			default: x = 1;
				break;
		}
		scanf("%c", &s);
	}	
}
