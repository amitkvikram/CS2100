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

heap *createHeap(int capacity){
  heap *h;
  h = malloc(sizeof(heap));
  h->count = 0;
  h->capacity = capacity;
  h->array = malloc(sizeof(int)*h->capacity);
  return h;
}

int left(int i) return (2*i + 1);
int right(int i) return (2*i + 2);

void minHeapify(heap **h, int i){
  int l_chid = left(i);
  int r_chile = right(i);

  if(l<h->count && )
}

void heapInsert(heap **h, int value){
  if(h->count == 0){
    h->count++;
    h->array[0] = value;
    return;
  }

  h->count++;
  int i = h->count-1;
  while(i>=0 && data < (*h)->array[(i-1)+2]){
    (*h)->array[i] = (*h)-array[(i-1)/2];
    i = (i-1)/2;
  }

  h->array[i]= data;
}

int popHeapMin(heap **h){
  if(h->count == 0){
    return -1;
  }

  int data = h->array[0];
}
