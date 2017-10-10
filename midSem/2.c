/*
 MID-SEM EXAMINATION
 Name: Amit Vikram Singh
 Roll No: 111601001
 IP Address: 10.64.1.193
 Set Number: A
 Problem No: 02

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char plateNumber[100]; //plateNumber stores the plate number of vehicle
	struct stack *next; //ponter to next node in stack
};

typedef struct stack stack;  // setting alias "stack" for "struct stack"

//stackPush pushes new element at the top of Stack
void stackPush(stack **Topptr , char *str){
		stack *temp= (stack*)(malloc(sizeof(stack))); 	
		strcpy(temp->plateNumber, str);
		temp->next= *Topptr;
		*Topptr= temp;
}


//stackPop deletes and returns top of stack
char* stackPop(stack **Topptr){
	if(!(*Topptr)){                    //Checks if stack is empty
		printf("Stack is empty\n");
		return NULL;               //returns NULL if string is empty
	}
	stack *temp= *Topptr;
	static char str1[100];
	strcpy(str1,(*Topptr)->plateNumber);
	*Topptr=(*Topptr)->next;	//resetting the position of head
	free(temp);		//free memory 
	return str1;	//return plate number at top
}

//isempty returns 1 if list is empty else returns 0
int isEmpty(stack **Topptr){
	if(!(*Topptr)){     //Checks if stack is empty
		return 1;
	}
	return 0;
}

//Inserting plate number of new vehicle
void Insert(stack **Topptr1, stack **Topptr2){
	char str[100];
	char *str1;
	printf("Enter Plate Number: ");
	scanf("%s", str);
	while(!isEmpty(Topptr1)){ //Pop all elements of stack1 and push is stack2
		str1 = stackPop(Topptr1);
		stackPush(Topptr2, str1);
	}
	
	stackPush(Topptr1, str);	//Inserting plate number of new vehicle 
	
	while(!isEmpty(Topptr2)){ //Pop all elements of stack2 and push is stack1
		str1 = stackPop(Topptr2);
		stackPush(Topptr1, str1);	
	}
	printf("\n");
}

//Displying the plate number of all the vehicles to be serviced
void Display(stack **Topptr1, stack **Topptr2){
	char *str1;
	int i =0;
	printf("List of Vehicles is: \n");
	while(!isEmpty(Topptr1)){
		i++;
		str1 = stackPop(Topptr1);
		printf("%d: %s\n",i, str1);
		stackPush(Topptr2, str1);
	}
	
	while(!isEmpty(Topptr2)){
		str1 = stackPop(Topptr2);
		stackPush(Topptr1, str1);
	}
	
	printf("\n");
}

//Free the memory 	
void Exit(stack **Topptr1, stack **Topptr2){
	while(!isEmpty(Topptr1)){
		stackPop(Topptr1);	//Calling repeatedly stackPop function to clear the memory of stack1
	}
	
	while(!isEmpty(Topptr2)){
		stackPop(Topptr2);	//Calling repeatedly stackPop function to clear the memory of stack2
	}	

}

//MAIN BEGINS HERE
int main(){
	int flag = 1;
	int option;	//variable to store the option choose bu user
	char plateNumber[100]; //string to store plate number
	stack *Top1 = NULL;   //Top1 is pointer to the head of first stack
	stack *Top2 = NULL;   //Top2 is pointer to head of second stack
	
	while(flag){
		printf("Options\nInsert:Enter 1  Next: Enter 2  Display: Enter 3  Exit: Enter 4\n");
		printf("Enter your option: ");
		scanf("%d", &option);
		if(option == 1){
			Insert(&Top1, &Top2);	//Inserting new plate number
		}
		
		else if(option == 2){	
			if(isEmpty(&Top1)) printf("List is Empty\n");
			else{
				char *str = stackPop(&Top1);  //Displaying and deleting next cat to be serviced
				printf("Next Car to be serviced is: %s\n\n", str);
			}
		}
		
		else if(option == 3){
			if(isEmpty(&Top1)) printf("List is Empty\n");
			else Display(&Top1, &Top2);	//Displaying plate number of cars to be serviced
		}
		
		else if(option == 4){
			printf("Exiting\n");
			Exit(&Top1, &Top2);	//Free memory and exit
			flag =0;
		}
		else{
			printf("Unknown option....Exiting\n");
			Exit(&Top1, &Top2);	//Free memory and exit
			flag = 0;
		}
	}

return 0;
}
//MAIN ENDS HERE
				
