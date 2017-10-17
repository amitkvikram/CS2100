/*
 * Problem Name:Ex4.c
 * Programmer's Name: Amit Vikram Singh
 * Roll No.: 111601001
 * Email-id: 111601001@smail.iitpkd.ac.in
 * Date: 07/08/2017
 */

#include<stdio.h>
#include<stdlib.h>

struct CLLNode{               //user defined data type(structure) CLLNode 
	int data;             //data stores the value of node
	struct CLLNode *next; //Pointer to next node in Circular linked list
};

typedef struct CLLNode Node; //setting alias "Node" for "struct CLLNode"

int ValueAtGivenPosition(Node **Headptr, int pos){
	     Node *tempptr=*Headptr;    
      if(*Headptr==NULL){              //Checking if list is EMPTY
	      printf("List is EMPTY\n");
	      return -1;
      }
      
      int i =0;	
      while(i<pos){   
	      i++;
              tempptr=tempptr->next;
      }

     return tempptr->data;
}

void insert(Node **Headptr, int tempData){ //Headptr is a pointer to the "Head pointer"             
	       Node *temp= (Node*)malloc(sizeof(Node));     //Dynamically Allocating memory ponted by "temp"
	       temp->data=tempData;
	       if(*Headptr==NULL){
		       *Headptr=temp;
		       temp->next=*Headptr;
	       } 

	       else{
			temp->next=*Headptr;
			Node*tempptr= *Headptr;
			while(tempptr->next!=*Headptr){
				tempptr=tempptr->next;
			}

			tempptr->next=temp;
	       }
}

void Printlist(Node **Headptr){         //Headptr is pointer to pointer Head
      Node *tempptr=*Headptr;    
      if(*Headptr==NULL){              //Checking if list is EMPTY
	      printf("List is EMPTY\n");
	      return;
      }

      while(tempptr->next!=*Headptr){   
	      printf("%d ", tempptr->data);
              tempptr=tempptr->next;
      }

      printf("%d\n",tempptr->data);
}
		
void search(Node **Headptr, int tempData){          
    Node *tempptr=*Headptr;
    int index=0;           //stores the position at which value(tempData) is found
    do{  //traverse the list, loop breaks if "value(data) of node"=val OR we reach at end of list
        if(tempptr->data!=tempData){ //Checking if "value(data) of node"= tempData
        	tempptr=tempptr->next;
        	index++;          //inrementing index by 1
        }
        else {      //Checks if we found the node with data=tempData
            index++;
            break;
        }
    }while(tempptr!=*Headptr);
    
    if(tempptr==*Headptr && index!=1){    //Checking if value exist or not in linked list
        printf("Value not found in list\n");
        return;
    }

    printf("Value found at position: %d\n",index);
}

void FreeMemory(Node **Headptr){
	Node *tempptr=*Headptr;
	Node *temp1;
	if(tempptr==NULL) return;
	tempptr=tempptr->next;
	while(tempptr->next!=*Headptr){   
	      temp1=tempptr;
	      tempptr=tempptr->next;
	      free(temp1);
        }
        
        free(*Headptr);
 }


