#include <stdio.h>

int main(void)
{
	double ave_score;
	double mat, eng, sci, pro;

	printf("수학, 영어, 과학, 컴퓨터 프로그래밍 점수를 각각 입력하시오 : ");
	scanf("%lf%lf%lf%lf", &mat, &eng, &sci, &pro);

	ave_score = (mat + eng + sci + pro) / 4;

	printf("당신의 평균 점수는 %lf입니다.\n", ave_score);

	if (ave_score >= 90) {
		printf("당신은 우등생입니다.\n");
	}
	else if (ave_score >= 30) {
		printf("조금만 노력하세요.\n");
	}
	else {
		printf("공부를 발로 합니까?\n");
	}

	return 0;
}