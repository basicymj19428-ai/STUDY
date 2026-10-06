#include <stdio.h>

int max_number(int* parr);

int main(void)
{
	int arr[10];
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	printf("입력한 배열 중 가장 큰 수 : %d\n", max_number(arr));

	return 0;
}

int max_number(int* parr)
{
	int i;
	int max = parr[0];

	for (i = 1; i < 10; i++) {
		if (parr[i] > max) {
			max = parr[i];
		}
	}

	return max;
}