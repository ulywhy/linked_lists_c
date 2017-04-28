#include<stdlib.h>

#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct elem{
	struct elem *prev;
	struct elem *next;
	void *node;
} Element;

typedef struct {
	Element *first;
	Element *last;
	int n_elements;
} Linkedlist;


linkedlist * list_init ();
Element * element_create (void *);
int list_is_empty (Linkedlist *);
Element * list_insert (Linkedlist *, Element *);
void * list_extract (Linkedlist *);
int list_free (Linkedlist *, void(*)());

Linkedlist* list_init (){
	Linkedlist * list = (Linkedlist *) malloc(sizeof(Linkedlist));
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

int list_empty (Linkedlist *list){
	if (list->n_elements){
		return list->n_elements;
	}
	else{
		return 0;
	}
}

/*insert an element as the last element of the list*/
struct element * list_insert (Linkedlist *list, Element *element){
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
	return element;
}

void * list_extract (Linkedlist *list){
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
	--(list->nelements);
	node = elenemt->value;
	free(element);
	return value;		
}
#endif
