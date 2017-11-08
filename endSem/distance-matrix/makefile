all: a.out 

a.out: a.c queue.o
	gcc -ggdb -std=c11 a.c queue.o -o a.out

queue.o: queue.c
	gcc -g -c queue.c

clean:
	rm a.out
