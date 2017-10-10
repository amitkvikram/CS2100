/*
 MID-SEM EXAMINATION
 Name: Amit Vikram Singh
 Roll No: 111601001
 IP Address: 10.64.1.193
 Set Number: A
 Problem No: 01
*/

#include<stdio.h>

//Calculating gcd of two given numbers
int gcd(int a, int b){
	if(b == 0) return a;
	gcd(b, a%b);
}

//Main begins here
int main(){
	int a, b;
	printf("Enter 2 positive numbers: ");
	scanf("%d%d", &a,&b);
	
	int num;	//num is the variable to store gcd of given numbers
	if(a>b) num = gcd(a, b);
	else num = gcd(b,a);
	
	printf("GCD of %d and %d is: %d\n", a, b, num);  //printing gcd of given numbers
	return 0;
}
//Main ends here	
