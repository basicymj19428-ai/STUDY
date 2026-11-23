//파일 이름 : 예제 03-10.c
//작성자 : 홍길동
//작성일 : 2025년 11월 24일
//작성 이유 : printf함수의 기능 테스트

#include <stdio.h>

int main(void)
{
    int val = 0;  //변수 선언 및 초기화
    val = 1 + 2;  //덧셈 연산 후에 대입연산 
    
    printf("1 + 2 = %d\n", val);

    val = 2 + 3;
    printf("2 + 3 = %d\n", val);  //문자열 출력

    return 0;
}