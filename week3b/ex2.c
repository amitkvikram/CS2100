/*
  Problem Name:Ex2
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Date:12/09/2017
*/

#include<stdio.h>

//swap function takes address of two elements of array as arguments and swaps the elements
void swap(int *a, int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}


//BubbleSort function which sorts the array	
void BubbleSort(int *arr, int n){
	int i, j;	
	for(i=0;  i<n; i++){
		for(j= n-1; j>i; j--){
		      if(arr[j]>arr[j-1]) swap(&arr[j], & arr[j-1]);//Comparing two consecutive elements of array and sorting them in descending order
		}
	}
}
	
//main begins here	
int main(){
	printf("Enter length of array: ");  
 	int n; 				//length of array
 	scanf("%d", &n);
 	int arr[n];			//array to store the elements
 	printf("Enter elements of array: ");
 	int i=0;
 	for(i=0; i<n; i++){
 		scanf("%d", &arr[i]);
 	}
 	
 	BubbleSort(arr, n);		//calling function BubbleSort which sorts the array in descending order
 	printf("Sorted Array: ");
 	for(i=0; i<n; i++){
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
 	
 	return 0;
 }
 //main ends here	
 	
 	
