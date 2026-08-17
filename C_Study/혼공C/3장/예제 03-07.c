#include <stdio.h>
#include <string.h>

int main(void)
{
    char fruit[20] = "strawberry";  //strawberry로 초기화

    printf("%s\n", fruit);  //strawberry 출력
    strcpy(fruit, "banana");  //fruit에 banana 복사
    printf("%s\n", fruit);  //banana 출력

    return 0;
}