all: counting_pieces.o path_finder.o farthest.o
	
counting_pieces.o: counting_pieces.c queue.c
	gcc -g counting_pieces.c -std=c11 -o counting_pieces.o queue.c

farthest.o: farthest.c queue.c
	gcc -g farthest.c -std=c11 -o farthest.o queue.c

path_finder.o: path_finder.c queue.c
	gcc -g path_finder.c -std=c11 -o path_finder.o queue.c
	
clean:
	rm counting_pieces.o path_finder.o farthest.o
