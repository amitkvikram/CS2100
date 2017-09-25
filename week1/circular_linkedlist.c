/*
  Problem Name:Ex6
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:15/08/2017
*/
#include<stdio.h>
#include<stdlib.h>

struct CLLNode{
    int data;
    struct CLLNode *next;  //Pointer to next node in linked list
};

int size1;  //size1 stores the size of first linked list
int size2;  //size2 stores the size of second linked list

typedef struct CLLNode Node;   // setting alias "Node" for "struct CLLNode"

void createNode(Node **Headptr, int size){   //Creates linked list.
    Node *tempptr= *Headptr;
    printf("Enter %d nodes you want to add: ",size);
    int tempData;
    for(int i=0;i<size; i++){
          scanf("%d",&tempData);
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->data=tempData;
        temp->next=*Headptr;
        if(*Headptr==NULL){   //Checking if first node is being added.
            *Headptr= temp;
            temp->next=*Headptr;
            tempptr=temp;
        }

        else{
            tempptr->next=temp;
            tempptr=tempptr->next;
        }
    }
}

void printList(Node **Headptr){  //printList function prints the element of linked list. Headptr is a pointer to pointer to Head
    if(*Headptr==NULL){          //Checks if list is empty or not
        printf("List is Empty\n");
        return ;                 //returns if list is empty
    }

    Node *tempptr=*Headptr;
    printf("%d",tempptr->data); //printing out the element
    tempptr=tempptr->next;

    while(tempptr!=*Headptr){
        if(tempptr!=*Headptr) printf("->");
        printf("%d",tempptr->data);
        tempptr=tempptr->next;  //moving to next node
    }

    printf("\n");
}

void merge(Node **Headptr1, Node **Headptr2){  //merge function inserts element of second list at alternate position in first list.
    Node *tempptr1=*Headptr1, *tempptr2=*Headptr2;    //Headptr1 and Headptr2 are pointer to pointer to head of list1 and list2 respectively

        Node *temp=tempptr2->next;
        tempptr2->next=tempptr1->next;
        tempptr1->next=tempptr2;
        tempptr1=tempptr2->next;
        tempptr2=temp;

    while(tempptr2!=*Headptr2){
        Node *temp=tempptr2->next;
        tempptr2->next=tempptr1->next;
        tempptr1->next=tempptr2;
        tempptr1=tempptr2->next;
        tempptr2=temp;
    }
}

void FreeMemory(Node **Headptr){  //deallocate the dynamically allocated memory d
      if(*Headptr==NULL) return; //returns to main if list is empty.

      Node *tempptr= (*Headptr)->next;
      while(tempptr!=*Headptr){
            Node *temp=tempptr;
            tempptr=tempptr->next;
            free(temp);
      }

      free(*Headptr);
}

int main(){
    Node *head1= NULL;  //pointer to head of first list
    Node *head2= NULL;  //pointer to head of second list
    printf("Enter size of first list: ");
    scanf("%d",&size1);
    createNode(&head1,size1);   //Creating first circular linked list
    printf("Enter size of Second list(less than the size of first list): ");
    scanf("%d",&size2);
    if(size2>=size1) {
          printf("size2 is not less than size1");
          return 0;
    }
    else createNode(&head2, size2);   //Creating second circular linked list

    printf("List1 is: \n");
    printList(&head1);   //passing adress of head of first list to function printList, printList function prints element of list.

    printf("List2 is: \n");
    printList(&head2);   //passing adress of head of second list to function printList, printList function prints element of list.
    merge(&head1,&head2);
    printf("\nNew List after merging is: \n");
    printList(&head1);
    FreeMemory(&head1);   //frees dynamic memory allocated to first list
    FreeMemory(&head2);   //frees dynamic memory allocated to second list

    return 0;
}
