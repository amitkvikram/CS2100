all: path_finder.out shortBlue.out

path_finder.out: path_finder.c queue.o
	gcc -g path_finder.c -std=c11 -o path_finder.out queue.o

shortBlue.out: shortBlue.c queue.o
	gcc -g shortBlue.c queue.o -std=c11 -o shortBlue.out

queue.o: queue.c
	gcc -ggdb -std=c11 -c queue.c

clean:
	rm path_finder.out shortBlue.out
