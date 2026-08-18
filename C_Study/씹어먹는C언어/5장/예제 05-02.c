#include <stdio.h>

int main(void)
{
	double i, j;
	printf("나누고 싶은 두 정수를 입력하세요 : ");
	scanf("%lf%lf", &i, &j);

	if (j == 0) {
		printf("0으로 나눌수 없습니다.\n");
		return 0;
	}

	printf("%f를 %f로 나눈 결과는 : %f\n", i, j, i / j);

	return 0;
}