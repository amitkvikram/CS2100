all: eulerian.o
	
eulerian.o: eulerian.c queue.o CircularLinkedList.o stack.c
	gcc -g eulerian.c -std=c11 -o eulerian.out queue.o stack.c CircularLinkedList.o
	
clean:
	rm eulerian.o
