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

void insert(Node **Headptr){ //Headptr is a pointer to the "Head pointer"
       printf("Enter number of nodes you want to insert: ");  //promting user to input the number of node he/she wants to insert in                                                                 list
       int n;                                                 //n stores number of node to be inserted  
       scanf("%d",&n);
       if(n!=0) printf("Enter %d nodes you want to insert: ",n);     //promting user to insert n nodes      
       for(int i=0;i<n;i++){    
	       int tempData;       
               scanf("%d",&tempData);
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
		
void search(Node **Headptr){
    printf("Enter the value of node you want to search: ");
    int tempData;            //tempData stores value to be searched
    scanf("%d",&tempData);
    Node *tempptr=*Headptr;
    int index=0;           //stores the position at which value(tempData) is found
    while(tempptr!=NULL){  //traverse the list, loop breaks if "value(data) of node"=val OR we reach at end of list
        if(tempptr->data!=tempData){ //Checking if "value(data) of node"= tempData
        	tempptr=tempptr->next;
        	index++;          //inrementing index by 1
        }
        else {      //Checks if we found the node with data=tempData
            index++;
            break;
        }
    }
    
    if(tempptr==NULL){    //Checking if value exist or not in linked list
        printf("Value not found in list\n");
        return;
    }

    printf("Value found at position: %d\n",index);
}


int main(){
	Node *Head;        //Pointer to first node of list
	Head= NULL;
	insert(&Head);     //Passing address of Head to insert function, the insert function inserts n nodes in list
        Printlist(&Head);  //Passing address of Head to printList function,printList funtion prints the list
        search(&Head);     //Passing address of Head to search function, search function searches a value in list
       	return 0;
}

