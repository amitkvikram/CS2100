/*
 MID-SEM EXAMINATION
 Name: Amit Vikram Singh
 Roll No: 111601001
 IP Address: 10.64.1.193
 Set Number: A
 Problem No: 03
 Logic: First Check if palindrome of given strnig exists, if exists make first palindrome(using for loop) and then call a function recursively to make other
*/

#include<stdio.h>
#include<string.h>

swap(char *ch1, char *ch2){
	char *temp = *ch1;
	*ch1 = *ch2;
	*ch2 = *temp;
}

void Palindrome_Permutation(char *str, int len){
	
		
}

int main(){
	char str[100];
	printf("Enter String: ");
	scanf("%s", str);
 	
 	int arr[26] = {0};
 	
 	int len = strlen(str);
 	char str1[100];
 	int i=0;
 	
 	//Counting how many times each character occurs in given string
 	for(i =0; i<len; i++){
 		arr[str[i] - 'a'] ++;
 	}
 	
 	int num = 0, index = 0;
 	
 	for(int i = 0; i<26; i++){
 		if(arr[i]%2 != 0) {
 			num ++;
 			index = i;
 		}
 	}
 	
 	 //Checking if possible to make palindrome of given string
 	if(num>1) {   
 		printf("No palindrome of given string exist\n");
 		return 0;   //Exiting if no palondromic permutation of given string exist
 	}
 	
 	//Making first palindrome of string
 	if(num == 0){
 		int j =0 ;
 		for(i = 0; i<26; i++){
 			while(arr[i] > 0){
 				str1[j] = 'a' + i;
 				str1[len-1-j] = 'a' + i;
 				j++;
 			}
 		}
 	}
 	
 	else{
 		printf("%d   ", index);
 		str1[len/2] = index + 'a';
 		arr[index]--;
 		int j = 0;
 		for(i = 0; i<26; i++){
 			while(arr[i] > 0){
 				str1[j] = 'a' + i;
 				str1[len-1-j] = 'a' + i;
 				j++;
 				arr[i]-=2;
 			}
 		}
 	}
 		
 
 	printf("%s\n", str1);
 	void Palindrome_Permutation(str1, len, 0);  //calling Palindrome_Permutation to print all the palindrome of given string
 	
 	return 0;
 }
