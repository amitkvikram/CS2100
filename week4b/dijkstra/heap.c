#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
//MIN HEAP

struct arr{
	int value;
	int index;
};

typedef struct arr arr;

struct heap{  //min heap
  arr *array;
  int count;  //no of elements in a Heap
  int capacity;
};

typedef struct heap heap;

void swap(arr *a, arr *b){
  arr temp = *a;
  *a = *b;
  *b = temp;
}

heap *createHeap(int capacity){
  heap *h;
  h = malloc(sizeof(heap));
  h->count = 0;
  h->capacity = capacity;
  h->array = malloc(sizeof(arr)*h->capacity);
  return h;
}

int left(int i) {
	return (2*i + 1);
}
int right(int i){
	return (2*i + 2);
}
void minHeapify(heap **h, int i){
  int l_child = left(i);
  int r_child = right(i);
  int smallest = i;
  if(l_child< (*h)->count && (*h)->array[l_child].value < (*h)->array[i].value){
    smallest = l_child;
  }

  if(r_child < (*h)->count && (*h)->array[r_child].value < (*h)->array[smallest].value){
    smallest = r_child;
  }

  if(smallest != i){
    swap(&(*h)->array[i], &(*h)->array[smallest]);
    minHeapify(h, smallest);
  }
}

void heapInsert(heap **h, int value, int index){
  if((*h)->count == 0){     //heap is empty
    (*h)->count++;          //now heap have 1 element so incrementing count
    (*h)->array[0].value = value; //setting first element as value
    (*h)->array[0].index= index;
    return;
  }

  (*h)->count++;    //incrementing count
  int i = (*h)->count-1;  //i is last element
  while(i>=0 && value < (*h)->array[(i-1)/2].value){
    (*h)->array[i] = (*h)->array[(i-1)/2];
    i = (i-1)/2;
  }

  (*h)->array[i].value= value;
  (*h)->array[i].index= index;
}

arr popHeapMin(heap **h){
  if((*h)->count == 0){
  	arr temp;
  	temp.value = -1;
  	temp.index = -1;
    return temp;
  }

  arr data = (*h)->array[0];
  (*h)->array[0] = (*h)->array[(*h)->count-1];
  (*h)->count--;

  minHeapify(h, 0);

  return data;
}

int isEmptyHeap(heap **h){
	if((*h)->count == 0){
		return 1;
	}

	return 0;
}
