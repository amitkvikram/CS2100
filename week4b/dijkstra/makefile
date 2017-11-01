all: dijkstra1.out dijkstra.out

dijkstra.out: dijkstra.o heap.o
	gcc -ggdb -Wall -std=c11 dijkstra.o heap.o -o dijkstra.out

dijkstra.o: dijkstra.c
	gcc -ggdb -Wall -std=c11 -c dijkstra.c

heap.o: heap.c
	gcc -ggdb -Wall -std=c11 -c heap.c

dijkstra1.out: dijkstra1.o
	gcc -ggdb -std=c11 dijkstra1.o -o dijkstra1.out

dijkstra1.o: dijkstra1.c
	gcc -ggdb -Wall -std=c11 -c dijkstra1.c

clean:
	rm d*.o dijkstra1.out
