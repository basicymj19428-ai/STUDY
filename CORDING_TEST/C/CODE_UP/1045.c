#include <stdio.h>

int main(void)
{
    int num1, num2;
    double div = 0;
    scanf("%d%d", &num1, &num2);

    div = (double)num1 / (double)num2;

    printf("%d\n", num1 + num2);
    printf("%d\n", num1 - num2);   
    printf("%d\n", num1 * num2);
    printf("%d\n", num1 / num2);
    printf("%d\n", num1 % num2);
    printf("%.2lf\n", div);

    return 0;
}