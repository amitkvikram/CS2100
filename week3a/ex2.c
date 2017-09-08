/*
  Problem Name:Ex2
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Data:08/09/2017
*/

#include<stdio.h>

//function to check if list is sorted in ascending oreder or not
int checkSorted(float *arr, int n){
	int i=0;
	for(i=0;i<n-1;i++){
		if(arr[i+1]-arr[i]<1e-6) return 0;		//returns 0 if list is not sorted
	}
	
	return 1;					//reutrns 1 if list is sorted
}
	

int main(){
	int n;               //length of input list
	printf("Length of list: ");
	scanf("%d", &n);
	
	float arr[n];
	int i;
	printf("List: ");
	for(i =0;i<n;i++){	//taking input
		scanf("%f", &arr[i]);
	}
	
	if(!checkSorted(arr, n)){
		printf("array not sorted");
		return 0;		
	}
	
	printf("Target Value: ");
	float val;       	//target value
	scanf("%f", &val);
	
	int low= 0, high = n, mid = 0, flag=0;
	
	while(low<high){
		mid =(low+high)/2;
		if(arr[mid]<val+1e-6 && arr[mid]>val-1e-6){
			flag=1;				//setting flag=1 if target value is found in list
			break;
		}
		
		else if(val-arr[mid]>1e-6) low= mid+1;	//setting low = mid+1, if target value is greater than arr[mid]
		else high = mid;			//setting high = mid, if target value is less than arr[mid]
	}
	
	if(flag==1){   					//if flag =1, target value is found in list
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
        
	
		
		
	
	
	
	
		
