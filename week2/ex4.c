/*
  Problem Name:Ex4
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:22/08/2017
*/

#include<stdio.h>

//CHECKING IF PALINDROME
int Palindrome(char *begin,char *end, int size1){  //begin acts like a forward pointer and end like a reverse pointer
	if(size1==0) return 1;                     //returning 1 if we have found that string is palindrome
	if(*begin!=*end) return 0;		   //checking if pair of character pointed by "begin" and "end" are equal or not
	size1--; 
	begin++;                                   //moving pointer "begin" to next character of string
	end--;                                     //moving pointer "end" to previous character of string
	return Palindrome(begin, end, size1);
}

//BEGINNING OF MAIN FUNCTION
int main(){
	int size; 				//size stores size of the string
	printf("Enter size of string: "); 
	scanf("%d", &size);
	char str[size+1];                       
	printf("Enter String: ");
	scanf("%s",str);
	int size1= size/2;
	int flag= Palindrome(str, str+size-1, size1);  //calling function Palindrome to check if string is palindrome OR not
	if(flag==0) printf("NOT PALINDROME\n");
	else printf("PALINDROME\n");
}
//END OF MAIN FUNCTION
	
	
	
