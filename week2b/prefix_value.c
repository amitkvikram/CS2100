/*
  Problem Name:Ex3
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:05/09/2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

struct stack{
	float element; //element in expression
	struct stack *next; //ponter to next node in stack
};

int stackSize=0;    //stackSize stores size of Stack

typedef struct stack stack;  // setting alias "stack" for "struct stack"

//Operation function takes two intager and one operator as character and returns result after applying operator on integers
float Operation(float temp1, float temp2, char ch){
      float result= (ch=='+')?(temp1+temp2):((ch=='*')?(temp1*temp2):((ch=='/')?(temp1/temp2):(temp1-temp2)));
      return result;
}

//stackPush pushes new element at the top of Stack
void stackPush(stack **Topptr ,float Data){
            // int(Data);
		stackSize++;
		stack *temp= (stack*)(malloc(sizeof(stack)));
            temp->element=Data;
		temp->next= *Topptr;
		*Topptr= temp;   //resetting top of sta

}

//stackPop deletes and returns top of stack
float stackPop(stack **Topptr){
	if(!(*Topptr)){                    //Checks if stack is empty
            return INT_MAX;//returns INT_MAX if stack is empty
	}
	stackSize--;
	stack *temp= *Topptr;
	float topValue= (*Topptr)->element;
	*Topptr=(*Topptr)->next;   //resetting top
	free(temp);       //deallocation memory
	return topValue;
}

//Beginning of main function
int main(){
      stack *Top= NULL;
      printf("enter your prefix expression: ");
      char str[100];  //str stores the expression
      scanf("%s",str);
      int i;
      for(i=strlen(str)-1;i>=0;i--){
            if(0<=(str[i]-'0') && (str[i]-'0')<10){ //checking if element is an number.
                  stackPush(&Top,(str[i]-'0')); //pushes element on stack if it is an integer.
                  //printf("ami%d",(str[i]-'0'));
            }

            else{

                  float temp1=stackPop(&Top);
                  float temp2=stackPop(&Top);  //temp1 and temp2 are top2 element of stack
                 
                  stackPush(&Top, Operation(temp1, temp2, str[i]));  //calling Operation function
            }
      };

      printf("Result = %f\n",stackPop(&Top));
}
//main function ends here
