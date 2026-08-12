#include <stdio.h>	

int main(void)
{
	int a;
	a = 127;

	printf("a의 값은 %d진수로 %o입니다.\n", 8, a);
	printf("a의 값은 %d진수로 %d입니다.\n", 10, a);
	printf("a의 값은 %d진수로 %x입니다.\n", 16, a);

	return 0;
}