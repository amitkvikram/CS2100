#include<stdio.h>
#include<stdlib.h>

struct CLLNode{               //user defined data type(structure) CLLNode
	int data;             //data stores the value of node
	struct CLLNode *next; //Pointer to next node in Circular linked list
};


typedef struct CLLNode Node; //setting alias "Node" for "struct CLLNode"

//insert a node in list
void insert(Node **Headptr, int tempData);

void InsertAtGivenPosition(Node **Headptr, int pos, int value);

//print node in list
void Printlist(Node **Headptr);

int search(Node **Headptr, int tempData);

//free dynamically allocated memmory
void FreeMemory(Node **Headptr);

//returns value at a given position
int ValueAtGivenPosition(Node **Headptr, int pos);
