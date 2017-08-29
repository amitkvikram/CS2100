/*
  Problem Name:Ex1
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:29/08/2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char movieName[100]; //movieName stores the name of movie
	struct stack *next; //ponter to next node in stack
};

int stackSize=0;    //stackSize stores size of Stack

typedef struct stack stack;  // setting alias "stack" for "struct stack"

//stackTop prints the top of Stack
void stackTop(stack **Topptr){   
        if(!(*Topptr)){                               //Checks if stack is empty
		printf("4.stackTop: Stack is empty\n");
		return;
	}
	printf("4.stackTop: %s\n", (*Topptr)->movieName);
	return;
}

//stackPush pushes new element at the top of Stack
void stackPush(stack **Topptr ){
	printf("How many you wants to add: ");
	int n;
	scanf("%d",&n);
	int i;
	char str1[100];
	for(int i=0;i<n;i++){
		stackSize++;
		stack *temp= (stack*)(malloc(sizeof(stack)));
		printf("1.PUSH. Enter Name of %dth Movie: ", i);
		scanf(" %[^\n]s",temp->movieName);
		temp->next= *Topptr;
		*Topptr= temp;
	}
}

//stackPop deletes and returns top of stack
char* stackPop(stack **Topptr){
	if(!(*Topptr)){                    //Checks if stack is empty
		printf("Stack is empty\n");
		return NULL;               //returns NULL if string is empty
	}
	stackSize--;
	stack *temp= *Topptr;
	static char str1[100];
	strcpy(str1,(*Topptr)->movieName);
	*Topptr=(*Topptr)->next;
	free(temp);
	return str1;
}	

//isempty returns 1 if list is empty else returns 0
int isEmpty(stack **Topptr){
	if(!(*Topptr)){     //Checks if stack is empty
		return 1;
	}
	return 0;
}

//main function begins here	
int main(){
	stack *Top=NULL;  //Top Pointer points to top of stack
	stackPush(&Top);  //Passing adress of Top to function stackPush
	if(isEmpty(&Top)) printf("3.isEmpty: Stack is Empty\n");  //Passing adress of Top to function isEmpty
	else printf("3.isEmpty: Stack is Not Empty\n");
	stackTop(&Top);                                          //Passing adress of Top to function stackTop
	char *str= stackPop(&Top);                               //Passing adress of Top to function stackPop
	printf("2.POP. Movie: %s\n",str);
	if(isEmpty(&Top)) printf("3.isEmpty: Stack is Empty\n"); //Passing adress of Top to function stackPush
	else printf("3.isEmpty: Stack is Not Empty\n");
	stackTop(&Top);          			         //Passing adress of Top to function stackTop    
 	printf("SIZE: %d\n",stackSize);
 	return 0;	
}
//main function Ends here	
	 
	

