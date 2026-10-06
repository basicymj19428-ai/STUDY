#include <stdio.h>

int return_func()
{
	printf("실행\n");
	return 0;
	printf("실행 불가\n");
}
int main(void)
{
	return_func();
	return 0;
}