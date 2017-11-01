all: dijkstra1.out

dijkstra1.out: dijkstra1.o
	gcc -ggdb -Wall -std=c11 dijkstra1.o -o dijkstra1.out

dijkstra1.o: dijkstra1.c
	gcc -ggdb -Wall -std=c11 -c dijkstra1.c

clean:
	rm d*.o dijkstra1.out
