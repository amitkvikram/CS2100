/*
  Problem Name:Ex4
  Programmers'Name: Amit Vikram Singh
  Roll No.:111601001
  Date:18/09/2017
  Time Complexity : O(row*log(col)) ,where O is big-O notation
*/
#include <stdio.h>

//Searching the element using binary search
void Search(int arr[][100], int row, int col, int target, int flag) {
      int found =0, index, i=0;           //found variable to check the status if element is found or not
      if(flag == 1){           //array's elements are in ascending order
            for(i=0; i<row; i++){
                  int low =0, high = col, mid =0;
                  while(low < high){
                        mid = (low + high) /2;
                        if(arr[i][mid] > target){
                              high = mid;
                        }
                        else if(arr[i][mid] < target){
                              low = mid+1;
                        }
                        else{
                              found =1;
                              index = mid;                  //storing the index where element was found
                              break;                         //If target element is found break out of the loop
                        }
                  }

                  if(found == 1) break;                      //If target element is found break out of the loop

            }
      }

      else{             //if arrays elements are in descending order
            for(i=0; i<row; i++){
                  int low =0, high = col, mid =0;
                  while(low < high){
                        mid = (low + high) /2;
                        if(arr[i][mid] < target){
                              high = mid;
                        }
                        else if(arr[i][mid] > target){
                              low = mid+1;
                        }
                        else{
                              found =1;
                              index = mid;                  //storing the index where element was found
                              break;                         //If target element is found break out of the loop
                        }
                  }
                  if(found == 1) break;         //If target element is found break out of the loop
            }
      }

      if(found == 0){         //Checking if element was not found in matrix
            printf("element not found in matrix");
            return;
      }

      else{
            printf("Element found in %d row %d column\n", i, index);
      }

}

//taking input from user
int take_input(int arr[][100], int row, int col){
      int i, j;
      int flag1= 0, flag2 =0;     //flag1 works as a flag for order of element in row, flag2 works as flag to check order of element in column
                                  //flag ==1 ==> ascending order, flag ==2 ==> desceding order
      for(i=0; i<row; i++){
            for(j =0; j<col; j++){
                  scanf("%d", &arr[i][j]);

                  //Checking order of element in row
                  if(j!=0){
                        // printf("flag1 = %d\n", flag1);
                        if(flag1 == 0){
                              if(arr[i][j] > arr[i][j-1]) {
                                    flag1 =1;         //updating flag1 to 1 because array is ascending
                                    flag2 =1;         //updating flag2 to 1 because array is ascending
                              }
                              else if(arr[i][j]< arr[i][j-1]) {
                                    flag1 =2;         //updating flag1 to 2 because array descending
                                    flag2 =2;         //updation flag2 to 2 because array is descending
                              }
                        }
                        else if(flag1 == 1){     //array is ascending
                              if(arr[i][j]< arr[i][j-1]){         //checking for wrong input
                                    flag1 =3;                     //updating flag1 = 3 because wrong input found
                              }
                        }

                        else{                   //array is descending
                              if(arr[i][j]> arr[i][j-1]){         //checking for wrong input
                                    flag1 =3;                     //updating flag1 = 3 because wrong input found
                              }
                        }
                  }

                  //Checking order of element in column
                  if(i!=0){
                        if(flag2 == 0){
                              if(arr[i][j] > arr[i-1][j]) {
                                    flag2 =1;         //updating flag2 to 1 because array is ascending
                                    flag1 =1;         //updating flag1 to 1 because array is ascending

                              }
                              else if(arr[i][j]< arr[i-1][j]) {
                                    flag2 =2;         //updation flag2 to 2 because array is descending
                                    flag1 =2;         //updation flag1 to 2 because array is descending
                              }
                        }
                        else if(flag2 == 1){     //array is ascending
                              if(arr[i][j]< arr[i-1][j]){
                                    flag2 =3;       //wrong input found
                              }
                        }

                        else{                 //array is descending
                              if(arr[i][j]> arr[i-1][j]){
                                    flag2 =3;         //wrong input found
                              }
                        }
                  }

                  if(flag2 == 3 || flag1 == 3) {            //Checking if any wrong input has been detected
                        printf("wrong input\n");
                        return 3;           //returns to main function if wrong input detected.
                  }
            }
      }

      if(flag1 == 1 || flag2 == 1) return 1;          //returning 1 if array is in ascending order;
      else return 2;                                  //returning 2 if array is in descending order;
}

//main begins here
int main() {
      int row, col;    //row is number of row in matrix and col in number of row in matrix
      printf("Enter number of rows: ");
      scanf("%d", &row);

      printf("Enter number of columns: ");
      scanf("%d", &col);
      int arr[100][100];           //two dimensional array to store elements of matrix

      int status = take_input(arr, row, col);   //calling take_input function to take input from user
      if(status == 3) return 0;
      else{
            int target;       //target is element to search
            printf("Enter element to search: ");
            scanf("%d",&target);
            Search(arr, row, col, target, status);    //status is to denote ascending or descending order
      }

      return 0;
}
//main ends here
