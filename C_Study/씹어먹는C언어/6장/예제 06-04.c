#include <stdio.h>

int main(void)
{
	int subject, score;
	double sum_score = 0;

	printf("몇개의 과목 점수를 입력받을건가요 : ");
	scanf("%d", &subject);

	printf("\n각 과목의 점수를 입력해주세요\n");
	for (int i = 1; i <= subject; i++) {
		printf("과목%d : ", i);
		scanf("%d", &score);

		sum_score += score;
	}

	printf("전체 과목의 평균은 %.2lf\n", sum_score / subject);

	return 0;
}