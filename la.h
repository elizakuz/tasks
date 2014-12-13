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
	int size;
	int_list digits;
} long_num;
void add(int n, node_t * hd){
	scanf("%d", &n);
	node_t *p = (node_t *) malloc(sizeof (node_t));
	p->v = n;
	p->next = hd;
	hd = p;	
}

