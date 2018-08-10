all: tp3fb tp3h

tp3fb:	main_bruteforce.c graph.c list.c bruteforce.c
	gcc -o tp3fb main_bruteforce.c graph.c list.c bruteforce.c -I. -Wall -Wextra -Werror -std=c99 -pedantic -O2

tp3h: main_heuristic.c graph.c list.c heuristic.c
	gcc -o tp3h main_heuristic.c graph.c list.c heuristic.c -I. -Wall -Wextra -Werror -std=c99 -pedantic -O2