#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

void createNode(Node **Headptr){
    Node *tempptr =*Headptr;
    for(int i=0; i<3; i++){
        Node *temp= (Node*)malloc(sizeof(Node));
        temp->data=i;
        temp->next=NULL;
        if(*Headptr==NULL){
            *Headptr = temp;
            tempptr=*Headptr;
            printf("amit");
        }

        else{
            tempptr->next= temp;
            tempptr= tempptr->next;
        }

    }
}

void nthNode_from_end(Node **Headptr, int n){
       
    Node *ptemp=*Headptr, *ftemp=*Headptr;
    int i=1;
    while(ptemp!=NULL){
        if(i==n){
            break;
        }
        i++;
        ptemp= ptemp->next;
    }

    if(ptemp==NULL){
        printf("Not Sufficient Node\n");
        return;
    }
    ptemp=ptemp->next;
    while(ptemp!=NULL){
        ftemp=ftemp->next;
        ptemp=ptemp->next;
    }
    printf("nth Node from End is: %d\n",ftemp->data); 

}


void printList(Node **Headptr){
    if(*Headptr==NULL){
        printf("List is EMPTY\n");
        return ;
    }
    Node *tempptr=*Headptr;

    while(tempptr!=NULL){
        printf("%d ", tempptr->data);
        tempptr=tempptr->next;
    }

    printf("\n");
}


int main(){
    Node *head;
    head = NULL;

    createNode(&head);
    printList(&head);
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    nthNode_from_end(&head , n);
}
