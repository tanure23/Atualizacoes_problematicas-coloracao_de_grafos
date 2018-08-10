#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

int has_conflict(graph gr, int vertex, int *colors, int now_color);
int coloring(graph gr, int m, int *colors, int vertex);

#endif /*BRUTEFORCE_H*/
