all: counting_pieces.out path_finder.out farthest.out

counting_pieces.out: counting_pieces.c queue.o
	gcc -ggdb -Wall counting_pieces.c queue.o -std=c11 -o counting_pieces.out

farthest.out: farthest.c queue.o
	gcc -ggdb farthest.c queue.o -std=c11 -o farthest.out

path_finder.out: path_finder.c queue.o
	gcc -ggdb -Wall path_finder.c queue.o -std=c11 -o path_finder.out

queue.o:queue.c
	gcc -c queue.c

clean:
	rm counting_pieces.out path_finder.out farthest.out
