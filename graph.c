#include "graph.h"
#include "list.h"

graph create_graph(int n_vertices){
	list *adj = malloc(n_vertices*sizeof(list));
	int i;
	graph gr;
	for(i=0; i<n_vertices; i++){
		adj[i] = create_list();
	}
	gr.n_vertices = n_vertices;
	gr.adj = adj;
	return gr;
}

void add_edge(graph gr, int src, int dest){
	add_to_list(&(gr.adj[src]), dest);
	add_to_list(&(gr.adj[dest]), src);
}

void dfs(graph gr, int first, int *visited){
	visited[first] = 1;

	node *current = gr.adj[first].head;
	while(current != NULL){
		if(visited[current->id] == 0){
			dfs(gr, current->id, visited);
		}
	}

}

void print_graph_adjlist(graph gr, int n_vertices){
	int i;
	for(i=0; i<n_vertices; i++){
		// printf(CYN "Adj list of %d: " RESET, i+1);
		printf(CYN "Adj list of %d: " RESET, i);
		print_list(&(gr.adj[i]));
		printf("\n");
	}
}

void free_graph(graph gr, int n_vertices){
	int i;
	for(i=0; i<n_vertices; i++){
		free_list(&(gr.adj[i]));
	}
	free(gr.adj);
}