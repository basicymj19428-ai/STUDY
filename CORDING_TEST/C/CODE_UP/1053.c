#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    if(num == 0) {
        printf("1");
    }
    else if(num == 1) {
        printf("0");
    }

    return 0;
}