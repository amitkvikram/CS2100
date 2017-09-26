#include<stdio.h>

void toh(int n, int a, int c, int b){
	if(n==1){
		printf("move disk from 1 to 3\n");
		return;
	}
	
	toh(n-1, a, b, c);
   	printf("n Move disk %d from rod %d to rod %d\n", n, a, c);
    	toh(n-1, a, c, b);
    	
}
int main(){
	int n;
	printf("Enter number of disk: ");
	scanf("%d", &n);
	
	toh(n, 1, 2, 3);
	return 0;
}
