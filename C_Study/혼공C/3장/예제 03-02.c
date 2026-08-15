#include <stdio.h>

int main(void)
{
    char ch1 = 'A';  //문자로 초기화
    char ch2 = 65;  //문자 A의 아스키 코드값에 해당하는 정수

    printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1);
    printf("아스키코드값이 %d인 문자 : %c\n", ch2, ch2);

    return 0;
}