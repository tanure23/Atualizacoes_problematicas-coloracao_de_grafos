#include "graph.h"
#include "list.h"
#include "heuristic.h"

int main(){
	int n_servers, m_connections;
	int i=0;
	// int *colors;
	// int aux=0;
	// int *visited;
	int src, dest;
	graph gr;

	if(scanf("%d", &n_servers)==0) return -1;
	if(scanf("%d", &m_connections)==0) return -2;
	// aux = n_servers;
	// visited = (int*)calloc(n_servers, sizeof(int));
	// colors = (int*)calloc(n_servers, sizeof(int));
	
	gr = create_graph(n_servers);
	for(i=0; i<m_connections; i++){
		if(scanf("%d %d", &src, &dest)==0) return -3;
		src-=1;
		dest-=1;
		add_edge(gr, src, dest);
	}

	// print_graph_adjlist(gr, n_servers);

	int min = heuristic(gr, n_servers);

	FILE *answer = fopen("rodadash.txt", "w+");
	fprintf(answer, "%d\n", min);

	fclose(answer);

	printf("min: %d\n", min);

	// free(colors);
	free_graph(gr, n_servers);

	return 0;
}
