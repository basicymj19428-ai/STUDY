#include <stdio.h>

int main(void)
{
	int arr[10];
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	//for (i = 0; i <= 10; i++) {
	for (i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}