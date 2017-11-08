all: b1.out
	
b1.out: b1.c queue.o stack.o CircularLinkedList.o
	gcc -ggdb -std=c11 b1.c queue.o CircularLinkedList.o stack.o -o b1.out

queue.o: queue.c
	gcc -g -c queue.c

stack.o: stack.c
	gcc -g -c stack.c

CircularLinkedList.o: CircularLinkedList.c
	gcc -g -c CircularLinkedList.c

clean:
	rm a.out
