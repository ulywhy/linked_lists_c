#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#undef NODE
#define NODE data

typedef struct {
	int age;
	int id;
}data;

/*simple exaple using double linked list library*/
int main(void){
	/*declare a pointer to the linked list: keep a counter of elements
	* the head and the tail of the linked list
	*/
	LinkedList * List;
	
	/*initialize the list*/
	List = list_init();
	
	/*insert 10 data*/
	int i;
	data * d;
	for(i = 1; i <= 10; ++i){
		d = malloc(sizeof(data));
		d->age = i * 10;
		d->id = i * 20;
		/*insert the element at the end of the list*/
		list_stack(List, d);
	}
	
	/*print all id's*/
	data ** ds;//pointer to an array of pointers
	ds = list_get_all(List);//get an array with all data in the list in the order as they where inserted
	
	for(i = 0; i < 10; ++i){
		printf("id %d\n", ds[i]->id);
	}
	//the array must be freed by the user once it isn't needed
	free(ds);

	/*one can traverse the List*/
	Element * e = List->first;
	for(i = 0; i < 10; ++i){
		d = e->node;
		printf("pointer to data: %p, has age = %d\n", d, d->age);
		//go to the next element in the list
		e = e-> next;
		//similarly by doing e = List->last;
		// and e = e->prev; can traverse backards
		//your data structure is pointed by e->node
	}
	
	/*print all ages in the list and delete the struct using pop*/
	for(i = 0; i < 10; ++i){
		d = list_pop(List);
		printf("age: %d\n", d->age);
		free(d);
		/*insert the element at the end of the list*/
	}
	
	/*free the allocated memory from the linked list and the data stored by the user*/
	list_free(List);	
}
