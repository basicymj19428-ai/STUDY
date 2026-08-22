#include <stdio.h>

int main(void)
{
    int age;  //나이는 정수형
    double height;  //키는 실수형

    printf("나이와 키를 입력하세요 : ");
    scanf("%d%lf", &age, &height);

    printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);

    return 0;
}