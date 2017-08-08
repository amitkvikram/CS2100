/*
 * Problem Name: Ex1
 * Name: Amit Vikram Singh
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


typedef struct student student;      //Creating alias for data type struct student as "student"

void Update(student *stuptr){        //Update function actually changes the name and ID of stu1, Here stuptr is a pointer to stu1
        strcpy(stuptr->name,"abc");  //Changing the name of stu1 to "abc"
	stuptr->ID=123;              //Changing ID of stu1 to "123"
}

void PrintStruc(student *stuptr){      //stuptr is a pointer to stu1
	printf("Name: %s  ID: %d\n\n", stuptr->name,stuptr->ID);  //Printing name and ID of stu1
	return;
}

int main(){
    student stu1={"Amit", 111601001}; //initializing variable "stu1" of data type "student"
    printf("Details of stu1: \n");
    PrintStruc(&stu1);                //calling function Printstruc
    Update(&stu1);                    //calling function Update
    printf("Details of stu1(Changed): \n");
    PrintStruc(&stu1);                //calling function Printstruc
    return 0;
}
