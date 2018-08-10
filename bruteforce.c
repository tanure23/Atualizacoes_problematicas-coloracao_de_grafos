#include "graph.h"
#include "list.h"
#include "bruteforce.h"


int has_conflict(graph gr, int vertex, int *colors, int now_color){
	node *current = gr.adj[vertex].head;

	while(current != NULL){
		if(now_color == colors[current->id]){
			return 1; //there is conflict
		}
		current = current->next;
	}
	return 0;
}

int coloring(graph gr, int m, int *colors, int vertex){
	if(vertex == gr.n_vertices){
		return 1;
	}
	int c;
	for(c=1; c<=m; c++){
		if(has_conflict(gr, vertex, colors, c)==0){
			colors[vertex] = c;
			if(coloring(gr, m, colors, vertex+1)==1){
				return 1;
			}

			colors[vertex] = 0;
		}
	}

	return 0;
}




