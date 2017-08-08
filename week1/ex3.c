/*
  Problem Name:Ex3
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:07/08/2017
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next; //ponter to next node in linked list
};

typedef struct Node Node; // setting alias "Node" for "struct Node"

void frontPush(Node **Headptr, int N){  //frontPush is a function which adds N nodes in the beginning of list, **Headptr is a pointe                                          -r to pointer Head of linked list
       printf("Enter the %d nodes you want to add:\n",N); //Prompt user to input the value of N nodes
       int tempData, i;                                      //tempData will store the value to be inserted in linked list
       for(i=0;i<N;i++){
	       scanf("%d",&tempData);
	       Node *temp= (Node*) malloc(sizeof(Node));  //Dynamically allocating memory block pointed by pointer temp;
	       temp->data= tempData;                      //setting data member of allocated memory to tempData
	       temp->next= *Headptr;                      //setting next pointer to point to Current Head of list(So points to secon                                                            d element of updated linked list)
	       *Headptr= temp;                            //Head now points to block pointed by temp,So that Head points to beginnin                                                            -g of list 
       }
}

void insert(Node **Headptr){
	printf("Enter val you want to insert in list: "); //Promting user to enter the value to be inserted in linked list
	int val1;                                         //val1 stores the value to be inserted in list
	scanf("%d",&val1); 
	printf("Enter value after which you want to insert new node: ");   
	int val;      //val stores the value of node after which new node is inserted
	scanf("%d",&val);
	if(*Headptr==NULL){            //Checking if list is EMPTY
		printf("List is Empty");
                return;
        }
	
	Node *temp= *Headptr;
	while(temp!=NULL){  //traversing the list and breaks if "value(data) of node"==val
	     
	     if(temp->data!=val) temp=temp->next;  //Checking if "value(data) of node"==val
	     else break;
	}

	if(temp==NULL){             //Checking if node with data=val exists or not.
		printf("data not Found\n");
		return;
	}
         
	Node *temp1= (Node*)malloc(sizeof(Node));   //Dynamic allocation of memory
	temp1->data= val1;        
	temp1->next=temp->next;
	temp->next=temp1;

}

void delete(Node **Headptr){ //delete function delete a node whose "data=val" where val is input by user
       printf("Enter val to be deleted: ");  //Prompting user to input the value(data) of node to be delted
       int val;                              
       scanf("%d", &val);                    //scanning value
       if(*Headptr==NULL){                   //checking if list is empty
	       printf("List is already EMPTY\n"); //print that list is empty
	       return ;                       //return to calling function
       }

       Node *temp=*Headptr;                  //temp is pointing to Head of list
       if((*Headptr)->data==val && *Headptr!=NULL){
	       while((*Headptr)->data==val){
		       Node *temp1=*Headptr;
		       *Headptr=(*Headptr)->next;
		       free(temp1);
	       }

       }

       while(temp->next!=NULL){
               if(temp->next->data==val){
		       Node *temp1=temp->next;
		       temp->next=temp->next->next;
		       free(temp1);
	       }

	       else temp=temp->next;
       }

}

void reverse(Node **Headptr){
	if(*Headptr==NULL){             //Checking if list is Empty
		printf("LIST is EMPTY");
		return;
	}
        Node *temp=*Headptr;   //temp points to Head of list
	Node *temp1;           
	Node *prev=NULL;      //prev pointer keeps track of the previous node of list
	while(temp!=NULL){    //traversing the list
              temp1=temp->next;  //temp1 points to the next node
	      temp->next=prev;  
	      prev=temp;     
	      temp=temp1;
	}

	*Headptr=prev;
}

void Printlist(Node **Headptr){   //printList function prints value(data) of linked list
	Node *temp = *Headptr;    //initialize a ponter temp of type Node and make it to point to Head of linked list
	while(temp!=NULL){        //traverse through linked list, loop breaks if temp==NULL
		printf("%d ",temp->data);  //Printing data 
		temp=temp->next;           //make temp to point to next element of linked list
	}
	printf("\n");
}

int main(){
       Node *Head =NULL;
       int N;
       printf("Enter number of nodes you want to add to linked list: ");
       scanf("%d",&N);
       
       frontPush(&Head, N); //passing address of head and number of nodes to frontPush
       printf("List is: \n");  
       Printlist(&Head);  //passing address of Head to printList, which prints the linked list
       insert(&Head);     //
       printf("New List is: \n");
       Printlist(&Head);  //passing address of Head to printList, which prints the linked list
       delete(&Head);     //passing address of Head to funtion delete,which delete a node from list
       printf("New list is: \n");
       Printlist(&Head);  //passing address of Head to printList, which prints the linked list
       reverse(&Head);    //passing address of Head to reverse fuction,the function which reverse the list
       printf("Reversed list is: \n"); 
       Printlist(&Head);  //passing address of Head to printList, which prints the linked list
       return 0;
}
