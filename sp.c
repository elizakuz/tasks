/* односвязный список
	Kuzmina Elizaveta */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
	int v;
	struct node_t *next;
}node_t;
node_t *hd = NULL, *p;
void s(){ 
	for(;;)
	{
		node_t *p = (node_t *) malloc(sizeof (node_t));
		scanf("%d", &(*p).v);
		if ((*p).v != 0){
			(*p).next = hd;
			hd = p;
		}
		else break;
	}
}
void add(){
	node_t *p = (node_t *) malloc(sizeof (node_t));
	scanf("%d", &(*p).v);
	if((*p).v != 0){
		(*p).next = hd;
		hd = p;
	}
}
void print(){
	p = hd;
     	for(;;){
		if(p != NULL){
			printf("%d ", (*p).v);
			p = (*p).next;
		}
		else {
			break;
		}
	}	
	printf("\n");
}
void delete(){
	int n;
	scanf("%d", &n);
	node_t * q;
	for(p = hd; p && ((*p).v != n);q = p, p = (*p).next){}
	(*q).next = (*p).next;
	free(p);
}		
int main(){
	char k;
	scanf("%s", &k);
	while(k != 'q'){
		switch(k) {
			case 'a': add();
				break;
			case 'p': print();
				break;
			case 'd': delete();
				break;
			case 'q': break;
		}
		scanf("%s", &k);
	}
}
