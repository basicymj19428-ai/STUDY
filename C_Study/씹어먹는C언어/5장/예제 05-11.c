#include <stdio.h>

int main(void)
{
	int height, weight;
	
	printf("당신의 키와 몸무게를 각각 입력하시오 : ");
	scanf("%d%d", &height, &weight);

	if (height >= 190 || weight >= 100) {
		printf("당신은 거구입니다.\n");
	}

	return 0;
}