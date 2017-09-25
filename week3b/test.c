/*
  Problem Name:TEST
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Date:19/09/2017
*/

#include<stdio.h>
#include<string.h>

int compare(char str1[], char str2[]){
	char temp1[11];
	char temp2[11];
	
	strcpy(temp1, str1);
	strcpy(temp2, str2);
	
	if(str1[0] < 'a' || str1[0] > 'z'){
		temp1[0] = temp1[0] - 'A' +'a';
	}
	
	if(str2[0] < 'a' || str2[0] > 'z'){
		temp2[0] = temp2[0] - 'A' +'a';
	}
	
	return strcmp(temp1, temp2);
}

void Merge(char str[][11], int low, int mid, int high){
	int n1= mid-low+1;	  //n1 stores Length of left subarray
	int n2= high-mid;         //n2 stores Length of Right subarray
	char Left[n1][11], Right[n2][11];  //Left stores left half of subarray and Right stores right half of subarrays
	int i;
	
	//Copying left half and right half of subarrays in two separate arrays(string array)
	for(i=0;i<n1; i++){
		strcpy(Left[i], str[low+i]);
	}
	for(i=0; i<n2; i++){
		strcpy(Right[i], str[mid+i+1]);
	}
	
	i=0; 
	int j=0, k=low;
	
	//Merging Subarrays
	while(i<n1 && j<n2){
		if(compare(Left[i], Right[j]) < 0) {
			strcpy(str[k], Left[i]);		//Copying name into str
			i++;
		}
		else {
			strcpy(str[k], Right[j]);		//Copying name into str
			j++;
		}
		k++;
	}
	
	//copying remaining elements of Left and Right into str
	for(;i<n1;i++){
		strcpy(str[k], Left[i]);
		k++;
	}
	
	for(;j<n2; j++){
		strcpy(str[k], Right[j]);
		k++;
	}
	
}
	

void MergeSort(char str[][11], int low, int high){	//ptr is pointer to array, low is lower index of subarray , high is ending index of subarray
	if(low>=high) return;		//returns if number of element in subarray is 1;
	int mid= (low+high)/2;		//mid is middle index of array
	MergeSort(str, low, mid);	//calling MergeSort for left half of subarray
	MergeSort(str, mid+1, high);    //calling MergeSort for right half of subarray
	Merge(str, low, mid, high);	//Merging left and right half of subarray
}
	
//main begins here	
int main(){
	printf("Enter number of names: ");  
 	int n; 				//length of array
 	scanf("%d", &n);
 	char str[n][11];			//array to store the names
 	printf("Enter elements of array: ");
 	int i=0;
 	for(i=0; i<n; i++){
 		scanf("%s", str[i]);
 	}
 	MergeSort(str, 0, n-1);		//calling function MergeSort which sorts the array
 	printf("Sorted Array: ");
 	for(i=0; i<n; i++){
 		printf("%s\n", str[i]);   //printing elements
 	}
 	printf("\n");
 	
 	return 0;
 }
 //main ends here	
 	
 	
