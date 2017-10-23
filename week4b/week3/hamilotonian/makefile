all: hamiltonian.out amit

amit:hamiltonian.out
	./hamiltonian.out
	
hamiltonian.out: hamiltonian.o queue.o
	gcc -g -Wall hamiltonian.o queue.o -std=c11 -o hamiltonian.out 

hamiltonian.o: hamiltonian.c queue.h
	gcc -c hamiltonian.c

queue.o: queue.c
	gcc -c queue.c
	
clean:
	rm hamiltonian.out *.o
