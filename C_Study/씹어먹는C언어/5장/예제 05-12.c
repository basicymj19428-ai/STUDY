#include <stdio.h>

int main(void)
{
	int heihgt, weight;

	printf("당신의 키와 몸무게를 각각 입력해주세요 : ");
	scanf("%d%d", &heihgt, &weight);

	if (heihgt >= 190 || weight >= 100) {
		printf("당신은 거구 입니다.\n");
	}
	if (!(heihgt >= 190 || weight >= 100)) {
		printf("당신은 거구가 아닙니다.\n");
	}

	return 0;
}