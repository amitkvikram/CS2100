all: ex3.o path_finder.o ex4.o
	
ex3.o: ex3.c /home/amit/Documents/cs2110/week2b/queue.c
	gcc -g ex3.c -o ex3.o /home/amit/Documents/cs2110/week2b/queue.c

ex4.o: ex4.c /home/amit/Documents/cs2110/week2b/queue.c
	gcc -g ex4.c -o ex4.o /home/amit/Documents/cs2110/week2b/queue.c

path_finder.o: path_finder.c /home/amit/Documents/cs2110/week2b/queue.c
	gcc -g path_finder.c -o path_finder.o /home/amit/Documents/cs2110/week2b/queue.c
