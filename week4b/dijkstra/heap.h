#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

struct heap{  //min heap
  int *array;
  int count;  //no of elements in a Heap
  int capacity;
}

typedef struct heap heap;

void swap(int *a, int *b);

heap *createHeap(int capacity);

int left(int i);
int right(int i);

void minHeapify(heap **h, int i);
void heapInsert(heap **h, int value, int index);
int popHeapMin(heap **h);
