/*
    파일이름 : 예제 03-09.c
    작성자 : 홍길동
    작성일 : 2026년 11월 22일
    작성이유 : printf 함수의 기능 테스트
*/

#include <stdio.h>

int main(void)
{
    int val = 0;

    val = 1 + 2;  /*변수 선언 및 초기화*/

    printf("1 + 2 = %d\n", val);  /*덧셈 연산후 대입 연산*/

    val = 2 + 3;

    printf("2 + 3 = %d", val);  /*문자열 출력*/

    return 0;
}
