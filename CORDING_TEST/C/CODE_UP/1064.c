#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    int min;

    scanf("%d%d%d", &num1, &num2, &num3);

    min = (num1 > num2) ? num2 : num1;
    min = (min > num3) ? num3 : min;

    printf("%d\n", min);

    return 0;
}