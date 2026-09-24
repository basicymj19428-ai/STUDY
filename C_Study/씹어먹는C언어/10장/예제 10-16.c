#include <stdio.h>

int main(void)
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	printf("3[arr] : %d\n", 3[arr]);
	printf("*(3 + a) : %d\n", *(arr + 3));

	return 0;
}