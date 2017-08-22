/*
  Problem Name:Ex3
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:22/08/2017
*/

#include<stdio.h>

int n;

void Print(int n){
	if(n==-1) return;
	printf("%d ", n);
	Print(n-1);
}

int main(){
	printf("Enter value of n: ");
	scanf("%d",&n);
	Print(n);
	return 0;
}
