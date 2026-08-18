#include <stdio.h>

int main(void)
{
	int num;

	printf("아무숫자나 입력하시오 : ");
	scanf("%d", &num);

	if (num == 7) {
		printf("행운의 숫자 7입니다.\n");
	}
	else {
		if (num == 4) {
			printf("죽음의 숫자 4입니다...\n");
		}
		else {
			printf("그냥 평범한 숫자 %d입니다.\n", num);
		}
	}

	return 0;
}