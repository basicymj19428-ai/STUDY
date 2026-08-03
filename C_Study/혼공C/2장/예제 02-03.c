#include <stdio.h>

int main(void)
{
    printf("Be happy\n");  //줄바꿈
    printf("12345678901234567890\n");  //줄바꿈
    printf("My\tfriend\n");  //탭문자, 줄바꿈
    printf("Goot\bd\tchance\n");  //한칸왼쪽이동, 탭문자, 줄바꿈
    printf("Cow\rw\a\n");  //맨앞으로 이동, 벨소리, 줄바꿈

    return 0;
}