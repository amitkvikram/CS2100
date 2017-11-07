all: dfs.out cutVertex.out

dfs.out: dfs.c stack.o
	gcc -ggdb -Wall -std=c11 dfs.c stack.o -o dfs.out

cutVertex.out: cutVertex.c stack.o
	gcc -ggdb -Wall -std=c11 cutVertex.c stack.o -o cutVertex.out

stack.o: stack.c
	gcc -g -c stack.c

clean:
	rm dfs.out cutVertex.out *.o
