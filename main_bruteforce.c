#include "graph.h"
#include "list.h"
#include "heuristic.h"
#include "bruteforce.h"

int main(){
	int n_servers, m_connections;
	int i=0, min=0;
	int src, dest;
	graph gr;

	FILE *answer = fopen("rodadasfb.txt", "w+");
	FILE *allocation = fopen("alocacaofb.txt", "w+");

	if(scanf("%d", &n_servers)==0) return -1;
	if(scanf("%d", &m_connections)==0) return -2;
	
	gr = create_graph(n_servers);
	for(i=0; i<m_connections; i++){
		if(scanf("%d %d", &src, &dest)==0) return -3;
		src-=1;
		dest-=1;
		add_edge(gr, src, dest);
	}

	int *colors = malloc(n_servers*sizeof(int));
	for(i=0; i<n_servers; i++){
		colors[i] = 0;
	}

	for(i=1; i<=n_servers; i++){
		if(coloring(gr, i, colors, 0)==1){
			printf(GRN "min: %d\n", i);
			min = i;
			break;
		}
	}

	fprintf(answer, "%d\n", min);

	for(i=0; i<n_servers; i++){
		fprintf(allocation, "%d %d\n", i+1, colors[i]);
	}

	fclose(answer);
	fclose(allocation);


	// printf("min: %d\n", min);

	free(colors);
	free_graph(gr, n_servers);

	return 0;
}
