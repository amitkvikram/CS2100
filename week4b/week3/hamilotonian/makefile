all: hamiltonian.out
	
hamiltonian.out: hamiltonian.c queue.c
	gcc -g hamiltonian.c -std=c11 -o hamiltonian.out queue.c
	
clean:
	rm hamiltonian.out
