#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next; //ponter to next node in linked list
};

typedef struct Node Node; // setting alias "Node" for struct Node

void frontPush(Node **Headptr, int N){
       printf("Enter the %d nodes you want to add:\n",N);
       int tempData;
       for(int i=0;i<N;i++){
	       scanf("%d",&tempData);
	       Node *temp= (Node*) malloc(sizeof(Node));
	       temp->data= tempData;
	       temp->next= *Headptr;
	       *Headptr= temp;
       }
}

void push(Node **Headptr, int N){
	printf("Enter the %d nodes you want to add: \n",N);
	int tempData;
	Node *tempHead= *Headptr;
	for(int i=0;i<N;i++){
		scanf("%d",&tempData);
		Node *temp=(Node*) malloc(sizeof(Node));
		temp->data=tempData;
		temp->next=NULL;
		if(tempHead==NULL){
                    *Headptr=temp;
		    tempHead=temp;
		}

		else{
		      while(tempHead->next!=NULL){
			      tempHead=tempHead->next;
		      }
		      tempHead->next=temp;
		}

	}
}

void insert(Node **Headptr){
	printf("Enter val you want to insert in list: ");
	int val1;
	scanf("%d",&val1);
	printf("Enter value after which you want to insert new node: ");
	int val;
	scanf("%d",&val);
	if(*Headptr==NULL){
		printf("List is Empty");
                return;
        }
	
	Node *temp= *Headptr;
	while(temp!=NULL){
	     
	     if(temp->data!=val) temp=temp->next;
	     else break;
	}

	if(temp==NULL){
		printf("data not Found\n");
		return;
	}
         
	Node *temp1= (Node*)malloc(sizeof(Node));
	temp1->data= val1;
	temp1->next=temp->next;
	temp->next=temp1;

}

void delete(Node **Headptr){
       printf("Enter val to be deleted: ");
       int val;
       scanf("%d", &val);
       if(*Headptr==NULL){
	       printf("List is already EMPTY\n");
	       return ;
       }

       Node *temp=*Headptr;
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
	if(*Headptr==NULL){
		printf("LIST is EMPTY");
		return;
	}
        Node *temp=*Headptr;
	Node *temp1;
	Node *prev=NULL;
	while(temp!=NULL){
              temp1=temp->next;
	      temp->next=prev;
	      prev=temp;
	      temp=temp1;
	}

	*Headptr=prev;
}

void Printlist(Node **Headptr){
	Node *temp = *Headptr;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	return;
}

int main(){
       Node *Head =NULL;
       int N;
       printf("Enter number of nodes you want to add to linked list: ");
       scanf("%d",&N);
       
       //frontPush(&Head, N);
       push(&Head, N);
       printf("List is: \n");
       Printlist(&Head);
       insert(&Head);
       printf("New List is: \n");
       Printlist(&Head);
       delete(&Head);
       printf("New list is: \n");
       Printlist(&Head);
       reverse(&Head);
       printf("Reversed list is: \n");
       Printlist(&Head);
       return 0;
}
