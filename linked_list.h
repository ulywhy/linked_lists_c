#include<stdlib.h>

#ifndef LINKED_LIST
#define LINKED_LIST

#define NODE void

typedef struct elem{
	struct elem *prev;
	struct elem *next;
	void *node;
} Element;

typedef struct {
	Element *first;
	Element *last;
	int n_elements;
}LinkedList;


LinkedList * list_init ();
Element * element_create (void *);
int list_is_empty (LinkedList *);
void list_stack (LinkedList *, void *);
void * list_pop (LinkedList *);
NODE ** list_get_all (LinkedList *);
void list_free (LinkedList *);

LinkedList* list_init (){
	LinkedList * list = malloc(sizeof(LinkedList));
	list->n_elements = 0;
	list->first = list->last  = NULL;
	return list;
}

Element * element_create (void *node){
	Element *element = malloc(sizeof(Element));
	element->prev = element->next = NULL;
	element->node = node;
	return element;
}

int list_empty (LinkedList *list){
	if (list->n_elements){
		return list->n_elements;
	}
	else{
		return 0;
	}
}

/*insert an element as the last element of the list*/
void list_stack (LinkedList *list, void *node){

	Element * element = element_create(node);

	if (!list_empty(list)){
		list->last = list->first = element;
		element->prev = element->next = NULL;
	}
	else if (list_empty(list) == 1){
		list->last = element;
		element->prev = list->first;
		(list->first)->next = element;
	}
	else {
		(list->last)->next = element;
		element->prev = list->last;
		list->last = element;
	}
	++(list->n_elements);
}

void * list_pop (LinkedList *list){
	Element *element;
	void *node;
	element = list->last;
	
	if (element == NULL){
		return NULL;
	}
	else{
		if (list_empty (list) == 1){
			list->last = list->first = NULL;
		}
		else {
			list->last = (list->last)->prev;
		}
		element->prev = element->next = NULL;
	}
	--(list->n_elements);
	node = element->node;
	free(element);
	return node;
}

NODE ** list_get_all (LinkedList * List){
	int i, 
		lenght = List->n_elements;
	NODE ** nodes = malloc(sizeof(NODE *) * lenght);
	Element * e = List->first;
	for(i = 0; i < lenght; ++i){
		nodes[i] = e->node;
		e = e->next;
	}
	return nodes;
}

void list_free (LinkedList * List){
	int i, j = List->n_elements;
	Element * e;
	NODE * n;
	for(i = 0; i < j; ++i){
		e = list_pop(List);
		n = e->node;
		free(n);
	}
	free(List);
	List = NULL;
}
#endif
