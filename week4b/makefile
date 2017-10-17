all: eulerian.o
	
eulerian.o: eulerian.c queue.o CircularLinkedList.o
	gcc -g eulerian.c -std=c11 -o eulerian queue.o CircularLinkedList.o
	
clean:
	rm eulerian.o
