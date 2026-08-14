#include <stdio.h>

int main(void)
{
	unsigned int b = 4294967295;
	printf("b : %u\n", b);

	b++;
	printf("b : %u\n", b);

	return 0;
}