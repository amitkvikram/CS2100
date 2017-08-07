/*
 * Problem Name: Ex2.c
 * Name:Amit Vikram Singh
 * Roll No.: 111601001
 * Email-id: 111601001@smail.iitpkd.ac.in
 * Date: 01/08/2017
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{          //User defined data type(structure) "student"
	char name[100];  //Variable to store Name  of student 
	int ID;          //Variable to store ID of student
};

typedef struct student student;          //Creating alias "student" for "struct student"

void takeInput(student **listptr, int N){      //function takes Input from user
	
	printf("Enter the name and ID of %d Student:\n",N);

	for(int i=0;i<N;i++){
		student *tempptr= (*listptr)+i;
        printf("Name: ");
		scanf("%s",(tempptr)->name);    //scanning name of i(th) student
        printf("ID: ");
		scanf("%d", &(tempptr)->ID);    //scnning ID of i(th) student
	}
}


int maxID(student **listptr, int N){            //function which return the index of student with maximum ID, listptr is a pointer to pointer "list"
	int index=0;
	int max=(*listptr)->ID;                 //initially setting the value of max equal to ID of first student
	for(int i=0;i<N;i++){
		if((*listptr+i)->ID>max){       //Checking if the ID of current student is greater than current maximum ID
			max=(*listptr+i)->ID;
			index=i;
	        }
	}
	return index;                           //returning the index of student with maximum ID
}

int main(){
	int N;
	printf("Enter number of Students: ");
	scanf("%d", &N);
        
	student *list;                                  //initializing pointer to data type student
	list=(student*) malloc(N * sizeof(student));    //allocating memory block
        takeInput(&list, N);                            //calling the function takeInput
        int maxId_index= maxID(&list, N);               //Variable maxId_index stores the index of student with maximum ID
        printf("Student with Maximum Id is:\nName:%s  ID:%d\n",(list+maxId_index)->name,(list+maxId_index)->ID); //printing the name of Student having maximum ID
	free(list);                                     //free the allocated memory block pointed by pointer "list"
	return 0;
}
