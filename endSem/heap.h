#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

struct arr{
	int value;
	int index;
};

typedef struct arr arr;

struct heap{  //min heap
  arr *array;
  int count;  //no of elements in a Heap
  int capacity;
  int *hashTable;
};

typedef struct heap heap;

void swap(heap **h, int i, int smallest);

heap *createHeap(int capacity);

int left(int i);
int right(int i);

void minHeapifyUp(heap **h, int i);
void minHeapify(heap **h, int i);
void heapInsert(heap **h, int value, int index);
arr popHeapMin(heap **h);
int isEmptyHeap(heap **h);
void printHeap(heap **h);
