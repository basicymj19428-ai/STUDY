#include <stdio.h>

int main(void)
{
	int a = 1;
	printf("++a : %d\n", ++a);  //++a : 2

	a = 1;
	printf("a++ : %d\n", a++);  //a++ : 1
	printf("a : %d\n", a);  //a : 2

	return 0;
}