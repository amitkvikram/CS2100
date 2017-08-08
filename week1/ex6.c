#include<stdio.h>
#include<stdlib.h>

struct CLLNode{
    int data;
    struct CLLNode *next;
};

typedef struct CLLNode Node;

void createNode(Node **Headptr, int size){
    Node *tempptr= *Headptr;

    for(int i=0;i<size; i++){
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->data=i;
        temp->next=*Headptr;
        if(*Headptr==NULL){
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

void printList(Node **Headptr){
    if(*Headptr==NULL){
        printf("List is Empty\n");
        return ;
    }

    Node *tempptr=*Headptr;
    printf("%d ",tempptr->data);
    tempptr=tempptr->next;
    while(tempptr!=*Headptr){
        printf("%d ",tempptr->data);
        tempptr=tempptr->next;
    }

    printf("\n");
}

void merge(Node **Headptr1, Node **Headptr2){
    Node *tempptr1=*Headptr1, *tempptr2=*Headptr2;
    int i=0;

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

int main(){
    int size1=20;
    int size2=19;

    Node *head1= NULL;
    Node *head2= NULL;

    createNode(&head1,size1);
    createNode(&head2, size2);

    printf("List1 is: \n");
    printList(&head1);

    printf("List2 is: \n");
    printList(&head2);
    printList(&head2);
    merge(&head1,&head2);
    printf("\nNew List after merging is: \n");
    printList(&head1);

    return 0;
}
    
