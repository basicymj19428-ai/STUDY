#include <stdio.h>

int main(void)
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);

    if(num1 == 0 && num2 == 0) {
        printf("1");
    }
    else {
        printf("0");
    }

    return 0;
}