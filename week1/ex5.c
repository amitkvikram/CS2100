/*
  Problem Name:Ex5
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:15/08/2017
*/

#include<stdio.h>
#include<stdlib.h>

struct DLLNode{
	int data;
	struct DLLNode *next; //ponter to next node in linked list
      struct DLLNode *prev; //ponter to previous node in linked list
};

typedef struct DLLNode Node; // setting alias "Node" for "struct Node"

void frontPush(Node **Headptr, int N){ //frontPush is a function which adds N nodes in the beginning of list, **Headptr is a pointer to pointer to head                                          -r to pointer Head of linked list
       printf("Enter the %d nodes you want to add:\n",N); //Prompt user to input the value of N nodes
       int tempData, i;                                      //tempData will store the value to be inserted in linked list
       Node *tempptr=*Headptr;
       for(i=0;i<N;i++){
             Node *temp= (Node*)malloc(sizeof(Node));  //Dynamically allocating memory.
             scanf("%d",&tempData);    //scanning the data input by user
             temp->data=tempData;
             temp->next=NULL;
             if(*Headptr==NULL){       //Checking if list is empty
                  *Headptr=temp;
                  tempptr=*Headptr;
                  temp->prev=NULL;
             }
             else{
                   temp->prev=tempptr;
                   tempptr->next=temp;
                   tempptr=tempptr->next;
             }
       }
}

void Printlist(Node **Headptr){  //printList function prints element of list
      Node *tempptr= *Headptr;
      if(*Headptr==NULL){        //Checking if list is empty
            printf("List is empty\n");
            return;              //returning to main() since list is empty
      }
      while(tempptr!=NULL){
            printf("%d ",tempptr->data);
            tempptr= tempptr->next;    //Moving to next node
      }
      printf("\n");
}

void insert(Node **Headptr){   //function iserts a node after a node having specific value
      printf("Enter val you want to insert in list: "); //Promting user to enter the value to be inserted in linked list
	int val1;                                         //val1 stores the value to be inserted in list
	scanf("%d",&val1);
	printf("Enter value after which you want to insert new node: ");
	int val;      //val stores the value of node after which new node is inserted
	scanf("%d",&val);
      if(*Headptr==NULL){
            printf("List is Empty\n");
            return;
      }

      Node *tempptr= *Headptr;
      while(tempptr!=NULL && tempptr->data!=val){
            tempptr=tempptr->next;
      }

      if(tempptr==NULL){
            printf("Data not found\n");
            return;
      }

      Node *temp=(Node*)malloc(sizeof(Node));
      temp->data=val1;
      temp->next=NULL;
      temp->prev=NULL;
      temp->next=tempptr->next;
      if(tempptr->next!=NULL) tempptr->next->prev= temp;
      temp->prev=tempptr;
      tempptr->next=temp;
}

void delete(Node **Headptr){                 //deleting all node having data = val
      printf("Enter val to be deleted: ");  //Prompting user to input the value(data) of node to be deleted
      int val;
      scanf("%d", &val);                    //scanning value
      if(*Headptr==NULL){                   //checking if list is empty
           printf("List is already EMPTY\n"); //print that list is empty
           return ;                       //return to calling function
      }


      if((*Headptr)->data==val){
            while(*Headptr!=NULL && (*Headptr)->data==val){
                  Node *temp=*Headptr;
                  if((*Headptr)->next!=NULL){
                        (*Headptr)->next->prev=NULL;
                  }
                  *Headptr=(*Headptr)->next;
                  free(temp);
            }
      }

      Node *tempptr=*Headptr;
      if(*Headptr==NULL) return;
      while(tempptr->next!=NULL){
            if(tempptr->next->data==val){
                  Node *temp= tempptr->next;
                  tempptr->next=tempptr->next->next;
                  if(tempptr->next!=NULL){
                        tempptr->next->prev=tempptr;
                  }
                  free(temp);
            }

            else tempptr=tempptr->next;
      }
}

void reverse(Node **Headptr){    //function reverse(), reverses the list
      if(*Headptr==NULL){        //Checking if list is empty.
            return ;
      }

      if((*Headptr)->next==NULL) return ;  //If list contains only one element there is no need to reverse the list

      Node *tempptr=*Headptr,*temp1;
      while(tempptr!=NULL){
            temp1=tempptr->prev;
            tempptr->prev=tempptr->next;
            tempptr->next=temp1;
            tempptr=tempptr->prev;
      }

      if(temp1!=NULL) *Headptr=temp1->prev;
}

void FreeMemory(Node **Headptr){    //deallocate the dynamic memory allocated for list
      Node *tempptr= *Headptr;
      while(tempptr!=NULL){
            Node *temp=tempptr;
            tempptr= tempptr->next;
            free(temp);
      }
}

int main(){
      Node *Head;   //pointer to head of list
      Head=NULL;
      int N;        //N is number of nodes user want to add.
      printf("Enter number of nodes you want to add to linked list: ");
      scanf("%d",&N);
      frontPush(&Head, N); //passing address of head and number of nodes to frontPush
      printf("List is: \n");
      Printlist(&Head);  //passing address of Head to printList, which prints the linked list
      insert(&Head);     //inserts a node in linked list
      printf("New List is: \n");
      Printlist(&Head);  //passing address of Head to printList, which prints the linked list
      delete(&Head);     //passing address of Head to funtion delete,which delete a node from list
      printf("New list is: \n");
      Printlist(&Head);  //passing address of Head to printList, which prints the linked list
      reverse(&Head);    //passing address of Head to reverse fuction,the function which reverse the list
      printf("Reversed list is: \n");
      Printlist(&Head);  //passing address of Head to printList, which prints the linked list
      FreeMemory(&Head);
      return 0;
}
