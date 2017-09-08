/*
  Problem Name:Ex4
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:05/09/2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char element; //element in expression
	struct stack *next; //ponter to next node in stack
};

int stackSize=0;    //stackSize stores size of Stack

typedef struct stack stack;  // setting alias "stack" for "struct stack"

//stackTop returns the top of Stack
char stackTop(stack **Topptr){
        if(!(*Topptr)){                               //Checks if stack is empty
		return '\0';
	}
	return ((*Topptr)->element);
}

//Checks Precedence of current operator with operator at the top of stack
int Precedence(stack **Topptr, char ch){
      int ch1=stackTop(Topptr);
      if(ch1!='(' && ch1 !='\0'){
            if(ch=='*' || ch=='/'){
                  if(ch1=='*' || ch1=='/'){
                        return 0;          //rerturns 0 if current operator has equal Precedence than operator at top of stack
                  }
                  else return 1;           //returns 1 if current operator has higher Precedence than operator at top of stack
            }

            else{
                  if(ch1=='*' || ch1=='/'){
                        return -1;        //rerturns -1 if current operator has equal Precedence than operator at top of stack
                  }
                  else return 0;          //rerturns 0 if current operator has equal Precedence than operator at top of stack
            }
      }
      else return 2;     //returns 2 if either stack is empty or operator at top of stack is '('
}

//Checks associativity of operator
int Association(stack **Topptr, char ch){
      if(ch=='+' || ch=='-' ||  ch=='*' || ch=='/') return 1; //returns 1 if associativity is left-to-right
      else return 0;
}


//isempty returns 1 if list is empty else returns 0
int isEmpty(stack **Topptr){
	if(!(*Topptr)){     //Checks if stack is empty
		return 1;
	}
	return 0;
}

//stackPush pushes new element at the top of Stack
void stackPush(stack **Topptr ,char Data){
            // int(Data);
		stackSize++;
		stack *temp= (stack*)(malloc(sizeof(stack)));
            temp->element=Data;
		temp->next= *Topptr;
		*Topptr= temp;   //resetting top of stack

}

//stackPop deletes and returns top of stack
char stackPop(stack **Topptr){
	if(!(*Topptr)){                    //Checks if stack is empty
		printf("Stack is empty\n");
                  return '\0';   //returns NULL if stack is empty
	}
	stackSize--;
	stack *temp= *Topptr;
	char topValue= (*Topptr)->element;
	*Topptr=(*Topptr)->next;   //restting Top
	free(temp);       //deallocation memory
	return topValue;
}

//main function begins here
int main(){
      stack *Top= NULL;
      printf("enter your infix expression: ");
      char str[100];  //str stores the expressio
      scanf("%s",str);
      printf("prefix expression: ");
      for(int i=0;i<strlen(str);i++){
            if(0<=(str[i]-'0') && (str[i]-'0')<10){ //checking if element is an integer.
                  printf("%d",(str[i]-'0'));
            }

            else{
                  if(isEmpty(&Top) || stackTop(&Top)=='(') stackPush(&Top, str[i]);  //pushes new operator
                  else{
                        char ch=str[i];
                        if(ch==')'){
                              char temp=stackPop(&Top);
                              while(temp!='('){
                                    printf("%c",temp);
                                    temp=stackPop(&Top);
                              }
                        }
                        else if(Precedence(&Top,ch)==1){    //current operator has higer Precedence than operator at top of stack
                              stackPush(&Top, str[i]);
                        }

                        else if(Precedence(&Top, ch)==0){   //current operator has equal Precedence than operator at top of stack
                              if(Association(&Top, ch)){
                                    printf("%c\n",stackPop(&Top) );
                                    stackPush(&Top, ch);
                              }
                              else{
                                    stackPush(&Top, ch);
                              }
                        }

                        else{
                              char ch1=ch;
                              while(!isEmpty(&Top) && ch!='(' && Precedence(&Top, ch)<0){
                                    printf("%c",stackPop(&Top));
                                    ch=stackTop(&Top);
                              }
                              if(Precedence(&Top, ch)==0){
                                    if(Association(&Top, ch)){
                                          printf("%c\n",stackPop(&Top) );
                                          stackPush(&Top, ch);
                                    }
                                    else{
                                          stackPush(&Top, ch);
                                    }
                              }
                              else{
                                    stackPush(&Top, str[i]);
                              }
                        }
                  }
            }
      }

      while(!isEmpty(&Top)){
            printf("%c",stackPop(&Top));
      }
      printf("\n");
}
//main function ends here
