#include <stdio.h>

int main(void)
{
	int i, sum = 0;
	for (int i = 0; i < 20; i++) {
		sum += i;
	}
	printf("i부터 19까지의 합 : %d\n", sum);

	return 0;
}