#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    int sum = 0;
    double mid = 0;

    scanf("%d%d%d", &num1, &num2, &num3);

    sum = num1 + num2 + num3;
    mid = sum/3.0;

    printf("%d\n", sum);
    printf("%.1lf\n", mid);

    return 0;
}