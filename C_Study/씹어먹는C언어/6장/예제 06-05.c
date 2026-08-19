#include <stdio.h>

int main(void)
{
	int usranswer;

	printf("컴퓨터가 생각한 숫자를 맞춰보시오\n");
	for (;;) {
		scanf("%d", &usranswer);
		if (usranswer == 3) {
			printf("정답입니다!\n");
			break;
		}
		else {
			printf("오답입니다.\n");
		}
	}

	return 0;
}