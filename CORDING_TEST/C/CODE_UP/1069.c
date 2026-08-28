#include <stdio.h>

int main(void)
{
    char test;
    scanf("%c", &test);

    if(test == 'A') {
        printf("best!!!");
    }
    else if(test == 'B') {
        printf("good!!");
    }
    else if(test == 'C') {
        printf("run!");
    }
    else if(test == 'D') {
        printf("slowly~");
    }
    else {
        printf("what?");
    }

    return 0;
}