#include <stdio.h>

int main(void)
{
	int a;
	printf("아무숫자나 입력하세요 : ");
	scanf("%d", &a);

	if (a >= 10) {
		if (a < 20) {
			printf("%d는 10이상 20미만인 수입니다.\n", a);
		}
	}

	return 0;
}