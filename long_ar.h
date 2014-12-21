typedef struct node_t{
	int v;
	struct node_t * next;
} node_t;
typedef struct int_list {
	size_t count;
	node_t * head;
} int_list;
typedef struct long_num {
	int sign;
	int_list digits;
} long_num;
void add(int n, int_list * l){
	node_t *p = (node_t *) malloc(sizeof (node_t));
	p->v = n;
	p->next = l->head;
	l->head = p;	
}
void print(node_t * hd){
	node_t * p = hd;
     	for(;p != NULL; p = p->next){
		if(p->next != NULL){
			printf("%d, ", p->v);
		}else {
			printf("%d\n", p->v);
			break;
		}
	}		
}
