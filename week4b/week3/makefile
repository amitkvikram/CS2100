all: hamiltonian.o
	
hamiltonian.o: hamiltonian.c queue.c CircularLinkedList.c double_linked_list.c
	gcc -g hamiltonian.c -std=c11 -o hamiltonian queue.c CircularLinkedList.c double_linked_list.c
	
clean:
	rm hamiltonian.o
