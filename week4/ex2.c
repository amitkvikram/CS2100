/*
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 03/10/2017
   Task: 02
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int arr[100][100];

/**********************************************  QUEUE  **********************************************************/ 
struct Node{
      int data;
      struct Node *next;
};

typedef struct Node node;

struct Queue{
      node *front;
      node *end;
};

typedef struct Queue queue;

//Creates Queue
queue *createQueue(){
      queue *Q;
      Q= malloc(sizeof(queue));
      Q->front= Q->end= NULL;
      return Q;
}

//checks if Queue is empty or not
int isEmptyQueue(queue **Q){
      if((*Q)->front==NULL) return 1; //returns 1 if Queue is empty
      return 0;                  //returns 0 if Queue is not empty
}

//Inserts an element at	the end of the queue
void enQueue (queue **Q, int x){
      node *temp;
      temp=(node*)malloc(sizeof(node));
      temp->next=NULL;
      temp->data=x;
      if(!(*Q)->front){     //Checks if queue is empty
            (*Q)->front=(*Q)->end=  temp;   //reset front of queue
      }
      else{
            (*Q)->end->next=temp;
            (*Q)->end = temp;               //reset end of queue
      }

      temp->next= (*Q)->front;
}

//deletes and returns element at the front of queue
int dequeue(queue **Q){
      if(isEmptyQueue(Q)){
            printf("Queue is Empty\n");
            return INT_MAX;
      }

      int element;

          if ((*Q)->front == (*Q)->end)
          {
              element = (*Q)->front->data;
              free((*Q)->front);
              (*Q)->front = NULL;
              (*Q)->end = NULL;
          }
          else
          {
              struct Node *temp = (*Q)->front;
              element = temp->data;
              (*Q)->front = (*Q)->front->next;
              (*Q)->end->next= (*Q)->front;
              free(temp);
          }
    return element;
}

/********************************************************************************************************************************/

int BreadthFirstSearch(int num_vertices){
	int root, goal;		//Aim is to search if path between root and goal exists
	printf("Enter Root and Goal: ");
	scanf("%d%d", &root, &goal);
	queue *Q=createQueue();
	int Checked[100] = {0};
	Checked[root] = 1;	//marking root as visited
	enQueue(&Q, root);
	while(!isEmptyQueue(&Q)){
		int Current = dequeue(&Q);		//finding current node
		if(Current == goal) return 1;		//returns 1 if Current node is equal means if we have found path from root to goal
		for(int i=0; i<num_vertices; i++){
			if(arr[Current][i] == 1){
				if(Checked[i] !=1){	//checking if cerrent node has been visted before or not
					Checked[i] = 1;	//marking  node as visited
					enQueue(&Q, i);
				}
			}
		}
	}
	
	return 0;
}
	
	

int Read(FILE **fp){
	char GraphName[50] ;
	fscanf(*fp, " %[^\n]s", GraphName);
	char GraphType[50];
	fscanf(*fp, " %[^\n]s", GraphType);
	int num_vertices;
	fscanf(*fp, "%d", &num_vertices);	//scannig number of vertices in the graph
	
	for(int i=0;i<num_vertices; i++){
		for(int j=0;j<num_vertices;j++){TestGraphs/Graph06.txt
			fscanf(*fp, "%1d", &arr[i][j]);
		}
	}
	
	return num_vertices;
}	

int main(){
	char FileName[50];
	printf("Enter Filename");
	scanf("%s", FileName);
	
	FILE *fp;
	fp=fopen(FileName, "r");	//Opening .txt file
	
	 
	 if(fp==0)	//Checking for file error in opening
	 {
	  	printf("Error in opening the file %s.\n", FileName);
	  	return(1);
	 }
	
	int num_vertices = Read(&fp);
	int flag = BreadthFirstSearch(num_vertices);
	if(flag == 1) printf("Connected\n");
	else printf("Not Connected\n");
	return 0;
}
