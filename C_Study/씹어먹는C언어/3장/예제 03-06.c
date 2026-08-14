#include <stdio.h>

int main(void)
{
	int a = 2147483647;  //int가 표현할수 있는 최댓값
	printf("a : %d\n", a);

	a++;
	printf("a : %d\n", a);  //오버플로우 발생

	return 0;
}