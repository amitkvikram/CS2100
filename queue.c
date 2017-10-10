/*
  Problem Name:Ex2
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:05/09/2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

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
//main ends here
