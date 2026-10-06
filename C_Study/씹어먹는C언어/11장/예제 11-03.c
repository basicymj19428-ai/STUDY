#include <stdio.h>

int ret()
{
	return 1000;
}

int main(void)
{
	int a = ret();
	printf("ret() 함수의 반환값 : %d\n", a);

	return 0;
}