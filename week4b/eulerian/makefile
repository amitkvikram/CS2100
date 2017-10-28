all: eulerian.o
	
eulerian.o: eulerian.c queue.c CircularLinkedList.c stack.c
	gcc -g eulerian.c -std=c11 -o eulerian.o queue.c CircularLinkedList.c stack.c
	
clean:
	rm eulerian.o
