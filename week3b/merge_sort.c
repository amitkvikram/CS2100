/*
  Problem Name:Ex1
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Date:12/09/2017
*/

#include<stdio.h>

void Merge(int *arr, int low, int mid, int high){
	int n1= mid-low+1;	  //n1 stores Length of left subarray
	int n2= high-mid;         //n2 stores Length of Right subarray
	int Left[n1], Right[n2];  //Left stores left half of subarray and Right stores right half of subarrays
	int i;
	
	//Copying left half and right half of subarrays in two separate arrays 
	for(i=0;i<n1; i++){
		Left[i]= arr[low+i];
	}
	for(i=0; i<n2; i++){
		Right[i]= arr[mid+i+1];
	}
	
	i=0; 
	int j=0, k=low;
	
	//Merging Subarrays
	while(i<n1 && j<n2){
		if(Left[i]<Right[j]) {
			arr[k] =Left[i];
			i++;
		}
		else {
			arr[k]= Right[j];
			j++;
		}
		k++;
	}
	
	//copying remaining elements of Left and Right into arr
	for(;i<n1;i++){
		arr[k]= Left[i];
		k++;
	}
	
	for(;j<n2; j++){
		arr[k]= Right[j];
		k++;
	}
	
}
	

void MergeSort(int *ptr, int low, int high){	//ptr is pointer to array, low is lower index of subarray , high is ending index of subarray
	if(low>=high) return;		//returns if number of element in subarray is 1;
	int mid= (low+high)/2;		//mid is middle index of array
	MergeSort(ptr, low, mid);	//calling MergeSort for left half of subarray
	MergeSort(ptr, mid+1, high);    //calling MergeSort for right half of subarray
	Merge(ptr, low, mid, high);	//Merging left and right half of subarray
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
 	
 	MergeSort(arr, 0, n-1);		//calling function MergeSort which sorts the array
 	printf("Sorted Array: ");
 	for(i=0; i<n; i++){
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
 	
 	return 0;
 }
 //main ends here	
 	
 	
