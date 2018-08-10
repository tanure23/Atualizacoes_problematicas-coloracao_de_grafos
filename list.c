#include "graph.h"
#include "list.h"

void add_to_list(list *l, int id){
	node *aux = malloc(sizeof(node));
	aux->id = id;
	aux->next = NULL;
	if(is_empty(l) == 0){
		l->tail->next = aux;
		l->tail = aux;
	}
	else{
		l->head = aux;
		l->tail = aux;
	}
}

int is_empty(list *l){
	if(l->head == NULL && l->tail == NULL){
		return 1;
	}
	return 0;
}

void print_list(list *l){
	node *current = l->head;
	if(is_empty(l) == 0){
		while(current != NULL){
			// printf("%d -> ", (current->id)+1);
			printf("%d -> ", (current->id));
			current = current->next;
		}
	}
	printf("the end\n");
}

list create_list(){
	list l;
	l.head = NULL;
	l.tail = NULL;
	return l;
}

void free_list(list *l){
	node *current = l->head;
	node *temp;
	while(current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	}
	l->head = NULL;
}