#include <stdio.h>

int main(void)
{
	int input;

	printf("마이펫\n");
	printf("무엇을 하실것인지 입력하세요\n");
	printf("1. 밥주기\n");
	printf("2. 씻기기\n");
	printf("3. 재우기\n");

	scanf("%d", &input);

	switch (input) {
	case 1:
		printf("맛있다\n");
		break;

	case 2:
		printf("시원해\n");
		break;

	case 3:
		printf("zzz\n");
		break;

	default:
		printf("무슨 명령인지 모르겠다.\n");
		break;
	}

	return 0;
}