/*
  Problem Name:Ex5
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Date:18/09/2017
*/

#include <stdio.h>

//FindRotate function returns index where element is found otherwise returns -1
int FindRotate(int *arr, int n, int target){
      int found =0;
      if(target== arr[0]){
            return 0;         //returning 0 if first element is target element
      }
      else if(target == arr[n-1]){
            return n-1;       //returning n-1 if last element is target element
      }

      else if(target > arr[0]){                 //if target element is greater than first element of array
            int low =0, high = n, mid =0;

            //Binary Search
            while(low<= high){
                  mid = (low+high)/2;
                  if(arr[mid] == target ){
                        found =mid;
                        break;                   //breaking loop if element was found
                  }

                  else if(arr[mid] < arr[0]){
                        high = mid -1;
                  }

                  else if(arr[mid] > target) high = mid-1;
                  else low = mid+1;
            }
      }

      else{                                     // if target elements is less than last element of array
            int low =0, high = n, mid =0;

            //Binary Search
            while(low<= high){
                  mid = (low+high)/2;
                  if(arr[mid] == target){
                        found = mid;
                        break;                   //breaking loop if element was found
                  }

                  else if(arr[mid] > arr[n-1]){
                        low = mid +1;
                  }

                  else if(arr[mid] < target) low = mid+1;
                  else high = mid -1;
            }
      }

      if(found >0){                 //checking if element was found
            return found;           //returning index where element was found
      }
      else return -1;               //if element was not found returning -1
}


int main(int argc, char const *argv[]) {
      int n;      //length of array
      printf("Enter length of array: ");
      scanf("%d",&n );

      int arr[n];                   //array to store the element
      printf("Enter Elements: ");
      for(int i=0;i<n; i++){
            scanf("%d",&arr[i]);
      }

      int target;
      printf("Enter element to search: ");
      scanf("%d",&target);

      int index = FindRotate(arr, n, target);         //calling FindRotate function to search the element.
      if(index !=-1) printf("index = %d\n", index);   //if element was found printitng its index
      else printf("Not Found");

      return 0;
}
