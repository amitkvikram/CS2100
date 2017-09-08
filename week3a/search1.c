/*
  Problem Name:Ex1
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:08/09/2017
*/

#include<stdio.h>

int main(){
	int n;    		//length of input list
	printf("Length of list: ");
	scanf("%d", &n);
	float arr[n];		//array 
	int i;
	printf("List: ");
	for(i =0;i<n;i++){	//taking input
		scanf("%f", &arr[i]);
	}
	printf("Target Value: ");
	float val;       	//target value
	scanf("%f", &val);
	for(i=0; i<n;i++){	//checking for target value in list
		if(arr[i]<val+1e-6 && arr[i]>val-1e-6){
			break;		//breaks out of for loop if target value is found in list
		}
	}
	
	if(i==n) printf("No\n");
	else printf("Yes\n");
	
	return 0;
}
