#include <stdio.h>

int main(void)
{
	int arr[5];
	int ave = 0;
	
	for (int i = 0; i < 5; i++) {
		printf("%d 번째 학생의 성적은?", i + 1);
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 5; i++) {
		ave += arr[i];
	}

	printf("전체 학생의 평균은 : %d\n", ave / 5);
	return 0;
}