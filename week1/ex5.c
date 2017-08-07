/*
 * Programme Name: Ex5.c
 * Programmer's Name: Amit Vikram Singh
 * Roll no.: 111601001
 * Email-id: 111601001@smail.iitpkd.ac.in
 * Date: 01/08/2017
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int ID;               //Variable to store ID of student
    char Name[40];        //Variable to store the name of student
    struct student *next; //pointer to next node of linked list
    struct student *prev; //pointer to previous node of linked list
};

typedef struct student student; //Setting alias "student" for "struct student"

void TakeInput(student **Headptr, int N){ //Headptr is a pointer to pointer to head
        student *tempptr= *Headptr; //tempptr points to the head of list
        char name[40]; //stores name of student
        int ID;       //stores ID of student
        for(int i=0;i<N;i++){
            scanf("%s %d",name,  &ID);
            student *temp= (student*)malloc(sizeof(student)); //Dynamically Allocating Memory
            temp->ID=ID;
            strcpy(temp->Name,name);
            
            temp->next=NULL;
            if(*Headptr==NULL){
                *Headptr=temp;
                temp->prev=*Headptr;
                tempptr=*Headptr;
            }
            else{
                temp->prev=tempptr;
                tempptr->next=temp;
                tempptr=temp;
            }

        }
}

void Printlist(student **Headptr){
    if(*Headptr==NULL){
        printf("LIST is EMPTY\n");
        return;
    }
    student *tempptr= *Headptr;
    int i=0;
    while(tempptr!=NULL){
        printf("%s\n", tempptr->Name);
        printf("%d\n", tempptr->ID);
        tempptr=tempptr->next;

    }
}

void student_with_maxID(student **Headptr){
    student *tempptr= *Headptr;
    if(tempptr==NULL){
        printf("List is EMPTY");
        return;
    }

    int maxID= tempptr->ID;
    char name[40];
    strcpy(name, tempptr->Name);
    int index=0, i=0;
    while(tempptr!=NULL){
        if(tempptr->ID>maxID){
            maxID=tempptr->ID;
            strcpy(name, tempptr->Name);
            index=i;
        }
        else i++;
        tempptr=tempptr->next;
    }

    printf("Student with largest ID is: %s\n", name);
}

int main(){
    student *Head=NULL;
    int N;
    scanf("%d",&N);
    TakeInput(&Head, N);
    printf("List of Students is: \n");
    Printlist(&Head);
    student_with_maxID(&Head);
}    
    

