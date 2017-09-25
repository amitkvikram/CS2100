/*
  Problem Name:Ex3
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Date:12/09/2017
*/

#include<stdio.h>


void swap(int *a, int *b){
      int temp = *a;
      *a = *b;
      *b = temp;
}

int partition(int *arr, int p, int r){       //arr[r] is pivot
      int i = p;			
      for(int j=p; j<r; j++){
            if(arr[j]<=arr[r]){
                  swap(&arr[i], &arr[j]);
                  i++;
            }
      }

      swap(&arr[r], &arr[i]);   //calling swap function to adjust the position of pivot
      return i;
}


void quick_sort(int *arr, int p, int r){
      if(p<r){
            int q = partition(arr, p, r); //calling function partition to spli the array in 2 parts.elements in left part>arr[r]
                                          //whereas elments in right<arr[r]
            quick_sort(arr, p, q-1);      //calling quick_sort function to sort the subarray.
            quick_sort(arr, q+1, r);
      }
}

//main function begins here
int main(int argc, char const *argv[]) {

      printf("Enter length of array: ");
 	int n; 				//length of array
 	scanf("%d", &n);
 	int arr[n];			//array to store the elements
 	printf("Enter elements of array: ");
 	int i=0;
 	for(i=0; i<n; i++){
 		scanf("%d", &arr[i]);
 	}

      quick_sort(arr, 0, n-1);  //calling function quick_sort to sort the array

      printf("Sorted Array: ");
 	for(i=0; i<n; i++){
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
      return 0;
}

//main function ends here
