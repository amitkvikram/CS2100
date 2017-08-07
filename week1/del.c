#include<stdio.h>

int main(){
	char *names[] = {"Miller","Jones","Anderson"};
	printf("%c\n",*(*(names+1)+2));
	printf("%c\n",names[1][2]);
	printf("%zu",sizeof(char*));
	int num=100;
	const int *p= &num;
	*p=200;
	return 0;

}
