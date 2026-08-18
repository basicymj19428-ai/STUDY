#include <stdio.h>

int main(void)
{
	int i, j;

	printf("크기를 비교할 두 수를 압력하시오 : ");
	scanf("%d%d", &i, &j);

	if (i > j) {
		printf("%d는 %d보다 큽니다.\n", i, j);
	}
	if (i < j) {
		printf("%d는 %d보다 작습니다.\n", i, j);
	}
	if (i >= j) {
		printf("%d는 %d보다 크거나 같습니다.\n", i, j);
	}
	if (i <= j) {
		printf("%d는 %d보다 작거나 같습니다.\n", i, j);
	}
	if (i == j) {
		printf("%d는 %d와(과) 같습니다.\n", i, j);
	}
	if (i != j) {
		printf("%d는 %d와(과) 같지 않습니다.\n", i, j);
	}

	return 0;
}