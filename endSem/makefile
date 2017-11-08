all: a.out b.out b1.out

a.out: a.c queue.o
	gcc -ggdb -std=c11 a.c queue.o -o a.out
	
b1.out: b1.c queue.o stack.c CircularLinkedList.c
	gcc -ggdb -std=c11 b1.c queue.o CircularLinkedList.c stack.c -o b1.out

b.out: b.c queue.o stack.c CircularLinkedList.c
	gcc -ggdb -std=c11 b.c queue.o CircularLinkedList.c stack.c -o b.out

queue.o: queue.c
	gcc -g -c queue.c

stack.o: stack.c
	gcc -g -c stack.c

CircularLinkedList.o: CircularLinkedList.c
	gcc -g -c CircularLinkedList.c

clean:
	rm a.out
