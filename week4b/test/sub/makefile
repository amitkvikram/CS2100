all: path_finder.out farthest.out

farthest.out: farthest.c queue.c
	gcc -g farthest.c -std=c11 -o farthest.out queue.c

path_finder.out: path_finder.c queue.c
	gcc -g path_finder.c -std=c11 -o path_finder.out queue.c
	
clean:
	rm path_finder.out farthest.out
