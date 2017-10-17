all: 5colour.o 6colour.o
	
5colour.o: 5colour.c queue.c CircularLinkedList.c stack.c
	gcc -g 5colour.c -std=c11 -o 5colour.o queue.c CircularLinkedList.c stack.c
	
6colour.o: 6colour.c queue.c CircularLinkedList.c stack.c
	gcc -g 6colour.c -std=c11 -o 6colour.o queue.c CircularLinkedList.c stack.c

clean:
	rm 5colour.o
	rm 6colour.o
