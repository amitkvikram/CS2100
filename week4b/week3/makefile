all: hamiltonian
	
hamiltonian: hamiltonian.o queue.o CircularLinkedList.o double_linked_list.o
	gcc -ggdb -Wall hamiltonian.o queue.o CircularLinkedList.o double_linked_list.o -std=c11 -o hamiltonian 

hamiltonian.o: hamiltonian.c 
	gcc -c hamiltonian.c 

queue.o: queue.c
	gcc -c queue.c

CircularLinkedList.o: CircularLinkedList.c 	
	gcc -c CircularLinkedList.c 

double_linked_list.o: double_linked_list.c 
	gcc -c double_linked_list.c 

clean:
	rm hamiltonian
