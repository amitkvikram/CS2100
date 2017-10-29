all: eulerian.out eulerian1.out

eulerian.out: eulerian.c queue.o CircularLinkedList.c stack.o CircularLinkedList.h
	gcc -g eulerian.c queue.o CircularLinkedList.c stack.o CircularLinkedList.h -std=c11 -o eulerian.out

eulerian1.out: eulerian1.c queue.o CircularLinkedList.c stack.o CircularLinkedList.h
	gcc -g eulerian1.c queue.o CircularLinkedList.c stack.o CircularLinkedList.h -std=c11 -o eulerian1.out

queue.o: queue.c
	gcc -c queue.c

CircularLinkedList.o:CircularLinkedList.c	CircularLinkedList.h
	gcc -c CircularLinkedList.c

stack.o:stack.c
	gcc -c stack.c

clean:
	rm eulerian.out
