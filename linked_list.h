#ifndef linked_list
#define linked_list

struct element{
	struct element *prev;
	struct element *next;
	void * value;
	};

typedef struct {
	struct element *first;
	struct element *last;
	int nelements;
	} linkedlist;


extern char* mode;
char* mode = "stack";
linkedlist* begin_list ();
struct element* begin_element(void *);
int list_empty(linkedlist *);
struct element* insert(linkedlist *, struct element*);
void* extract(linkedlist *);
int list_free(linkedlist *, void(*)());

linkedlist* begin_list (){
	linkedlist *list = (linkedlist *) malloc(sizeof(linkedlist));
	list->nelements = 0;
	list->first = list->last  = NULL;
	return list;
}

struct element* begin_element(void * value){
	struct element * el = malloc(sizeof(struct element));
	el->prev = el->next = NULL;
	el->value = value;
	return el;
}

int list_empty(linkedlist * list){
	if(list->nelements) return list->nelements;
	else return 0;
}

struct element* insert(linkedlist * list, struct element* el){
	if(!list_empty(list)){
		list->last = list->first = el;
		el->prev = el->next = NULL;
	}
	else if(list_empty(list) == 1){
		list->last = el;
		el->prev = list->first;
		(list->first)->next = el;
	}
	else {
		(list->last)->next = el;
		el->prev = list->last;
		list->last = el;
	}
	list->nelements++;
	return el;
}

void * extract(linkedlist * list){
	struct element* aux;
	void * value;
	if(!strcmp(mode, "stack")){puts("stack");
		aux = list->last;
		if(aux == NULL) return NULL;
		else if(list_empty(list) == 1) list->last = list->first = NULL;
		else list->last = (list->last)->prev;
	} else if(!strcmp(mode, "queue")) {
		puts("queue");
		aux = list->first;
		if(aux == NULL) return NULL;
		else if(list_empty(list) == 1) list->last = list->first = NULL;
		else list->first = (list->first)->next;
	}
	aux->prev = aux->next = NULL;
	list->nelements--;
	value = aux->value;
	free(aux);
	return value;		
}
#endif
