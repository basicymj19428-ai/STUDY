#include <stdio.h>

int main(void)
{
	int arr[6] = { 1, 2, 3, 4, 5 ,6 };
	int* parr = arr;

	printf("Sizeoff(arr) : %d\n", sizeof(arr));
	printf("Sizeof(parr) : %d\n", sizeof(parr));

	return 0;
}