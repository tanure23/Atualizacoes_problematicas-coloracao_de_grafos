#include "graph.h"
#include "list.h"

int heuristic(graph gr, int n_vertices){
	int *vertexes = malloc((n_vertices+1)*sizeof(int));
	int *rounds = (int*)calloc((n_vertices+1), sizeof(int));
	int i, v, c;
	int min=0;
	int available=0;
	node *current;
	
	for(i=0; i<n_vertices+1; i++){
		vertexes[i] = -1;
	}
	vertexes[0] = 0;

	//colors[i] will be 1 if the color at that position
	//has already been assigned to one of i's adj vertices
	int *colors = (int*)calloc((n_vertices+1), sizeof(int));

	for(v=0; v<n_vertices; v++){
		current = gr.adj[v].head;
		while(current != NULL){
			if(vertexes[current->id] != -1){
				colors[vertexes[current->id]] = 1;
			}
			current = current->next;
		}

		//find the first available color
		for(c=0; c<n_vertices; c++){
			if(colors[c] == 0){
				available = c;
				rounds[v] = c;
				if(available > min){
					min = available;
				}
				break;
			}
		}

		//assign the minimum color available to vertex v
		vertexes[v] = available;

		//reset values back to false for next iteration
		current = gr.adj[v].head;
		while(current != NULL){
			if(vertexes[current->id] != -1){
				colors[vertexes[current->id]] = 0;
			}
			current = current->next;
		}
	}

	FILE *alocacao = fopen("alocacaoh.txt", "w+");
	for(i=0; i<n_vertices; i++){
		fprintf(alocacao, "%d %d\n", i+1, rounds[i]+1);
	}

	free(vertexes);
	free(colors);
	free(rounds);
	fclose(alocacao);

	return min+1;

}
